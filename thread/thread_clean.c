// Last Update:2018-03-29 15:35:31
/**
 * @file get_threadstatus.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-29
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void cleanup(void * arg)
{
    printf("cleanip: %s\n", (char*)arg);
}

void * thr_fn1(void * arg)
{
    printf("thread 1 start\n");
    pthread_cleanup_push(cleanup, "thread1 1st handler");
    pthread_cleanup_push(cleanup, "thread1 2nd handler");
    printf("thread 1 push complete\n");
    if (arg)
        return ((void*)1);
    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);
    return ((void*)1);
}

void * thr_fn2(void * arg)
{
    printf("thread 2 start\n");
    pthread_cleanup_push(cleanup, "thread2 1st handler");
    pthread_cleanup_push(cleanup, "thread2 2nd handler");
    printf("thread 2 push complete\n");
    if (arg)
    {
        printf("Hi\n");
        return ((void*)2);
    }
    printf("Hiihihihi\n");
    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);
    return ((void*)2);
}

int main(void)
{
    int err;
    pthread_t tid1, tid2;
    void * tret;

    err = pthread_create(&tid1, NULL, thr_fn1, (void*)1);
    if (err)
    {
        fprintf(stderr, "can not create thread1 %s\n", strerror(err));
        exit(err);
    }
    err = pthread_create(&tid2, NULL, thr_fn2, NULL);
    if (err)
    {
        fprintf(stderr, "can not create thread2 %s\n", strerror(err));
        exit(err);
    }

    err = pthread_join(tid1, &tret);
    if (err)
    {
        fprintf(stderr, "can join with thread1 %s\n", strerror(err));
        exit(err);
    }
    printf("thread1 exit code %d\n", (int)tret);
    err = pthread_join(tid2, &tret);
    if (err)
    {
        fprintf(stderr, "can join with thread2 %s\n", strerror(err));
        exit(err);
    }
    printf("thread2 exit code %d\n", (int)tret);
    return 0;
}

