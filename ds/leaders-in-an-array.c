// Last Update:2018-03-12 13:39:56
/**
 * @file leaders-in-an-array.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-12
 */
#include <iostream>
using namespace std;
 
/* C++ Function to print leaders in an array */
void printLeaders(int arr[], int size)
{
    int max_from_right =  arr[size-1];
 
    /* Rightmost element is always leader */
    cout << max_from_right << " ";
     
    for (int i = size-2; i >= 0; i--)
    {
        if (max_from_right < arr[i])
        {           
            max_from_right = arr[i];
            cout << max_from_right << " ";
        }
    }    
    cout << endl;
}
 
/* Driver program to test above function*/
int main()
{
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    printLeaders(arr, n);
    return 0;
}
