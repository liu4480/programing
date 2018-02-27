// Last Update:2018-03-07 13:11:16
/**
 * @file find-whether-subarray-form-mountain-not.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-07
 */
#include <bits/stdc++.h>
using namespace std;

int preprocess(int arr[], int N, int left[], int right[])
{
    left[0] = 0;
    int lastIncr = 0;

    for(int i = 1; i < N; i++)
    {
        if (arr[i] > arr[i - 1])
            lastIncr = i;
        left[i] = lastIncr;
    }

    right[N - 1] = N - 1;
    int firstDecr = N - 1;

    for(int i = N - 2;i >= 0; i--)
    {
        if(arr[i] > arr[i + 1])
           firstDecr = i;
        right[i] = firstDecr;
    }
}

bool isSubarrayMountainForm(int arr[], int left[], int right[], int L, int R)
{
    return (right[L] >= left[R]);
}

int main()
{
    int arr[] = {2, 3, 2, 4, 4, 6, 3, 2};
    int N = sizeof(arr) / sizeof(int);
 
    int left[N], right[N];
    preprocess(arr, N, left, right);
 
    int L = 0;
    int R = 2;
    if (isSubarrayMountainForm(arr, left, right, L, R))
        cout << "Subarray is in mountain form\n";
    else
        cout << "Subarray is not in mountain form\n";
 
    L = 1;
    R = 3;
    if (isSubarrayMountainForm(arr, left, right, L, R))
        cout << "Subarray is in mountain form\n";
    else
        cout << "Subarray is not in mountain form\n";
 
    return 0;
}
