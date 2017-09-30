#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fact(int n)
{
    if (n < 2)
        return 1;
    else 
        return n*fact(n-1);
}

char * reverse(char * s)
{
    register char t, *p = s, *q = (s + (strlen(s)-1));
    while(p < q)
    {
        t = *p;
        *p++ = *q;
        *q-- = t;
    }
    return s;
}

int main()
{
    char s[BUFSIZ];
    printf("4!==%d\n", fact(4));
    printf("8!==%d\n", fact(8));
    printf("12!==%d\n", fact(12));
    strcpy(s, "abcdef");
    printf("reversing 'abcdef', we get '%s'\n", reverse(s));
    strcpy(s, "madam");
    printf("reversing 'madam', we get '%s'\n", reverse(s));
    return 0;
}
