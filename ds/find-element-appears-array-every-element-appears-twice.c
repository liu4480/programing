// Last Update:2018-03-19 13:47:20
/**
 * @file find-element-appears-array-every-element-appears-twice.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-19
 */
#include <iostream>
using namespace std;
 
int findSingle(int ar[], int ar_size)
{
     // Do XOR of all elements and return
     int res = ar[0];
     for (int i=1; i < ar_size; i++)
        res = res ^ ar[i];
 
     return res;
}
 
/* Diver function to test above function */
int main()
{
     int ar[] = {2, 3, 5, 4, 5, 3, 4};
     int n = sizeof(ar)/sizeof(ar[0]);
     cout << "Element occurring once is " << findSingle(ar, n) << endl;
     return 0;
}
