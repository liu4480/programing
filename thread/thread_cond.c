// Last Update:2018-03-29 17:29:39
/**
 * @file thread_cond.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-29
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#define TRY 5
pthread_cond_t qready_one = PTHREAD_COND_INITIALIZER;
pthread_cond_t qready_two = PTHREAD_COND_INITIALIZER;
pthread_mutex_t qlock = PTHREAD_MUTEX_INITIALIZER;
int write_one=1;

void *thr_fn1(void* arg)
{
    int i = 0;
    while(i<TRY)
    {
        pthread_mutex_lock(&qlock);
        while(write_one == 0)
            pthread_cond_wait(&qready_one, &qlock);
        printf("in thread1:\t");
        printf("1\n");
        write_one = 0;
        pthread_mutex_unlock(&qlock);
        pthread_cond_signal(&qready_two);
        i++;
    };
}

void *thr_fn2(void*arg)
{
    int i = 0;
    while(i<TRY)
    {
        pthread_mutex_lock(&qlock);
        while(write_one == 1)
            pthread_cond_wait(&qready_two, &qlock);
        printf("in thread2:\t");
        printf("2\n");
        write_one = 1;
        pthread_mutex_unlock(&qlock);
        pthread_cond_signal(&qready_one);
        i++;
    };
}

int main()
{
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, thr_fn1, NULL);
    pthread_create(&tid2, NULL, thr_fn2, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    return 0;
}
