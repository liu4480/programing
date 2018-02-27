// Last Update:2018-02-26 16:40:28
/**
 * @file greater-on-right.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-02-26
 */
#include<iostream>

using namespace std;

void findMax(int arr[], int start, int end)
{
    int max = arr[end];
    int tmp;
    for(int j = end - 1;j >= start; j--)
    {
        tmp = arr[j];
        arr[j] = max;
        if (max < tmp)
            max = tmp;
    }
    arr[end] = -1;
}

void process(int arr[], int n)
{
    findMax(arr, 0, n - 1);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int t, n;
    int *arr;
    cin >> t;
    for(int j=0; j < t; j++)
    {
        cin >> n;
        arr = new int[n];
        for(int i=0; i < n; i++)
            cin >> arr[i];
        process(arr, n);
        delete []arr;
    }
    return 0;
}
