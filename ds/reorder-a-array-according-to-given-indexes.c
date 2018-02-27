// Last Update:2018-02-27 18:02:55
/**
 * @file reorder-a-array-according-to-given-indexes.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-02-27
 */
#include <iostream>
using namespace std;

void recorder(int arr[], int index[], int n)
{
    for(int i = 0; i < n; i++)
    {
        while(index[i] != i)
        {
            int oldTargetI = index[index[i]];
            int oldTargetE = arr[index[i]];

            arr[index[i]] = arr[i];
            index[index[i]] = index[i];

            index[i] = oldTargetI;
            arr[i] = oldTargetE;
        }
    }
}

int main()
{
    int arr[] = {50, 40, 70, 60, 90};
    int index[] = {3, 0, 4, 1, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    recorder(arr, index, n);

    cout << "Reordered array is: \n";
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
         
    cout << "\nModified Index array is: \n";
    for (int i=0; i<n; i++)
        cout << index[i] << " ";
    cout << endl;
    return 0;
}
