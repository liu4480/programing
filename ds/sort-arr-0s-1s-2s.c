// Last Update:2018-03-12 15:55:03
/**
 * @file sort-arr-0s-1s-2s.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-12
 */
#include <stdio.h>

void swap(int *a, int *b);

void sort012(int a[], int size)
{
    int lo = 0;
    int hi = size - 1, mid = 0;

    while(mid <= hi)
    {
        switch(a[mid])
        {
        case 0:
            swap(&a[lo++], &a[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(&a[mid], &a[hi--]);
            break;
        }
    }
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {0,1,1,0,1,2,1,2,0,0,0,1};
    int n = sizeof arr/sizeof arr[0];
    int i;

    printArray(arr, n);
    sort012(arr, n);
    printf("after segregation\n");
    printArray(arr, n);

    return 0;
}
