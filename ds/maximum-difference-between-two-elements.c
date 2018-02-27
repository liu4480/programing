// Last Update:2018-03-01 14:36:13
/**
 * @file maximum-difference-between-two-elements.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-01
 */
#include <stdio.h>

int maxDiff(int arr[], int n)
{
    int max_diff = arr[1] - arr[0];
    int min_element = arr[0], i;
    for(i = 1; i < n; i++)
    {
        if (arr[i] - min_element > max_diff)
            max_diff = arr[i] - min_element;
        if(arr[i] < min_element)
            min_element = arr[i];
    }
    return max_diff;
}

int main()
{
    int arr[] = {1,2,6,80,100};
    int size = sizeof arr/sizeof arr[0];
    printf("Maximum difference is %d\n", maxDiff(arr, size));
    return 0;
}
