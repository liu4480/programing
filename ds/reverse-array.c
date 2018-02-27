// Last Update:2018-02-23 13:27:33
/**
 * @file reverse-array.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-02-23
 */

#include <stdio.h>

void reverse(int arr[], int start, int end)
{
    int tmp;
    while(start < end) {
        tmp = arr[start];
        arr[start++] = arr[end];
        arr[end--] = tmp;
    }
}

/* Utility that prints out an array on a line */
void printArray(int arr[], int size)
{
  int i;
  for (i=0; i < size; i++)
    printf("%d ", arr[i]);
 
  printf("\n");
} 
 
/* Driver function to test above functions */
int main() 
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    printArray(arr, 6);
    reverse(arr, 0, 5);
    printf("Reversed array is \n");
    printArray(arr, 6);    
    return 0;
}
