#include<stdio.h>
 
int main()
{
    char c;
    printf("......Enter q to quit......\n");
    do
    {
        printf("Enter a character\n");
        //an extra “Enter a character” followed by an extra new line. 
        //This happens because every scanf() leaves a newline character 
        //in buffer that is read by next scanf.
        //1. We can make scanf() to read a new line by using an extra “\n”,
        //i.e., scanf(“%d\n”, &x), this work does not as expected:
        //Enter a character
        //a
        //b
        //a
        //Enter a character
        //c
        //b
        //Enter a character
        //d
        //c
        //Enter a character
        //2. We can add a getchar() after scanf() to read an extra newline. 
        //this could work as expected, but except you enter two successor newlines
        scanf("%c", &c);
        getchar();
        printf("%c\n", c);
    }
    while (c != 'q');
    return 0;
}
