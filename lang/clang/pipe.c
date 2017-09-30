//#include <stdio.h>  
//#include <stdlib.h>  
//#include <unistd.h>  
//#include <string.h>  
//#include <errno.h>  
//#include <sys/types.h>  
//#include <sys/wait.h>  
//#define BUFFER 255  
//  
//int main(int argc, char **argv) {  
//    char buffer[BUFFER + 1];  
//    int fd[2];  
//    if (argc != 2) {  
//        fprintf(stderr, "Usage：%s string\n\a", argv[0]);  
//        exit(1);  
//    }  
//    if (pipe(fd) != 0) {  
//        fprintf(stderr, "Pipe Error：%s\n\a", strerror(errno));  
//        exit(1);  
//    }  
//    if (fork() > 0) {  
//        close(fd[0]);  
//        printf("Parent[%d] Write to pipe\n\a", getpid());  
//        snprintf(buffer, BUFFER, "%s", argv[1]);  
//        write(fd[1], buffer, strlen(buffer));  
//        printf("Parent[%d] Quit\n\a", getpid());  
//        exit(0);  
//    } else {  
//        close(fd[1]);  
//        printf("Child[%d] Read from pipe\n\a", getpid());  
//        memset(buffer, '\0', BUFFER + 1);  
//        read(fd[0], buffer, BUFFER);  
//        printf("Child[%d] Read：%s\n", getpid(), buffer);  
//        exit(1);  
//    }  
//}  
//
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>

#define MAXLINE 4096

void err_sys(char*msg)
{
    fprintf(stderr, "%s\n", msg);
    fprintf(stderr, "%d:%s", errno, strerror(errno));
    exit(-1);
}

int main(void)
{
    int n;
    int fd[2];
    pid_t pid;
    char line[MAXLINE];

    if(pipe(fd) != 0)
        err_sys("pipe error");
    if((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid>0){
        close(fd[0]);
        n = write(fd[1], "hello world\n", 12);
        //printf("parent(%d) wrote %d bytes: %s", getpid(), n, "hello world\n");
        exit(0);
    } else {
        close(fd[1]);
        n = read(fd[0], line, MAXLINE);
        //printf("child(%d) read %d bytes: %s", getpid(), n, "hello world\n");
        write(STDOUT_FILENO, line, n);
        exit(0);
    }
}
