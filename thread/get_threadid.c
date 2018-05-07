// Last Update:2018-03-29 15:25:01
/**
 * @file get_threadid.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-29
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

pthread_t ntid;

void printids(const char *s)
{
    pid_t pid;
    pthread_t tid;

    pid = getpid();
    tid = pthread_self();
    printf("%s pid %u tid %u (0x%x)", s, (unsigned int)pid, (unsigned int)tid, (unsigned int)tid);
}

void * thr_fn(void * arg)
{
    printids("New thread:");
    return ((void*)0);
}

int main(void)
{
    int err;
    err = pthread_create(&ntid, NULL, thr_fn, NULL);
    if (err != 0){
        fprintf(stderr, "can not create thread %s.\n", strerror(err));
        exit(err);
    }
    printids("main thread:");
    sleep(1);
    return 0;
}
