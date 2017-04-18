// Last Update:2016-09-26 14:52:31
/**
 * @file long.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2016-09-26
 */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<setjmp.h>

//jmp_buf jmpbuffer;
//#define TOK_ADD 5
//#define MAXLINE 4096
//
//int get_token()
//{
//    return 5;
//}
//
//void cmd_add(void)
//{
//    int token;
//    token = get_token();
//    printf("calling cmd_add:token=%d\n",token);
//    if(token>0)
//        longjmp(jmpbuffer,1);
//    printf("%d\n", token);
//}
//
//void do_line(char*ptr)
//{
//    int cmd;
//    printf("calling do_line:%s\n",ptr);
//    while((cmd = get_token()) > 0)
//    {
//        printf("cmd=%d\n", cmd);
//        switch(cmd){
//        case TOK_ADD:
//            cmd_add();
//            break;
//        }
//    }
//}
//
//int main(void)
//{
//    char line[MAXLINE];
//    if(setjmp(jmpbuffer) != 0)
//        printf("error");
//    while(fgets(line, MAXLINE,stdin) != NULL)
//    {
//        printf("main loop\n");
//        do_line(line);
//    }
//    exit(0);
//}
static void f1(int,int,int,int);
static void f2(void);

static jmp_buf jmpbuffer;
static int globval;
int main(void)
{
    int autoval;
    register int regival;
    volatile int volaval;
    static int statval;
    globval=1, autoval=2 , regival=3, volaval=4, statval=5;
    if(setjmp(jmpbuffer) != 0)
    {
        printf("after longjmp:\n");
        printf("globval=%d, autoval=%d, regival=%d, volaval=%d, statval=%d\n",
            globval, autoval, regival, volaval, statval);
        exit(0);
    }
    globval=91, autoval=92 , regival=93, volaval=94, statval=95;
    f1(autoval, regival, volaval, statval);
}

static void f1(int i,int j, int k, int l)
{
    printf("in f1():\n");
    printf("globval=%d, autoval=%d, regival=%d, volaval=%d, statval=%d\n",
            globval, i, j, k, l);
    f2();
}

static void f2()
{
    longjmp(jmpbuffer, 1);
}
