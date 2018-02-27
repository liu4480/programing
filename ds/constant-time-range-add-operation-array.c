// Last Update:2018-03-07 11:22:55
/**
 * @file constant-time-range-add-operation-array.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-07
 */
#include <bits/stdc++.h>
using namespace std;
void add(int arr[], int N, int lo, int hi, int val)
{
    arr[lo] += val;
    if(hi != N - 1)
        arr[hi + 1] -= val;
}

void updateArray(int arr[], int N)
{
    for(int i = 1; i < N; i++)
        arr[i] += arr[i-1];
}

void printArray(int arr[], int N)
{
    updateArray(arr, N);
    for(int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int N = 6;
    int arr[] = {0, 0, 0, 0, 0, 0};
    add(arr, N, 0, 2, 100);
    add(arr, N, 1, 5, 100);
    add(arr, N, 2, 3, 100);

    printArray(arr, N);
    return 0;
}
