// Last Update:2018-02-22 15:50:30
#include <stdio.h>
#include <stdlib.h>

void leftRotatebyOne(int arr[], int n);

void leftRotate(int arr[], int d, int n)
{
    int i;
    for(i = 0; i < d; i++)
        leftRotatebyOne(arr, n);
}

void leftRotatebyOne(int arr[], int n)
{
    int i, temp;
    temp = arr[0];
    for(i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];
    arr[i] = temp;
}

void printArray(int arr[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    leftRotate(arr, 2, 7);
    printArray(arr, 7);
//    getchar();
    return 0;
}
