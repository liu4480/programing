#include <stdio.h>

int main()
{
    int var = 10;

    int * ptr = &var;

    printf("Value of var = %d\n", *ptr);

    printf("Address of var = %p\n", ptr);

    *ptr = 20;

    printf("After doing *ptr = 20, *ptr is %d\n", *ptr);

    return 0;
}
