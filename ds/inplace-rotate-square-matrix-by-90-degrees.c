// Last Update:2018-03-19 14:58:42
/**
 * @file inplace-rotate-square-matrix-by-90-degrees.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-19
 */
#include <bits/stdc++.h>
#define N 4
using namespace std;

void displayMatrix(int mat[N][N]);

void rotateMatrix(int mat[][N])
{
    for(int x = 0; x < N/2; x++)
    {
        for(int y = x; y < N - x - 1; y++)
        {
            int tmp = mat[x][y];
            mat[x][y] = mat[y][N-1-x];
            mat[y][N-1-x] = mat[N-1-x][N-1-y];
            mat[N-1-x][N-1-y] = mat[N-1-y][x];
            mat[N-1-y][x] = tmp;
        }
    }
}

void displayMatrix(int mat[N][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            printf("%2d ", mat[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int mat[N][N] = 
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    rotateMatrix(mat);
    displayMatrix(mat);
}
