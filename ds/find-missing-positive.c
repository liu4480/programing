// Last Update:2018-03-02 14:00:47
/**
 * @file find-missing-positive.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-02
 */
#include <stdio.h>
#include <stdlib.h>

void swap(int * a, int * b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int segregate(int arr[], int n)
{
    int j = 0, i;
    for(i = 0; i < n; i++)
    {
        swap(&arr[i], &arr[j]);
        j++;
    }
    return j;    
}

int findMissing(int arr[], int n)
{
    int shift = segregate(arr, n);
    //return findMissingPositive(arr + shift, size - shift);
    int i;
    for(i = shift; i < n; i++)
    {
        if(abs(arr[i]) - 1 < n && arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
    }
    for(i = shift; i < n; i++)
        if (arr[i] > 0)
            return i + 1;
    return n - shift + 1;
}

int main()
{
    int arr[] = {0,10,2,-10,-20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int missing = findMissing(arr, n);
    printf("The smallest positive missing number is %d\n", missing);
    return 0;
}
