// Last Update:2018-02-23 14:12:56
/**
 * @file rearrange-positive-and-negative-numbers.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-02-23
 */
#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout <<endl;
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1 +j];

    i = 0, j = 0, k = l;

    while(i < n1 && L[i] < 0)
        arr[k++] = L[i++];

    while(j < n2 && R[j] < 0)
        arr[k++] = R[j++];

    while(i < n1)
        arr[k++] = L[i++];
    while(j < n2)
        arr[k++] = R[j++];
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverse(int arr[], int l, int r)
{
    if(l < r)
    {
        swap(arr[l], arr[r]);
        reverse(arr, ++l, --r);
    }
}

void merge2(int arr[], int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    while(i <= m && arr[i] < 0)
        i++;

    while(j <= r && arr[j] < 0)
        j++;

    reverse(arr, i, m);
    reverse(arr, m + 1, j - 1);
    reverse(arr, i, j - 1);
}

void rearrangePosNeg(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = l + (r - l) / 2;
        rearrangePosNeg(arr, 1, m);
        rearrangePosNeg(arr, m + 1, r);
        //merge(arr, l, m, r);
        merge2(arr, l, m, r);
    }
}

int main()
{
    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    rearrangePosNeg(arr, 0, arr_size - 1);
    printArray(arr, arr_size);
    return 0;
}
