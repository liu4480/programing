// Last Update:2017-04-20 17:10:13
/**
 * @file test.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2017-04-20
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/prctl.h>

extern char **environ;

int changeNameByArgv(int argc, char*argv[], const char * new_name)
{
    /*
     * this will change the name in cmdline
     * not name in /proc/${PID}/status
     */
    memcpy(argv[0], new_name, 16);
    return 0;
}

int changeNameByPrctl(const char * new_name)
{
    /*
     * this only change /proc/${PID}/status, 
     * not the name in cmdline
     */
    printf("%s", new_name);
    prctl(PR_SET_NAME, new_name);
    return 0;
}

int main(int argc, char * argv[])
{
    getchar();
    changeNameByArgv(argc, argv, "changeName1");
    changeNameByPrctl("changeName1");
    getchar();
    
    return 0;
}
