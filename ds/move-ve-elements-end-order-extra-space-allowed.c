// Last Update:2018-02-23 15:23:25
/**
 * @file move-ve-elements-end-order-extra-space-allowed.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-02-23
 */
#include <bits/stdc++.h>
using namespace std;

void segregateElements(int arr[], int n)
{
    int tmp[n];
    int j = 0;
    for(int i = 0; i < n; i++)
        if (arr[i] >= 0)
            tmp[j++] = arr[i];
    
    if (j == n || j ==0)
        return;

    for(int i = 0; i < n; i++)
        if(arr[i] < 0)
            tmp[j++] = arr[i];

    memcpy(arr, tmp, sizeof(tmp));
}

int main()
{
    int arr[] = {1, -1, -3, -2, 7, 5, 11, 6};
    int n = sizeof arr / sizeof arr[0];

    segregateElements(arr, n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
