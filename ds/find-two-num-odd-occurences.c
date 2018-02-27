// Last Update:2018-03-16 13:56:47
/**
 * @file find-two-num-odd-occurences.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-16
 */
#include <stdio.h>

void printTwoOdd(int arr[], int size)
{
    int xor2 = arr[0];
    int set_bit_no;
    int i;
    int n = size - 2;
    int x = 0, y = 0;

    for(i = 1; i < size; i++)
        xor2 = xor2 ^ arr[i];

    set_bit_no = xor2 & ~(xor2 - 1);

    for(i = 0; i < size; i++)
    {
        if (arr[i] & set_bit_no)
            x = x ^ arr[i];
        else
            y = y ^ arr[i];
    }
    printf("The two odd elementsare %d and %d.\n", x, y);
}

int main()
{
    int arr[] = {4,2,4,5,2,3,3,1};
    int n = sizeof arr/sizeof arr[0];
    printTwoOdd(arr, n);
    return 0;
}
