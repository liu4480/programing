// Last Update:2016-09-26 15:16:00
/**
 * @file rlimit.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2016-09-26
 */
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<sys/resource.h>

#define FMT "%10ld    "

#define doit(name) pr_limits(#name, name)

static void pr_limits(char* name, int resource)
{
    struct rlimit limit;

    if(getrlimit(resource, &limit))
    {
        fprintf(stderr, "getrlimit error for %s", name);
        exit(-1);
    }
    printf("name=%s\t", name);
    if(limit.rlim_cur == RLIM_INFINITY)
        printf("(infinite)  ");
    else
        printf(FMT, limit.rlim_cur);
    if (limit.rlim_max == RLIM_INFINITY)
        printf("(infinite)");
    else
        printf(FMT, limit.rlim_max);
    putchar((int)'\n');
}

int main(void)
{
    doit(RLIMIT_AS);
    doit(RLIMIT_CORE);
    doit(RLIMIT_CPU);
    doit(RLIMIT_DATA);
    doit(RLIMIT_FSIZE);
    doit(RLIMIT_LOCKS);
    doit(RLIMIT_MEMLOCK);
    doit(RLIMIT_NOFILE);
    doit(RLIMIT_NPROC);
    doit(RLIMIT_RSS);
    doit(RLIMIT_STACK);
    doit(RLIMIT_OFILE);
    doit(RLIMIT_SIGPENDING);
    doit(RLIMIT_MSGQUEUE);
    doit(RLIMIT_NICE);
    doit(RLIMIT_RTPRIO);
    doit(RLIMIT_RTTIME);
}
