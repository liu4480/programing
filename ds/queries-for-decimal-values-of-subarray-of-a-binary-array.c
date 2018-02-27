// Last Update:2018-03-07 14:05:14
/**
 * @file queries-for-decimal-values-of-subarray-of-a-binary-array.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-07
 */
#include <bits/stdc++.h>
using namespace std;

void precompute(int arr[], int n, int pre[])
{
    memset(pre, 0, n * sizeof(int));
    pre[n - 1] = arr[n - 1] * pow(2, 0);
    for(int i = n - 2;i >= 0; i--)
        pre[i] = pre[i + 1] + arr[i] * (1 << (n - 1 - i));
}

int decimalOfSubarr(int arr[], int l, int r, int n, int pre[])
{
    if( r != n - 1)
        return (pre[l] - pre[r+1])/(1 << (n -1 -r));

    return pre[l]/(1 << (n - 1 - r));
}

int main()
{
    int arr[] = {1,0,1,0,1,1};
    int n = sizeof arr/sizeof arr[0];

    int pre[n];
    precompute(arr, n, pre);
    cout << decimalOfSubarr(arr, 2, 4, n, pre) << endl;
    cout << decimalOfSubarr(arr, 4, 5, n, pre) << endl;
    return 0;
}
