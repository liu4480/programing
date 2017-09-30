// Last Update:2016-09-26 15:46:48
/**
 * @file ids.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2016-09-26
 */

#include<stdio.h>
#include<unistd.h>
int main(void)
{
    printf("pid=%d,ppid=%d,uid=%d,euid=%d,gid=%d,egid=%d\n",
           getpid(),getppid(),getuid(),geteuid(),getgid(),getegid());
    return 0;
}
