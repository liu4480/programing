// Last Update:2018-02-26 13:58:34
/**
 * @file alternative-sorting.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-02-26
 */
#include <bits/stdc++.h>

using namespace std;

void alternateSort(int arr[], int n)
{
    int minIndex = 0;
    int maxIndex = n - 1;
    sort(arr, arr + n);
    int i = 0;
    int maxEle = arr[n-1] + 1;
    while(minIndex <= maxIndex) {
        if(i & 1) {
            arr[i] = arr[i] + (arr[minIndex] % maxEle) * maxEle;
            i++;
            minIndex++;
        } else {
            arr[i] = arr[i] + (arr[maxIndex] % maxEle) * maxEle;
            i++;
            maxIndex--;
        }
    }
    for(i = 0; i < n; i++)
        if (arr[i] > maxIndex)
            arr[i] = arr[i] / maxEle;
}

int main()
{
    int arr[] = {1,12,4,6,7,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    alternateSort(arr, n);
    for(int i=0; i < n; i++)
        cout << arr[i] <<" ";
    cout << endl;
    return 0;
}
