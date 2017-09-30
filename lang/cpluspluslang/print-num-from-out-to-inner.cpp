#include <iostream>
using namespace std;

int main()
{
    int xbound=0, ybound=0;
    int M, N, v, i=0, j=0;
    cin >> M >> N;
    int **arr = new int*[M];
    for (i = 0; i < M; i++)
        arr[i] = new int[N];
    int row_s = 0, row_e = N - 1;
    int line_s = 0, line_e = M -1;

    for(v = 1;v <= M*N; )
    {
        if (((xbound % 2) == 0) && ((ybound % 2) == 0))
        {
            //go forward the line
            //and xbound + 1
            //only increase row start pos
            i = line_s;
            for(j = row_s; j <= row_e; j++)
            {
                arr[i][j] = v++;
            }
            line_s++;
            xbound++;
            if(line_s > line_e)
                break;
        }
        if (((xbound % 2) == 1) && ((ybound % 2) == 0))
        {
            //go down the row
            //and ybound + 1
            //only decrease row end pos
            j = row_e;
            for(i = line_s; i <= line_e; i++)
            {
                arr[i][j] = v++;
            }
            row_e--;
            ybound++;
            if(row_s > row_e)
                break;
        }
        if (((xbound % 2) == 1) && ((ybound % 2) == 1))
        {
            //go back the line
            //and xbound + 1
            //only decrease line end pos
            i = line_e;
            for(j = row_e; j >= row_s; j--)
            {
                arr[i][j] = v++;
            }
            xbound++;
            line_e--;
            if(line_s > line_e)
                break;
        }
        if (((xbound % 2) == 0) && ((ybound % 2) == 1))
        {
            //go up the row
            j = row_s;
            for(i = line_e; i >= line_s; i--)
            {
                arr[i][j] = v++;
            }
            row_s++;
            ybound++;
            if(row_s > row_e)
                break;
        }
    }

    for(i=0; i<M; i++)
    {
        for(j=0; j<N; j++)
            cout << arr[i][j] <<"\t";
        cout << endl;

    }
}
