// Last Update:2018-02-27 12:55:58
/**
 * @file given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-02-27
 */
#include <string.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <unistd.h>
using namespace std;


int myCompare(char* str1, char* str2)
{
    int len = strlen(str1) + strlen(str2);
    char* tmp1 = new char [len+1];
    char* tmp2 = new char [len+1];
    memset(tmp1, 0, len + 1);
    memset(tmp2, 0, len + 1);
    strncpy(tmp1, str1, strlen(str1));
    strncpy(tmp1 + strlen(str1), str2, strlen(str2));
    strncpy(tmp2, str2, strlen(str2));
    strncpy(tmp2 + strlen(str2), str1, strlen(str1));
    return strncmp(tmp1, tmp2, len + 1);
}

void printLargest(char * arr[], int n)
{
    sort(arr, arr + n, myCompare);
    for(int i = 0; i < n; i++)
        cout << arr[i];
    cout << endl;
}

int main()
{
    char * arr[] = {"54", "546", "548", "60"};
    printLargest(arr, 4);
}
