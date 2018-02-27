// Last Update:2018-03-01 10:47:17
/**
 * @file find-largest-3-ele.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-01
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define INT_MIN -100000

void printLargest(int arr[], int n)
{
    int first = INT_MIN, second = INT_MIN, third = INT_MIN;

    int i, x;
    for(i = 0; i < n; i++)
    {
        x = arr[i];
        if(x > first)
        {
            third = second;
            second = first;
            first = x;
        }
        else if(x > second)
        {
            third = second;
            second = x;
        }
        else if(x > third)
        {
            third = x;
        }
    }
    printf("largest 3 elements: %d %d %d\n", first, second, third);
}

int main()
{
    int arr[] = {12, 13, 1, 10, 34, 1};
    int n = sizeof arr/sizeof arr[0];
    printLargest(arr, n);
    return 0;
}
