#include <iostream>

using namespace std;

void swap(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

void permute(int arr[], int pos, int num, int size)
{
    int i;
    if(pos == num)
    {
        for(i = 0; i < num; i++)
            cout << arr[i] << "\t";
        cout << endl;
        return;
    }
    for(i = pos; i < size; ++i)
    {
        swap(arr[i], arr[pos]);
        permute(arr, pos + 1, num, size);
        swap(arr[pos], arr[i]);
    }
}

int main()
{
    int size, i, j;//j is print number of int
    cin >> size >> j;
    int *arr = new int[size];
    for(i = 0; i < size; i++)
        arr[i] = i + 1;
    permute(arr, 0, j, size);
}
