#include<stdio.h>

int main()
{
    int a = 10;
    //push addr to stack from right to left, prefix '++'/'--' will push addr
    //of a, while postfix '++'/'--' will think b=a++, and push b to stack
    printf("\n %d %d", a, a++); 
    a = 10;
    printf("\n %d %d", a++, a);
    a = 10;
    printf("\n %d %d %d ", a, a++, ++a);
    a = 10;
    printf("\n %d %d %d ", a, ++a, a++);
    a = 10;
    printf("\n %d %d %d ", a, a++, --a);
    return 0;
}
