// Last Update:2018-02-28 14:17:55
/**
 * @file form-min-num-from-given-seq.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-02-28
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void printArray(int arr[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void PrintMinNumberForPattern(char * str)
{
    int len = strlen(str);
    int num[len + 1], i,j, tmp;
    int dec = 0;
    for(i = 0; i< len + 1; i++)
        num[i] = i + 1;
    printArray(num, len + 1);

    for(i = 0; i < len; i++)
    {
        if(str[i] == 'I')
            dec = 0;
        else {
            dec++;
        }
        if(dec)
        {
            tmp = num[i + 1];
            for(j = i+1; j > i + 1 - dec; j--)
                num[j] = num[j-1];
            num[j] = tmp;
        }
    }

    for(i = 0; i < len + 1; i++)
        printf("%d ", num[i]);
    printf("\n");
}

int main()
{
    PrintMinNumberForPattern("IDID");
    PrintMinNumberForPattern("I");
    PrintMinNumberForPattern("DD");
    PrintMinNumberForPattern("II");
    PrintMinNumberForPattern("DIDI");
    PrintMinNumberForPattern("IIDDD");
    PrintMinNumberForPattern("DDIDDIID");
}
