#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
int main()
{
    char * b;
    char * a = malloc(10);
    memset(a,0,10);
    memcpy(a,"/dev/sda", 10);
    printf("%x, %x", &(a[-1]), &(a[0]));
    return 0;
}
