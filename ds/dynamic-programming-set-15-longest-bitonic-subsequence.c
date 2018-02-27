// Last Update:2018-02-26 14:35:08
/**
 * @file dynamic-programming-set-15-longest-bitonic-subsequence.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-02-26
 */
#include <stdio.h>
#include <stdlib.h>

int lbs(int arr[], int n)
{
    int i, j, max, tmp;
    int * lis = new int[n];
    int * lds = new int[n];

    for (i = 0; i < n; i++)
       lis[i] = 1;
 
    for (i = n-1; i >= 0; i--)
       lds[i] = 1;

    for(i = 0; i < n; i++)
        for( j = 0; j < i; j++)
            if(arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;

    for(i = n - 2; i >= 0; i--)
        for(j = n - 1; j > i; j--)
            if(arr[i] > arr[j] && lds[i] < lds[j] + 1)
                lds[i] = lds[j] + 1;


    max = lis[0] + lds[0] - 1;
    for(i = 1; i < n; i++)
    {
        tmp = lis[i] + lds[i] - 1;
        if(tmp > max)
        {
            max = tmp;
        }
    }
    return max;
}

int main()
{
    int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5,
                        13, 3, 11, 7, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max_len;
    max_len = lbs(arr, n);
    printf("Length of LBS is %d\n", max_len);
    printf("\n");
    return 0;
}
