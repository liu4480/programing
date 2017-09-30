#include <iostream>
#include <bits/stdc++.h>
#include <string.h>

using namespace std;

void swap(char &a, char &b)
{
    char tmp = a;
    a = b;
    b = tmp;
}

void reverseStr(string &str)
{
    int n = str.length();

    for (int i = 0; i < n/2; i++)
        swap(str[i], str[n-i-1]);
}

void * reverse(char* str)
{
    int i, len;
    len = strlen(str);

    for(i = len; i>=0; i--)
        printf("%c", str[i]);
    printf("\n");
}

char * reverseConstString(const char * str)
{
    int start, end, len;
    char tmp, *ptr = NULL;

    len = strlen(str);

    ptr = new char[len];

    strcpy(ptr, str);
    for(start = 0, end = len - 1; start <= end; start++, end--)
    {
        swap(ptr[start], ptr[end]);
    }
    return ptr;
}

int main()
{
    string str = "geeksforgeeks";
    reverseStr(str);
    cout << str << endl;
    str = "geeksforgeeks";
    reverse(str.begin(), str.end());
    cout << str << endl;
    char a[] = "geeksforgeeks";
    reverse(a);
    const char *s = "GeeksforGeeks";
    char * tmp = reverseConstString(s);
    cout << tmp << endl;
    delete tmp;
    return 0;
}
