// Last Update:2018-03-12 13:13:20
/**
 * @file find-the-number-occurring-odd-number-of-times.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-12
 */
#include <stdio.h>

int getOddOccurrence(int ar[], int ar_size)
{
    int i;
    int res = 0;
    for(i = 0; i < ar_size; i++)
        res = res^ar[i];

    return res;
}

int main()
{
    int ar[] = {2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2};
    int n = sizeof ar/ sizeof ar[0];
    printf("%d\n", getOddOccurrence(ar, n));
    return 0;
}
