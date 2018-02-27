// Last Update:2018-03-19 14:43:01
/**
 * @file rotate-marix.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-19
 */
#include <bits/stdc++.h>
using namespace std;

#define R 4
#define C 4

void rotateMatrix(int m, int n, int mat[R][C])
{
    int row = 0, col = 0;
    int prev, curr, i;

    while (row < m && col < n)
    {
        if (row + 1 == m || col + 1 == n)
            break;

        prev = mat[row+1][col];

        for(i = col; i < n; i++)
        {
            curr = mat[row][i];
            mat[row][i] = prev;
            prev = curr;
        }
        row++;

        for(i = row; i < m; i++)
        {
            curr = mat[i][n-1];
            mat[i][n-1] = prev;
            prev = curr;
        }
        n--;

        if(row < m)
        {
            for (i = n - 1; i >= col; i--)
            {
                curr = mat[m - 1][i];
                mat[m - 1][i] = prev;
                prev = curr;
            }
        }
        m--;

        if(col < n)
        {
            for (i = m - 1; i >= row; i--)
            {
                curr = mat[i][col];
                mat[i][col] = prev;
                prev = curr;
            }
        }
        col++;
    }

    for(i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
            cout << mat[i][j] << "\t";
        cout << endl;
    }
}

int main()
{
    int a[R][C] = {{1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 11, 12},
                   {13, 14, 15, 16}};
    rotateMatrix(R, C, a);
    return 0;
}
