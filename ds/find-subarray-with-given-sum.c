// Last Update:2018-03-16 13:42:22
/**
 * @file find-subarray-with-given-sum.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-16
 */
#include <stdio.h>

int findSum(int arr[], int n, int x)
{
    int start, sum, i;
    sum = arr[0];
    start = 0;
    for(i = 1; i < n; i++)
    {
        while(sum > x)
        {
            sum -= arr[start];
            start++;
        }
        if (sum == x)
        {
            printf("find sum between indexes %d and %d\n", start, i - 1);
            return 1;
        }
        if (i < n)
            sum += arr[i];
    }
    printf("No subarray found\n");
    return 0;

}

int main()
{
    int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
    int n = sizeof arr/sizeof arr[0];
    int sum = 23;
    findSum(arr, n, sum);
    return 0;
}
