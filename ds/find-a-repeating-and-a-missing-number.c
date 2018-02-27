// Last Update:2018-03-13 14:25:12
/**
 * @file find-a-repeating-and-a-missing-number.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-13
 */
#include<stdio.h>
#include<stdlib.h>
 
void printTwoElements(int arr[], int size)
{
    int i;
    printf("\n The repeating element is");
 
    for(i = 0; i < size; i++)
    {
        if(arr[abs(arr[i])-1] > 0)
            arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
        else
            printf(" %d ", abs(arr[i]));
    }
 
    printf("\nand the missing element is ");
    for(i=0; i<size; i++)
    {
        if(arr[i]>0)
            printf("%d.\n",i+1);
    }
}

void getTwoElements(int arr[], int n, int *x, int *y)
{
    /* Will hold xor of all elements and numbers 
       from 1 to n */
    int xor1; 
     
    /* Will have only single set bit of xor1 */
    int set_bit_no; 
     
    int i;
    *x = 0;
    *y = 0;
 
    xor1 = arr[0];
     
    /* Get the xor of all array elements */
    for(i = 1; i < n; i++)
        xor1 = xor1 ^ arr[i];
     
    /* XOR the previous result with numbers 
       from 1 to n*/
    for(i = 1; i <= n; i++)
        xor1 = xor1 ^ i;
     
    /* Get the rightmost set bit in set_bit_no */
    set_bit_no = xor1 & ~(xor1-1);
     
    /* Now divide elements in two sets by comparing 
    rightmost set bit of xor1 with bit at same 
    position in each element. Also, get XORs of two 
    sets. The two XORs are the output elements. The
    following two for loops serve the purpose */
    for(i = 0; i < n; i++)
    {
        if(arr[i] & set_bit_no)
        /* arr[i] belongs to first set */
        *x = *x ^ arr[i]; 
         
        else
        /* arr[i] belongs to second set*/
        *y = *y ^ arr[i]; 
    }
    for(i = 1; i <= n; i++)
    {
        if(i & set_bit_no)
        /* i belongs to first set */
        *x = *x ^ i; 
         
        else
        /* i belongs to second set*/
        *y = *y ^ i;
    }
 
/* *x and *y hold the desired output elements */
}
 
/* Driver program to test above function */
int main()
{
    int arr[] = {7, 3, 4, 5, 5, 6, 2};
    int  n = sizeof(arr)/sizeof(arr[0]);
    int x, y;
    printTwoElements(arr, n);
    getTwoElements(arr, n, &x, &y);
    printf("The missing element is %d and the repeating element is %d.\n", y, x);
    return 0;
}
