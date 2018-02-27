// Last Update:2018-02-23 15:50:59
/**
 * @file rearrange-array-maxmin.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-02-23
 */
#include <iostream>
using namespace std;

void swap(int * a, int * b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void rearrange(int arr[], int n)
{
    int max_idx = n - 1, min_idx = 0;
    int max_elem = arr[n - 1] + 1;
    for(int i = 0; i < n; i++)
    {
        if(i%2 == 0)
        {
            arr[i] +=(arr[max_idx]%max_elem)*max_elem;
            max_idx--;
        }
        else
        {
            arr[i] += (arr[min_idx] % max_elem) * max_elem;
            min_idx++;
        }
    }
    for(int i = 0; i < n; i++)
        arr[i] = arr[i] / max_elem;
}

void change(int arr[],int n)
{
    cout << "Original Array\n";
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
 
    rearrange(arr, n);
 
    cout << "Modified Array\n";
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{

    int arr1[] = {1,2,3,4,5,6,7,8,9};
    int arr2[] = {1,2,3,4,5,6,7,8};
    int arr3[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    change(arr1, n);
    n = sizeof(arr2)/sizeof(arr2[0]);
    change(arr2, n);
    n = sizeof(arr3)/sizeof(arr3[0]);
    change(arr3, n);
    return 0;
}
