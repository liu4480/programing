// Last Update:2018-03-12 14:28:43
/**
 * @file union-and-intersection.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-12
 */
/* For union of two arrays, follow the following merge procedure.
 * 1) Use two index variables i and j, initial values i = 0, j = 0
 * 2) If arr1[i] is smaller than arr2[j] then print arr1[i] and increment i.
 * 3) If arr1[i] is greater than arr2[j] then print arr2[j] and increment j.
 * 4) If both are same then print any of them and increment both i and j.
 * 5) Print remaining elements of the larger array.
 */
#include <stdio.h>
#include <stdlib.h>
void unionArr(int arr1[], int n1, int arr2[], int n2)
{
    int i=0, j=0;
    while(i < n1 && j < n2)
    {
        if(arr1[i] < arr2[j])
            printf("%d ", arr1[i++]);
        else if (arr1[i] > arr2[j])
            printf("%d ", arr2[j++]);
        else
        {
            printf("%d ", arr2[j++]);
            i++;
        }
    }
    while(i < n1)
        printf("%d ", arr1[i++]);
    while(j < n2)
        printf("%d ", arr2[j++]);
    printf("\n");
}
void intersection(int arr1[], int n1, int arr2[], int n2)
{
    int i = 0, j = 0;
    while(i < n1 && j < n2)
    {
        if(arr1[i] < arr2[j])
            i++;
        else if(arr1[i] > arr2[j])
            j++;
        else
        {
            printf("%d ", arr1[i++]);
            j++;
        }
    }
    printf("\n");
}

int main()
{
    int arr1[] = {1,2,4,5,6};
    int arr2[] = {2,3,5,7};
    int m = sizeof arr1/sizeof arr1[0];
    int n = sizeof arr2/sizeof arr2[0];
    unionArr(arr1, m, arr2, n);
    intersection(arr1, m, arr2, n);
    return 0;
}
