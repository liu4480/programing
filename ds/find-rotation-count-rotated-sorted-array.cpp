// Last Update:2018-02-23 11:04:31
/**
 * @file find-rotation-count-rotated-sorted-array.cpp
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-02-23
 */

#include<bits/stdc++.h>
using namespace std;
 
// Returns count of rotations for an array which
// is first sorted in ascending order, then rotated
int countRotations(int arr[], int n)
{
    // We basically find index of minimum
    // element
    int min = arr[0], min_index;
    for (int i=0; i<n; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
            min_index = i;
        }
    }
    return min_index;
}

int countRotations2(int arr[], int n)
{
    int min = arr[0], minindex;
    for(int i = 1; i < n; i++)
    {
        if((arr[(n + i - 1) % n] > arr[i]) &&
           (arr[i] < arr[(i+1)%n])){
            minindex = i;
            break;
        }
    }
    return minindex;
}
 
// Driver code
int main()
{
    int arr[] = {15, 18, 2, 3, 6, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << countRotations(arr, n) << endl;
    cout << countRotations2(arr, n) << endl;
    return 0;
}
