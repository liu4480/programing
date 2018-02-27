// Last Update:2018-03-01 11:25:42
/**
 * @file find-k-smallest-pairs.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-01
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void kSmallestPair(int arr[], int n1, int arr2[],
                                int n2, int k)
{
    if(k > n1 * n2)
    {
        cout << "k pairs don't exist" << endl;
        return;
    }

    int index2[n1];
    memset(index2, 0, sizeof(index2));

    while(k > 0)
    {
        int min_sum = INT_MAX;
        int min_index = 0;

        for(int i1 = 0; i1 < n1; i1++)
        {
            if(index2[i1] < n2 && arr[i1] + arr[index2[i1]] < min_sum)
            {
                min_index = i1;
                min_sum = arr[i1] + arr2[index2[i1]];
            }
        }

        cout << "(" << arr[min_index] << ", "
            << arr2[index2[min_index]] << ")";

        cout << endl;
        index2[min_index]++;
        k--;
    }
}

int main()
{
    int arr1[] = {1,3,11};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);

    int arr2[] = {2,4,8};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    int k = 4;
    kSmallestPair(arr1, n1, arr2, n2, k);
    return 0;
}
