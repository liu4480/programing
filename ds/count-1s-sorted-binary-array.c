// Last Update:2018-03-16 17:52:07
/**
 * @file count-1s-sorted-binary-array.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-16
 */
#include <stdio.h>
#include <stdbool.h>
int countOnes(bool arr[], int l, int r)
{
    if(r > l)
    {
        int mid = l + (r - l)/2;
        if((r == mid || arr[mid + 1] == 0) &&(arr[mid] == 1))
            return mid;
        else if(arr[mid] == 1)
            return countOnes(arr, mid + 1, r);
        return countOnes(arr, l, mid - 1);
    }
    return -1;
}

int main()
{
    bool arr[] = {1, 1, 1, 1, 0, 0, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Count of 1's in given array is %d.\n",countOnes(arr, 0, n-1));
    return 0;
}
