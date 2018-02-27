// Last Update:2018-02-26 14:14:04
/**
 * @file segregate-0-and-1.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-02-26
 */
#include <stdio.h>

void segregate0and1(int arr[], int n)
{
    int left = 0, right = n - 1;
    while(left < right)
    {
        while(arr[left] == 0 && left < right)
            left++;
        while(arr[right] == 1 && left < right)
            right--;

        if(left < right)
        {
            arr[left] = 0;
            arr[right] = 1;
            left++;
            right--;
        }
    }
}

int main()
{
    int arr[] = {0, 1, 0, 1, 1};
    int i, n = sizeof arr/ sizeof arr[0];
    segregate0and1(arr, n);

    printf("Array after segregation ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
