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

struct foo {
    int a,b,c,d;
};

void * thr_fn1(void * arg)
{
    printf("thread 1 returning\n");
    return ((void*)1);
}

void * thr_fn2(void * arg)
{
    printf("thread 2 returning\n");
    return ((void*)2);
}

void err_quit(char * fmt, const char * str, int err)
{
    fprintf(stderr, fmt, str);
    exit(err);
}

void printfoo(const char *s, const struct foo* fp)
{
    printf(s);
    printf(" structure at 0x%x\n", (unsigned)fp);
    printf(" foo.a = %d\n", fp->a);
    printf(" foo.b = %d\n", fp->b);
    printf(" foo.c = %d\n", fp->c);
    printf(" foo.d = %d\n", fp->d);
}

void* thr_fn1_1(void * arg)
{
    struct foo f_o = {1,2,3,4};
    printfoo("thread 1_1:\n", &f_o);
    pthread_exit((void*)&f_o);
}
void* thr_fn2_2(void * arg)
{
    printf("thread 2_2: ID is %u\n", pthread_self());
    pthread_exit((void*)2);
}
int main(void)
{
    int err;
    pthread_t tid1, tid2;
    struct foo *tret;

    err = pthread_create(&tid1, NULL, thr_fn1_1, NULL);
    if (err)
        err_quit("can not create thread1_1, %s\n", strerror(err), err);
    err = pthread_create(&tid2, NULL, thr_fn2_2, NULL);
    if (err)
        err_quit("can not create thread2_2, %s\n", strerror(err), err);

    err = pthread_join(tid1, (void*)tret);
    if (err)
        err_quit("can not join thread1_1, %s\n", strerror(err), err);
    printfoo("thread 1 exit code \n", tret);
    err = pthread_join(tid2, (void*)tret);
    if (err)
        err_quit("can not join thread2_2, %s\n", strerror(err), err);
    printf("thread 2 exit code %d\n", *((int*)tret));
    exit(0);
}
