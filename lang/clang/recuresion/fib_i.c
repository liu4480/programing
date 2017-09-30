#include <stdio.h>
int count = 0;
int count2 = 0;

int fib_i(int a, int b, int n)
{
    count++;
    if(n == 0)
        return b;
    return fib_i(a+b, a, n-1);
}

int fib(int n)
{
    count2++;
    if(n == 1|| n ==2)
        return 1;
    else if(n > 2)
        return fib(n-1) + fib(n-2);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("called func fib_i: %d time(s),\tfib(%d)=%d\n", count, n, fib_i(1, 0, n));
    printf("called func fib  : %d time(s),\tfib(%d)=%d\n", count2, n, fib(n));
    return 0;
}
