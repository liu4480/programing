// Last Update:2018-04-02 14:06:01
/**
 * @file threadpool.h
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-04-02
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <assert.h>

#ifndef THREADPOOL_H
#define THREADPOOL_H

struct task {
    void* (*cb_fn)(void *);
    void * arg;
    struct task * next;
};

struct threadpool {
    int thread_num;      //the thread numbe
    int queue_curr_num; //current number of tasks in queue
    int queue_max_num;  //max number of tasks in queue
    pthread_t * pthreads;//list of threads

    pthread_mutex_t mutex; //the mutext
    pthread_cond_t queue_empty;
    pthread_cond_t queue_not_empty;
    pthread_cond_t queue_not_full;

    int queue_close;
    int pool_close;
    struct task * head;
    struct task * tail;
};

void * threadpool_func(void* arg);
struct threadpool* threadpool_init(int thread_num, int queue_max_num)
{
    struct threadpool * pool = malloc(sizeof(struct threadpool));
    if (pool == NULL){
        fprintf(stderr, "failed to malloc threadpool.\n");
        return NULL;
    }
    //init the flags
    pool->thread_num = thread_num;
    pool->queue_max_num = queue_max_num;
    pool->queue_curr_num = 0;
    pool->queue_close = 0;
    pool->pool_close = 0;

    //init head and tail
    pool->head = NULL;
    pool->tail = NULL;

    //init the mutex
    int rc = pthread_mutex_init(&(pool->mutex), NULL);
    if (rc) {
        fprintf(stderr, "failed to init mutex.\n");
        return NULL;
    }

    rc = pthread_cond_init(&(pool->queue_empty), NULL);
    if (rc) {
        fprintf(stderr, "failed to init cond: pool->queue_empty.\n");
        return NULL;
    }

    rc = pthread_cond_init(&(pool->queue_not_empty), NULL);
    if (rc) {
        fprintf(stderr, "failed to init cond: pool->queue_not_empty.\n");
        return NULL;
    }

    rc = pthread_cond_init(&(pool->queue_not_full), NULL);
    if (rc) {
        fprintf(stderr, "failed to init cond: pool->queue_not_full.\n");
        return NULL;
    }

    pool->pthreads = malloc(thread_num * sizeof(pthread_t));
    if (pool->pthreads == NULL) {
        fprintf(stderr, "failed to malloc thread list: pool->pthreads.\n");
        return NULL;
    }
    int i;
    for(i = 0; i < thread_num; i++)
        pthread_create(&(pool->pthreads[i]), NULL, threadpool_func, (void*)pool);

    return pool;
}

int threadpool_add_task(struct threadpool* pool, void* (*cb_fn)(void *arg), void *arg)
{
    assert(pool != NULL);
    assert(cb_fn != NULL);
    assert(arg != NULL);
    //1. compare queue_curr_num and queue_max_num, if greater or equal to, wait
    pthread_mutex_lock(&(pool->mutex));
    if ((pool->queue_curr_num == pool->queue_max_num) && !(pool->pool_close || pool->queue_close))
        pthread_cond_wait(&pool->queue_not_full, &pool->mutex);

    //2. if queue_close OR pool_close, then return -1
    if (pool->pool_close || pool->queue_close) {
        pthread_mutex_unlock(&(pool->mutex));
        return  -1;
    }
    //3. add cb_fn to the task pool
    struct task * ptask = malloc(sizeof(struct task));
    if(ptask == NULL) {
        pthread_mutex_unlock(&(pool->mutex));
        return -1;
    }
    ptask->cb_fn = cb_fn;
    ptask->arg = arg;
    ptask->next = NULL;
    if (pool->head == NULL) {
        pool->head = pool->tail = ptask;
        pthread_cond_broadcast(&(pool->queue_not_empty));
    } else {
        pool->tail->next = ptask;
        pool->tail = ptask;
    }
    //4. update queue_curr_num
    pool->queue_curr_num++;
    pthread_mutex_unlock(&(pool->mutex));
    return 0;
}

int threadpool_destroy(struct threadpool* pool)
{
    //1. if pool_close or queue_close, then return
    assert(pool != NULL);
    pthread_mutex_lock(&(pool->mutex));
    if (pool->pool_close || pool->queue_close) {
        pthread_mutex_unlock(&(pool->mutex));
        return -1;
    }

    //2. set queue_close to 1
    pool->queue_close = 1;
    //3. wait for queue_empty
    while (pool->queue_curr_num != 0){
        pthread_cond_wait(&(pool->queue_empty), &(pool->mutex));
    }
    //4. set pool_close
    pool->pool_close = 1;
    pthread_mutex_unlock(&(pool->mutex));
    //5. broadcast queue_not_empty for the blocking threads
    //6. broadcast queue_not_full for threadpool_add_task
    pthread_cond_broadcast(&(pool->queue_not_empty));
    pthread_cond_broadcast(&(pool->queue_not_full));
    //7. wait for all threads to exit
    int i;
    for (i = 0; i < pool->thread_num; i++)
        pthread_join(pool->pthreads[i], NULL);
    //8. cleanup
    pthread_mutex_destroy(&(pool->mutex));
    pthread_cond_destroy(&(pool->queue_empty));
    pthread_cond_destroy(&(pool->queue_not_empty));
    pthread_cond_destroy(&(pool->queue_not_full));
    free(pool->pthreads);
    struct task *p;
    while(pool->head != NULL) {
        p = pool->head;
        pool->head = p->next;
        free(p);
    }
    free(pool);
    return 0;
}

void * threadpool_func(void* arg)
{
    struct threadpool *pool = (struct threadpool*)arg;
    struct task * ptask = NULL;
    //1. while(1)
    while(1) {
        //2. if queue is empty, wait
        pthread_mutex_lock(&(pool->mutex));
        while ((pool->queue_curr_num == 0) && !(pool->pool_close)) {
            pthread_cond_wait(&(pool->queue_not_empty), &(pool->mutex));
        }
        //3. if pool_close is set, return
        if (pool->pool_close) {
            pthread_mutex_unlock(&(pool->mutex));
            pthread_exit(NULL);
        }
        //4. reduce queue_curr_num, and fetch a task from head
        pool->queue_curr_num--;
        ptask = pool->head;
        if (pool->queue_curr_num == 0) {
            pool->head = pool->tail = NULL;
        } else {
            pool->head = ptask->next;
        }
        //5. if queue is empty, tell threadpool_destroy
        if (pool->queue_curr_num == 0) {
            pthread_cond_signal(&(pool->queue_empty));
        }
        //6. tell threadpool_add_task that it can add a new task
        if (pool->queue_curr_num == pool->queue_max_num - 1) {
            pthread_cond_broadcast(&(pool->queue_not_full));
        }
        pthread_mutex_unlock(&(pool->mutex));
        //7. execute the task
        (*(ptask->cb_fn))(ptask->arg);
        free(ptask);
    }
}
#endif  /*THREADPOOL_H*/
