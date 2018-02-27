// Last Update:2018-03-12 15:09:57
/**
 * @file find-the-two-repeating-elements-in-a-given-array.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-12
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

int fact(int n)
{
    return (n == 0)? 1 : n * fact(n - 1);
}

void getRepeating(int arr[], int size)
{
    int S = 0, P = 1, x, y, D, n = size - 2, i;

    for(i = 0; i < size; i++)
    {
        S += arr[i];
        P *= arr[i];
    }

    S = S - n * (n + 1)/2;
    P = P/fact(n);
    D = sqrt(S*S - 4 * P);

    x = (D + S) / 2;
    y = (S - D) / 2;
    printf("The two Repeating elements are %d & %d\n", x, y);
}

void getRepeating2(int arr[], int size)
{
    int XOR = arr[0];
    int set_bit_no;
    int i;
    int n = size - 2;
    int x = 0, y = 0;

    for(i = 1; i < size; i++)
        XOR ^= arr[i];
    for(i = 1; i < size; i++)
        XOR ^= i;

    set_bit_no = XOR & ~(XOR - 1);

    for(i = 0; i < size; i++)
    {
        if (arr[i] & set_bit_no)
            x = x ^ arr[i];
        else
            y = y ^ arr[i];
    }

    for(i = 1; i <= n; i++)
    {
        if (i & set_bit_no)
            x = x ^ i;
        else
            y = y ^ i;
    }

    printf("\n The two repeating elements are %d & %d\n", x, y);
}

void getRepeating3(int arr[], int size)
{
    int i;
    printf("The two repeating elements are ");
    for(i = 0; i < size; i++)
    {
        if(arr[abs(arr[i])] > 0)
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        else
            printf(" %d ", abs(arr[i]));
    }
    printf("\n");
}

int main()
{
    int arr[] = {4, 2, 4, 5, 2, 3, 1};
    int size = sizeof arr/sizeof arr[0];
    getRepeating(arr, size);
    getRepeating2(arr, size);
    getRepeating3(arr, size);
    return 0;
}
