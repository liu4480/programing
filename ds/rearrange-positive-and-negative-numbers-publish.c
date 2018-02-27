// Last Update:2018-02-23 13:16:22
/**
 * @file rearrange-positive-and-negative-numbers-publish.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-02-23
 */
#include <stdio.h>

void swap(int * a, int * b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void rearrange(int arr[], int n)
{
    int i = -1;
    for(int j = 0; j < n; j++)
    {
        if(arr[j] < 0)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    for(int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");

    int pos = i + 1, neg = 0;
    while(pos < n && neg < pos && arr[neg] < 0)
    {
        swap(&arr[neg], &arr[pos]);
        pos++;
        neg += 2;
    }
}

int main()
{
    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int n = sizeof arr / sizeof arr[0];
    rearrange(arr, n);
    for(int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
    return 0;
}
