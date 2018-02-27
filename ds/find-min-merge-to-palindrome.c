// Last Update:2018-03-09 16:06:29
/**
 * @file find-min-merge-to-palindrome.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-09
 */

#include <bits/stdc++.h>
using namespace std;

int findMinOps(int arr[], int n)
{
    int ans = 0;

    for(int i = 0, j = n - 1; i <= j;)
    {
        if (arr[i] == arr[j])
        {
            i++;
            j--;
        }
        else if(arr[i] > arr[j])
        {
            j--;
            cout << "merging arr[" << j << "] : " << arr[j]
                 << " and arr[" << j + 1 << "] : " << arr[j + 1] << endl; 
            arr[j] += arr[j + 1];
            ans++;
        }
        else
        {
            i++;
            cout << "merging arr[" << i << "] : " << arr[i]
                 << " and arr[" << i - 1 << "] : " << arr[i - 1] << endl; 
            arr[i] += arr[i - 1];
            ans++;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1, 4, 5, 9, 1};
    int n = sizeof arr/sizeof arr[0];
    cout << "Count of minimum operatinos is "
         << findMinOps(arr, n) << endl;
    return 0;
}
