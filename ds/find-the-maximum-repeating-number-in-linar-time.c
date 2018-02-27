// Last Update:2018-03-02 14:37:34
/**
 * @file find-the-maximum-repeating-number-in-linar-time.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-02
 */
#include <stdio.h>
#include <stdlib.h>

int maxRepeating(int * arr, int n, int k, int *max)
{
    int i, result;
    for(i = 0; i < n; i++)
        arr[arr[i]%k] += k;

    *max = arr[0], result = 0;
    for(i = 1; i < n; i++)
    {
        if(arr[i] > *max)
        {
            *max = arr[i];
            result = i;
        }
    }
    return result;
}

int main()
{
    int arr[] = {2,3,3,5,3,4,1,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 8, max;
    int result = maxRepeating(arr, n, k, &max);
    printf("The maximum repeating number is %d, it appears %d time(s)\n",
           result, (max - max%k) / k);
    return 0;
}
