// Last Update:2018-02-27 11:14:09
/**
 * @file shuffle-a-given-array.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-02-27
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int * a, int * b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void printArray(int arr[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void randomize(int arr[], int n)
{
    srand(time(NULL));
    int i;
    for(i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    randomize(arr, n);
    printArray(arr, n);
    return 0;
}
