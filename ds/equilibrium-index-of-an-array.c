// Last Update:2018-03-13 13:47:15
/**
 * @file equilibrium-index-of-an-array.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-13
 */
#include <stdio.h>

int equilibrium(int arr[], int n)
{
    int sum = 0, leftsum = 0, i;

    for (i = 0; i < n; i++)
        sum += arr[i];

    for (i = 0; i < n; i++)
    {
        sum -= arr[i];
        if (sum == leftsum)
            return i;

        leftsum += arr[i];
    }

    return -1;
}

int main()
{
    int arr[] = {-7, 1, 5, 2, -4 , 3, 0};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printf("First equilibrium index is %d\n", equilibrium(arr, arr_size));
    return 0;
}
