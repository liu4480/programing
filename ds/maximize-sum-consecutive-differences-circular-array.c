// Last Update:2018-02-26 13:51:13
#include <bits/stdc++.h>
using namespace std;

int maxSum(int arr[], int n)
{
    int sum = 0;
    sort(arr, arr + n);
    for(int i = 0; i < n/2; i++)
    {
        sum -= (2 * arr[i]);
        sum += (2 * arr[n - 1 - i]);
    }
    return sum;
}

int main()
{
    int arr[] = {4, 2, 1, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSum(arr, n) << endl;
    return 0;
}
