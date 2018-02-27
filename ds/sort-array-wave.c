// Last Update:2018-02-23 13:36:20
/**
 * @file sort-array-wave.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-02-23
 */
#include<iostream>
#include<algorithm>
using namespace std;

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void sortInWave(int arr[], int n)
{
    sort(arr, arr + n);
    for(int i = 0; i < n - 1; i += 2)
        swap(&arr[i], &arr[i + 1]);
}

void sortInWave2(int arr[], int n)
{
    for(int i = 0; i < n; i += 2)
    {
        if(i > 0 && (arr[i - 1] > arr[i]))
            swap(&arr[i], &arr[i-1]);
        if(i < n - 1 && (arr[i] < arr[i + 1]))
            swap(&arr[i], &arr[i+1]);
        for (int i=0; i<n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
}

int main()
{
    int arr[] = {10, 90, 49, 2, 1, 5, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    //sortInWave(arr, n);
    sortInWave2(arr, n);
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
