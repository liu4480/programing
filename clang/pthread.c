// Last Update:2016-09-28 14:06:56
/**
 * @file pthread.c
 * @brief 
 *
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2016-09-28
 */
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_t ntid;

void printids(const char *s)
{
    pid_t pid = getpid();
    pthread_t tid = pthread_self();
    printf("%s pid %u tid %u (x0%x)\n", s, (unsigned int)pid, (unsigned int)tid, (unsigned int)tid);
}

void* thr_fn(void * arg)
{
    printids("new thread:");
    return;
}

//int main(void)
//{
//    int err = pthread_create(&ntid, NULL, thr_fn, NULL);
//    printids("main thread:");
//    sleep(1);
//    exit(0);
//}

//void * thr_fn1(void *arg)
//{
//    printf("thread 1 returning\n");
//    return;
//}
//
//void * thr_fn2(void* arg)
//{
//    printf("thread 2 returning\n");
//    return;
//}
//
//void err_quit(char* fmt, char* msg)
//{
//    fprintf(stderr, fmt, msg);
//    exit(-1);
//}
//
//int main(void)
//{
//    int err;
//    pthread_t tid1, tid2;
//    void *tret;
//    err = pthread_create(&tid1, NULL, thr_fn1, NULL);
//    if (err)
//        err_quit("can not create thread 1: %s\n", strerror(err));
//    err = pthread_create(&tid2, NULL, thr_fn2, NULL);
//    if (err)
//        err_quit("can not create thread 2: %s\n", strerror(err));
//    err = pthread_join(&tid1, &tret);
//    if (err)
//        err_quit("can not join thread 1: %s\n", strerror(err));
//    printf("thread 1 exit code %d", *(int*)(tret));
//    err = pthread_join(&tid2, &tret);
//    if (err)
//        err_quit("can not join thread 2: %s\n", strerror(err));
//    printf("thread 2 exit code %d", *(int*)(tret));
//}
struct foo{
    int a,b,c,d;
};

void printfoo(const char*s, const struct foo * fp)
{
    printf(s);
    printf("    structure at 0x%x\n", (unsigned)fp);
    printf("    foo.a = %d\n", fp->a);
    printf("    foo.b = %d\n", fp->b);
    printf("    foo.c = %d\n", fp->c);
    printf("    foo.d = %d\n", fp->d);
}

void* thr_fn1(void * arg)
{
    struct foo foo= {1,2,3,4};
    printfoo("thread 1:\n", &foo);
    pthread_exit((void*)&foo);
}

void* thr_fn2(void * arg)
{
    printf("thread 2: ID is %d\n", pthread_self);
    pthread_exit((void*)0);
}

int main(void)
{
    int err;
    pthread_t tid1, tid2;
    struct foo * fp;
    err = pthread_create(&tid1, NULL, thr_fn1, NULL);
    if (err)
    {
        fprintf(stderr, " can not create thread 1:%s", strerror(err));
        exit(-1);
    }
    err = pthread_join(tid1, (void*)&fp);
    if (err)
    {
        fprintf(stderr, " can not join with thread 1:%s", strerror(err));
        exit(-1);
    }
    err = pthread_create(&tid2, NULL, thr_fn2, NULL);
    if (err)
    {
        fprintf(stderr, " can not create thread 2:%s", strerror(err));
        exit(-1);
    }
    sleep(1);
    printfoo("parent:\n", fp);
    exit(0);
}
