#include <stdio.h>
#include <stdlib.h>
//gcc -o libpyvsll.do -shared -fPIC pycall.c
int add(int a, int b)
{
    printf("you entered %d and %d.\n", a, b);
    return a + b;
}
