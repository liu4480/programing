// Last Update:2018-03-19 15:47:28
/**
 * @file magic-square.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-19
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void generateSqure(int n)
{
    int magicSquare[n][n];

    memset(magicSquare, 0, sizeof(magicSquare));

    int i = n / 2;
    int j = n - 1, num;

    for(num = 1; num <= n*n;)
    {
        if (i == -1 && j == n)
        {
            j = n - 2;
            i = 0;
        } else {
            if (j == n)
                j = 0;

            if (i < 0)
                i = n - 1;
        }

        if (magicSquare[i][j])
        {
            j -= 2;
            i++;
            continue;
        }
        else
            magicSquare[i][j] = num++;
        j++;i--;
    }

    printf("The magic Square for n=%d: sum of each row or column %d.\n\n", n, n*(n*n + 1)/2);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            printf("%3d ", magicSquare[i][j]);
        printf("\n");
    }
}

int main()
{
    int n = 7;
    generateSqure(n);
    return 0;
}
