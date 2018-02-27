// Last Update:2018-03-01 13:18:12
/**
 * @file k-th-smallest-absolute-difference-two-elements-array.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-01
 */
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

/*
int countPairs(int *a, int n, int mid)
{
    int res = 0;
    for(int i = 0; i < n; ++i)
        res += upper_bound(a+i, +n, a[i] + mid) - (a + i + 1);
    return res;
}
*/

int getKthDiff(int arr[], int l, int h, int k)
{
    if(l < h)
    {
        int mid = l + (h - l)/2;
        if (mid - l == k)
            return mid;
        else if (mid -l < k)
            return getKthDiff(arr, mid + 1, h, k - mid); 
        else
            return getKthDiff(arr, l, mid - 1, k);
    }
    return -1;
}

int getKthDiff_wrapper(int arr[], int n, int k)
{
    sort(arr, arr + n);
    return getKthDiff(arr, 0, n - 1, k);
}

int main()
{
    int k = 3;
    int a[] = {1, 2, 3, 4};
    int n = sizeof(a)/sizeof(a[0]);
    cout << getKthDiff_wrapper(a, n, k);
    return 0;
}
