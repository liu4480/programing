// Last Update:2016-09-30 12:48:57
/**
 * @file pipe2.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2016-09-30
 */

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>

#define DEF_PAGER "/usr/bin/more"
#define MAXLINE 4096

void err_sys(char * msg)
{
    fprintf(stderr, "%d:%s, %s\n", errno, strerror(errno), msg);
    exit(-1);
}

void err_quit(char * msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(-2);
}

int main(int argc, char* argv[])
{
    int n;
    int fd[2];
    pid_t pid;
    char * pager, *argv0;
    char line[MAXLINE];
    FILE *fp;

    if (argc != 2)
        err_quit("usage: a.out <pathname>");

    if((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "%d:%s, can not open %s", errno, strerror(errno), argv[1]);
        exit(-1);
    }
    if(pipe(fd) != 0)
        err_sys("pipe error");

    if((pid = fork()) < 0)
        err_sys("fork error");
    else if(pid > 0) {
        close(fd[0]);
        while(fgets(line, MAXLINE, fp) != NULL) {
            n = strlen(line);
        //    printf("%s", line);
            if(write(fd[1], line, n) != n)
                err_sys("write error to pipe");
        }
        if(ferror(fp))
            err_sys("fgets error");
        close(fd[1]);
        if(waitpid(pid, NULL, 0) < 0)
            err_sys("waitpit error");
        exit(0);
    } else {
        close(fd[1]);
        if(fd[0] != STDIN_FILENO) {
            if(dup2(fd[0], STDIN_FILENO) != STDIN_FILENO)
                err_sys("dup2 error");
            close(fd[0]);
        }
        if((pager = getenv("PAGER")) == NULL)
            pager = DEF_PAGER;
        //if((argv0 = strrchr(pager, "/")) != NULL)
        //    argv0++;
        printf("%s %s\n", pager, argv0);
        if(execl(pager, argv0, (char*)0) < 0)
        {
            fprintf(stderr, "%d:%s,execl error for %s", errno, strerror(errno), pager);
            exit(-1);
        }
        exit(0);
    }
}
