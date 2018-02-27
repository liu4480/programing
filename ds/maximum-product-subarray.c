// Last Update:2018-02-26 16:18:48
/**
 * @file maximum-product-subarray.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-02-26
 */
#include <stdio.h>
int max(int a, int b)
{
    (a > b) ? a : b;
}

int min(int a, int b)
{
    (a < b) ? a : b;
}

int maxValue(int arr[], int n)
{
    int i, max_v = 1, min_v = 1;
    int maximum = 1;
    for(i = 0; i < n; i++)
    {
        if(arr[i] == 0){
            max_v = 1;
            min_v = 1;
        } else if(arr[i] > 0) {
            max_v = max_v * arr[i];
            min_v = min(min_v * arr[i], 1);
        } else {
            int v = max_v;
            max_v = max(min_v * arr[i], 1);
            min_v = v * arr[i];
        }
        if(maximum < max_v)
            maximum = max_v;
    }

    return maximum;
}

int main()
{
    int arr[] = {1, -2, -3, 0, 7, -8, -2};
    int n = sizeof arr / sizeof arr[0];
    printf("Maximum sub array product is %d\n", 
           maxValue(arr, n));
    return 0;
}
