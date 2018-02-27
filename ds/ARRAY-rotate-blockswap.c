// Last Update:2018-02-22 16:29:31
#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size);
void swap(int arr[], int fi, int si, int d);

void leftRotate(int arr[], int d, int n)
{
    printArray(arr, n);
    if (d == 0 || n == 0)
        return;

    if(n -d == d)
    {
        swap(arr, 0, n-d, d);
        return;
    }
    if(d < n - d)
    {
        swap(arr, 0, n - d, d);
        leftRotate(arr, d, n - d);
    }
    else
    {
        swap(arr, 0, d, n - d);
        leftRotate(arr + n - d, 2 * d -n, d);
    }
}

void printArray(int arr[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

void swap(int arr[], int fi, int si, int d)
{
    int i, tmp;
    for(i = 0; i < d; i++)
    {
        tmp = arr[fi + i];
        arr[fi + i] = arr[si + i];
        arr[si + i] = tmp;
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    leftRotate(arr, 2, 7);
    printArray(arr, 7);
    return 0;
}
