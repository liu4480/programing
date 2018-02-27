// Last Update:2018-02-27 15:00:15
/**
 * @file sort-array-according-order-defined-another-array.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-02-27
 */
#include <iostream>
#include <algorithm>
using namespace std;

int first(int arr[], int low, int high, int x, int n)
{
    if(high >= low)
    {
        int mid = low + (high - low) / 2;
        if((mid == 0 || x > arr[mid - 1]) && arr[mid] == x)
            return mid;
        if(x > arr[mid])
            return first(arr, (mid + 1), high, x, n);
        return first(arr, low, (mid - 1), x, n);
    }
    return -1;
}

void sortAccording(int A1[], int A2[], int m, int n)
{
    int tmp[m], visited[m];
    for(int i = 0; i < m; i++)
    {
        tmp[i] = A1[i];
        visited[i] = 0;
    }

    sort(tmp, tmp + m);

    int ind = 0;
    for(int i = 0; i < n; i++)
    {
        int f = first(tmp, 0, m-1, A2[i], m);
        if (f == -1) continue;

        for(int j = f; (j < m && tmp[j] == A2[i]); j++)
        {
            A1[ind++] = tmp[j];
            visited[j] = 1;
        }
    }
    for(int j = 0; j < m; j++)
        if(visited[j] == 0)
            A1[ind++] = tmp[j];
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
    int A2[] = {2, 1, 8, 3};
    int m = sizeof A1/sizeof A1[0];
    int n = sizeof A2/sizeof A2[0];
    sortAccording(A1, A2, m, n);
    printArray(A1, m);
    return 0;
}
