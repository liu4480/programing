// Last Update:2018-02-23 11:27:08
/**
 * @file quickly-find-multiple-left-rotations-of-an-array.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-02-23
 */
#include <stdio.h>
void leftRotate(int arr[], int n, int k)
{
    int i;
    k = k % n;
    for(i = k; i < n; i++)
        printf("%d\t", arr[i]);
    for(i = 0; i < k; i++) 
        printf("%d\t", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof arr / sizeof arr[0];

    int k = 2;
    leftRotate(arr, n, k);
    k = 3;
    leftRotate(arr, n, k);
    k = 4;
    leftRotate(arr, n, k);
    k = 5;
    leftRotate(arr, n, k);
}
