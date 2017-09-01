#include<stdio.h>

int fact(int n)
{
    if(n == 0 || n == 1)
        return 1;
    return fact(n - 1) * n;
}

int main()
{
    printf("fact(6)=%d\n", fact(6));
    return 0;
}
