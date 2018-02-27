// Last Update:2018-03-07 13:20:20
/**
 * @file query-gcd-num-arr.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-07
 */
#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a%b);
}

void FillPrefixSuffix(int prefix[], int arr[], int suffix[], int n)
{
    prefix[0] = arr[0];
    for(int i = 1; i < n; i++)
        prefix[i] = GCD(prefix[i - 1], arr[i]);

    suffix[n - 1] = arr[n - 1];
    for(int i = n - 2; i >= 0; i--)
        suffix[i] = GCD(suffix[i + 1], arr[i]);
}

int GCDoutsideRange(int l, int r, int prefix[], int suffix[], int n)
{
    if (l == 0)
        return suffix[r + 1];
    if (r == n - 1)
        return prefix[l - 1];
    return GCD(prefix[l - 1], suffix[r + 1]);
}

int main()
{
    int arr[] = {2, 6, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int prefix[n], suffix[n];
    FillPrefixSuffix(prefix, arr, suffix, n);
 
    int l = 0, r = 0;
    cout << GCDoutsideRange(l, r, prefix, suffix, n)
         << endl;
    l = 1 ; r = 1;
    cout << GCDoutsideRange(l, r, prefix, suffix, n)
         << endl;
    l = 1 ; r = 2;
    cout << GCDoutsideRange(l, r, prefix, suffix, n)
         << endl;
    return 0;
}
