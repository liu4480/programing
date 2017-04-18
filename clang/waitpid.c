// Last Update:2016-09-26 16:31:48
/**
 * @file waitpid.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2016-09-26
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

void err_sys(char*msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(-1);
}

int main(void)
{
    pid_t pid;
    if((pid=fork()) < 0){
        err_sys("fork error");
    } else if(pid == 0) {
        if((pid = fork()) < 0)
            err_sys("fork error");
        else if(pid>0)
        {
            //if (waitpid(pid, NULL, 0) != pid)
            //    err_sys("waitpid error");
            printf("first child(%d) exited, parent=%d\n", getpid(),getppid());
            exit(0);
        }
        sleep(2);
        printf("second child(%d), parent=%d\n", getpid(), getppid());
        exit(0);
    }
    //if(waitpid(pid, NULL, 0) != pid)
    //    err_sys("waitpid error");
    /*int res = 0;
    if((res=waitid(P_PID, pid, NULL, WSTOPPED)) == -1)
    {
        fprintf(stderr, "waitid returned %d\n",res);
        err_sys("waitid error");
    }*/
    if(wait4(pid, NULL, 0, NULL) != pid)
        err_sys("wait4 error");
    printf("parent(%d) exited.\n", getpid());
    exit(0);
}
