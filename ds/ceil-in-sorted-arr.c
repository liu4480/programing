// Last Update:2018-03-12 14:51:56
/**
 * @file ceil-in-sorted-arr.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-12
 */
#include <stdio.h>

int ceilSearch(int arr[], int low, int high, int x)
{
    int mid;

    if (x <= arr[low])
        return low;

    if (x > arr[high])
        return -1;

    mid = (low + high) / 2;

    if (arr[mid] == x)
        return mid;
    else if (arr[mid] < x)
    {
        if(mid + 1 <= high && x <= arr[mid + 1])
            return mid + 1;
        else
            ceilSearch(arr, mid + 1, high, x);
    }
    else
    {
        if (mid - 1 > low && x > arr[mid - 1])
            return mid;
        else
            return ceilSearch(arr, low, mid - 1, x);
    }
}

int main()
{
    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int n = sizeof arr/sizeof arr[0];
    int x = 20;
    int index = ceilSearch(arr, 0, n - 1, x);
    if (index == -1)
        printf("Ceiling of %d doesn't exist in array.\n", x);
    else
        printf("Ceiling of %d is %d.\n", x, arr[index]);

    return 0;
}
