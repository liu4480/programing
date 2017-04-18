// Last Update:2016-09-26 13:27:57
/**
 * @file exit.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2016-09-26
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

char ** environ;
int main()
{
    int i = 0;
    if(environ == NULL)
        exit(-1);
    while(environ[i])
    {
        printf("%s\n", environ[i]);
        i++;
    }
    exit(0);
    //_Exit(0);
    //_exit(0);
}
