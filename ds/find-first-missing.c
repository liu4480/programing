// Last Update:2018-03-01 14:07:55
/**
 * @file find-first-missing.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-01
 */
#include <stdio.h>

int findFirstMissing(int arr[], int s, int e)
{
    if (s > e)
        return s + 1;
    if (s != arr[s])
        return s;
    int mid = s + (e - s) / 2;
    if (arr[mid] == mid)
        return findFirstMissing(arr, mid + 1, e);
    return findFirstMissing(arr, s, mid);
}

int main()
{
    int arr[] = {0,1,2,3,4,5,6,7, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Smallest missing element is %d\n",
           findFirstMissing(arr, 0, n-1));
    return 0;
}
