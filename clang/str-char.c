#include<stdio.h>
int main()
{
    char str[80], ch;
     
    // Scan input from user -GeeksforGeeks for example
    scanf("%s", str);
     
    // ch can be flushed(swiped) without this line
    // reads the buffer characters till the end and discards them(including newline) 
    // and using it after the “scanf()” statement clears the input buffer 
    // and allows the input in the desired container. 
    while((getchar())!='\n');
    // Scan character from user- 'a' for example
    ch = getchar();
     
    // Printing character array, prints “GeeksforGeeks”)
    printf("%s\n", str);
     
    // This does not print character 'a'
    printf("%c\n", ch);
     
    return 0;
}
