// Last Update:2018-03-12 13:53:02
/**
 * @file counting-inversions.c
 * @brief
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-12
 */
#include <bits/stdc++.h>

int _mergeSort(int arr[], int tmp[], int left, int right);
int merge(int arr[], int tmp[], int left, int mid, int right);

int mergeSort(int arr[], int n)
{
    int * tmp = new int[n];
    return _mergeSort(arr, tmp, 0, n - 1);
}

int _mergeSort(int arr[], int tmp[], int left, int right)
{
    int mid, inv_count = 0;
    if(right > left)
    {
        mid = (right + left) / 2;
        inv_count = _mergeSort(arr, tmp, left, mid);
        inv_count += _mergeSort(arr, tmp, mid + 1, right);

        inv_count += merge(arr, tmp, left, mid + 1, right);
    }
    return inv_count;
}

int merge(int arr[], int tmp[], int left, int mid, int right)
{
    int i, j, k;
    int inv_count = 0;
    i = left;
    j = mid;
    k = left;

    while((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
            tmp[k++] = arr[i++];
        else
        {
            tmp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }

    while (i <= mid - 1)
        tmp[k++] = arr[i++];
    while (j <= right)
        tmp[k++] = arr[j++];

    for(i = left; i <= right; i++)
        arr[i] = tmp[i];

    return inv_count;
}

int main()
{
    int arr[] = {1, 20, 6, 4, 5};
    printf("Number of inversions are %d\n", mergeSort(arr, 5));
    return 0;
}
