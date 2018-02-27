// Last Update:2018-03-09 15:34:37
/**
 * @file find-maximum-average-subarray-of-k-length.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-09
 */
#include <bits/stdc++.h>
using namespace std;

int findMaxAverage(int arr[], int n, int k)
{
    if (k > n)
        return -1;
    int * csum = new int[n];
    csum[0] = arr[0];
    for(int i = 1; i < n; i++)
        csum[i] = csum[i - 1] + arr[i];

    int max_sum = csum[k - 1], max_end = k - 1;
    for(int i = k; i < n; i++)
    {
        int curr_sum = csum[i] - csum[i - k];
        if(curr_sum > max_sum)
        {
            max_sum = curr_sum;
            max_end = i;
        }
    }
    delete []csum;
    return max_end - k + 1;
}

int findMaxAverage2(int arr[], int n, int k)
{
    if (k > n)
        return -1;

    int sum = arr[0];
    for(int i = 1; i < k; i++)
        sum += arr[i];

    int max_sum = sum, max_end = k - 1;
    for(int i = k; i < n; i++)
    {
        sum = sum + arr[i] - arr[i - k];
        if(sum > max_sum)
        {
            max_sum = sum;
            max_end = i;
        }
    }

    return max_end - k + 1;
}

int main()
{
    int arr[] = {1, 12, -5, -6 , 50, 3};
    int k = 4;
    int n = sizeof arr/sizeof arr[0];

    cout << "The maximum average subarray of length " << k
         << " begins at index " << findMaxAverage2(arr, n, k) << endl;

    return 0;
}
