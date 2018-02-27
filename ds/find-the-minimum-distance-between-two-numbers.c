// Last Update:2018-03-07 15:27:06
/**
 * @file find-the-minimum-distance-between-two-numbers.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-07
 */
#include <stdio.h>
#include <limits.h>

int minDist(int arr[], int n, int x, int y)
{
    int i = 0;
    int min_dist = INT_MAX;
    int prev;

    for(i = 0; i < n; i++)
    {
        if(arr[i] == x || arr[i] == y)
        {
            prev = i;
            break;
        }
    }

    for(; i < n; i++)
    {
        if(arr[i] == x || arr[i] == y)
        {
            if(arr[prev] != arr[i] && (i - prev) < min_dist)
                min_dist = i - prev;
            prev = i;
        }
    }
    return min_dist;
}

int main()
{
    int arr[] = {3, 5, 4, 2, 6, 3, 0, 0, 5, 4, 8, 3};
    int n = sizeof arr/sizeof arr[0];
    int x = 3;
    int y = 6;
    printf("Minimum distance between %d and %d is %d\n",
           x, y, minDist(arr, n, x, y));
    return 0;
}
