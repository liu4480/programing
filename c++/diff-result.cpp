#include<stdio.h>

//http://www.geeksforgeeks.org/g-fact-54/ says gcc and g++ have different result
int main()
{
    //both gcc and g++ print 1
    printf("sizeof('a')=%d\n", sizeof('a'));

    //both gcc and g++ print 8
    struct T{double x;};
    printf("sizeof(T)=%d\n", sizeof(T));

    //both print 1
    printf("sizeof(1==1)=%d\n", sizeof(1==1));

    printf("sizeof('V') = %d sizeof(char) = %d\n", sizeof('V'), sizeof(char));
    return 0;
}
