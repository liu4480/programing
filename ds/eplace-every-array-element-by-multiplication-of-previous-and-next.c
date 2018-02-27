// Last Update:2018-02-27 16:26:36
/**
 * @file eplace-every-array-element-by-multiplication-of-previous-and-next.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-02-27
 */
#include <iostream>
using namespace std;

void modify(int arr[], int n)
{
    if (n <= 1)
        return;
    int prev = arr[0];
    arr[0] = arr[0] * arr[1];

    for(int i = 1; i < n - 1; i++)
    {
        int curr = arr[i];
        arr[i] = prev * arr[i + 1];
        prev = curr;
    }

    arr[n-1] = prev * arr[n - 1];
}

int main()
{
    int arr[] = {2,3,4,5,6};
    int n = sizeof arr/sizeof arr[0];
    modify(arr, n);
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
