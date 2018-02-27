// Last Update:2018-03-01 13:47:04
/**
 * @file next-greater-ele.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-01
 */
#include <iostream>
using namespace std;

void nextGreater(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int next = -1;
        for(int j = i + 1; j < n; j++)
            if (arr[i] < arr[i + 1])
            {
                next = arr[i + 1];
            }
        cout << arr[i] << " -- " << next << endl;
    }
}

int main()
{
    int arr[] = {11, 13, 21, 3};
    int n = sizeof arr/sizeof arr[0];
    nextGreater(arr, n);
    return 0;
}

