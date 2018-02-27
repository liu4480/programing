// Last Update:2018-02-23 15:19:59
/**
 * @file sort-an-array-according-to-absolute-difference-with-given-value.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-02-23
 */
#include<bits/stdc++.h>
using namespace std;
 
// Function to sort an array according absolute
// difference with x.
void rearrange(int arr[], int n, int x)
{
    multimap<int, int> m;
 
    // Store values in a map with the difference
    // with X as key
    for (int i = 0 ; i < n; i++)
        m.insert(make_pair(abs(x-arr[i]),arr[i]));
 
    // Update the values of array
    int i = 0;
    for (auto it = m.begin(); it != m.end(); it++)
        arr[i++] = (*it).second ;
}
 
// Function to print the array
void printArray(int arr[] , int n)
{
    for (int i = 0 ; i < n; i++)
        cout << arr[i] << " ";
}
 
// Driver code
int main()
{
    int arr[] = {10, 5, 3, 9 ,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 7;
    rearrange(arr, n, x);
    printArray(arr, n);
    return 0;
}
