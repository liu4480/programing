// Last Update:2018-03-09 14:51:07
/**
 * @file minimum-number-of-jumps-to-reach-end-of-a-given-array.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-09
 */
#include <stdio.h>
#include <limits.h>

int minJumps(int arr[], int l, int h)
{
    if(h == l)
        return 0;

    if(arr[l] == 0)
        return INT_MAX;

    int min = INT_MAX;
    for(int i = l + 1; i <= h && i <= l + arr[l]; i++)
    {
        int jumps = minJumps(arr, i, h);
        if(jumps != INT_MAX && jumps + 1 < min)
            min = jumps + 1;
    }
    return min;
}

int main()
{
    int arr[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
    int n = sizeof arr/sizeof arr[0];
    printf("Minimum number of jumps to reach the end is %d\n", minJumps(arr, 0, n - 1));
    return 0;
}
