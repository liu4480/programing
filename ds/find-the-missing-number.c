// Last Update:2018-03-12 13:19:24
/**
 * @file find-the-missing-number.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-12
 */
#include <stdio.h>

int getMissingNo1(int arr[], int n)
{
    int i, total = (n + 1) * (n + 2) / 2;
    for(i = 0; i < n; i++)
        total -= arr[i];
    return total;
}

int getMissingNo2(int arr[], int n)
{
    int i, total = 0;
    for(i = 1; i <= n + 1; i++)
        total ^= i;
    for(i = 0; i < n; i++)
        total ^= arr[i];

    return total;
}

int main()
{
    int a[] = {1,2,4,5,6};
    int miss = getMissingNo1(a, 5);
    printf("%d\n", miss);
    miss = getMissingNo2(a, 5);
    printf("%d\n", miss);
    return 0;
}
