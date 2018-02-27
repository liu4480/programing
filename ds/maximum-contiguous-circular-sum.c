// Last Update:2018-02-27 10:59:50
/**
 * @file maximum-contiguous-circular-sum.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-02-27
 */
#include <stdio.h>
#include <stdlib.h>

int kadane(int arr[], int n)
{
    int max = 0, max_v = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        max_v += arr[i];
        if(max_v < 0)
            max_v = 0;
        if(max < max_v)
            max = max_v;
    }
    return max;
}

int maxCircularSum(int arr[], int n)
{
    int max_kadane = kadane(arr, n);

    int max_wrap = 0, i;
    for(i = 0; i < n; i++)
    {
        max_wrap += arr[i];
        arr[i] = -arr[i];
    }
    max_wrap = max_wrap + kadane(arr, n);

    return (max_wrap > max_kadane) ? max_wrap: max_kadane;
}

int main()
{
    int arr[] = {11, 10, -20, 5, -3, -5, 8, -13, 10};
    int n = sizeof arr / sizeof arr[0];
    printf("Maximum circular sum is %d\n",
           maxCircularSum(arr, n));
    return 0;
}
