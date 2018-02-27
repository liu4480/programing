// Last Update:2018-02-23 15:32:49
/**
 * @file three-way-partition.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-02-23
 */
#include <iostream>
using namespace std;

void thereWayPartition(int arr[], int n,
                       int lowVal, int highVal)
{
    int start = 0, end = n - 1;

    for(int i = 0; i <= end;)
    {
        if(arr[i] < lowVal)
            swap(arr[i++], arr[start++]);
        else if (arr[i] > highVal)
            swap(arr[i], arr[end--]);
        else
            i++;
    }
}

int main()
{
    int arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87,
                98, 3, 1, 32};
    int n = sizeof arr/sizeof arr[0];
    thereWayPartition(arr, n, 10, 20);
    cout << "Modified array \n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
