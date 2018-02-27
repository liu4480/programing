// Last Update:2018-03-02 15:36:55
/**
 * @file find-zeroes-to-be-flipped-so-that-number-of-consecutive-1s-is-maximized.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-02
 */

#include <bits/stdc++.h>
using namespace std;

void findZeroes(int arr[], int n, int m)
{
    int wL = 0, wR = 0;
    int bestL = 0, bestWindow = 0;

    int zeroCount = 0;
    while(wR < n)
    {
        if(zeroCount <= m)
        {
            if(arr[wR] == 0)
                zeroCount++;
            wR++;
        }

        if(zeroCount > m)
        {
            if(arr[wL] == 0)
                zeroCount--;
            wL++;
        }
        if(wR - wL > bestWindow)
        {
            bestWindow = wR - wL;
            bestL = wL;
        }
    }
    for(int i = 0; i < bestWindow; i++)
        if(arr[bestL + i] == 0)
            cout << bestL + i << " ";
    cout << endl;
}

int main()
{
   int arr[] = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1};
   int m = 2;
   int n =  sizeof(arr)/sizeof(arr[0]);
   cout << "Indexes of zeroes to be flipped are ";
   findZeroes(arr, n, m);
   return 0;
}
