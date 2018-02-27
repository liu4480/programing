// Last Update:2018-02-26 14:20:53
/**
 * @file segregate-even-and-odd.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-02-26
 */
#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a= *b;
    *b= tmp;
}

void segregateEvenAndOdd(int arr[], int n)
{
    int left = 0, right = n - 1;
    while(left < right) {
        while(((arr[left] & 1) == 0) && (left < right)) left++;
        while(((arr[right] & 1) == 1) && (left < right)) right--;
        if(left < right)
        {
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }
}

int main()
{
    int arr[] = {12, 34, 45, 9, 8, 90, 3};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    int i = 0;
    segregateEvenAndOdd(arr, arr_size);

    printf("Array after segregation ");
    for(i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
