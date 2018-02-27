// Last Update:2018-02-27 15:54:27
/**
 * @file arrj-2-arr-i.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-02-27
 */
#include <stdio.h>

void rearrangeNaive(int arr[], int n)
{
    int tmp[n], i;
    for(i = 0; i < n; i++)
        tmp[arr[i]] = i;

    for(i = 0; i < n; i++)
        arr[i] = tmp[i];
}

void rearrangeNaive2(int arr[], int n)
{
    int i = arr[0], val = 0;
    while(i != 0)
    {
        int new_val = arr[i];
        arr[i] = val;

        val = i;
        i = new_val;
    }
    arr[i] = val;
}

void printArray(int arr[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {1, 3, 0, 2};
    int n = sizeof arr/sizeof arr[0];

    printf("Given array is\n");
    printArray(arr, n);

    rearrangeNaive2(arr, n);

    printf("Modified array is\n");
    printArray(arr, n);
    return 0;
}
