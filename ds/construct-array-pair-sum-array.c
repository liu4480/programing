// Last Update:2018-03-19 13:32:26
/**
 * @file construct-array-pair-sum-array.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-19
 */
#include <iostream>
using namespace std;
 
// Fills element in arr[] from its pair sum array pair[]. 
// n is size of arr[]
void constructArr(int arr[], int pair[], int n)
{
    arr[0] = (pair[0]+pair[1]-pair[n-1]) / 2;
    for (int i=1; i<n; i++)
        arr[i] = pair[i-1]-arr[0];
}
 
// Driver program to test above function
int main()
{
    int pair[] = {15, 13, 11, 10, 12, 10, 9, 8, 7, 5};
    int n = 5;
    int arr[n];
    constructArr(arr, pair, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
