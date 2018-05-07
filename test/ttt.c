#include <stdio.h>

/* Apply the constructor attribute to myStartupFun() 
   so that it is executed before main() */
void myStartupFun(void) __attribute__((constructor));

/* implementation of myStartupFun */
void myStartupFun(void)
{
    printf("GeeksforGeeks");
}

int main()
{
}
