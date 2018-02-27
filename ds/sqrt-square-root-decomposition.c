// Last Update:2018-03-06 16:35:04
/**
 * @file sqrt-square-root-decomposition.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-06
 */
#include <iostream>
#include <math.h>
using namespace std;

#define MAXN 10000
#define SQRSIZE 100

int arr[MAXN];
int block[SQRSIZE];
int blk_sz;

void update(int idx, int val)
{
    int blockNumber = idx / blk_sz;
    block[blockNumber] += val - arr[idx];
    arr[idx] = val;
}

int query(int l, int r)
{
    int sum = 0;
    while (l < r && l % blk_sz != 0 && l != 0)
    {
        sum += arr[l];
        l++;
    }
    while (l + blk_sz <= r)
    {
        sum += block[l / blk_sz];
        l += blk_sz;
    }
    while (l <= r)
    {
        sum += arr[l];
        l++;
    }
    return sum;
}

void preprocess(int input[], int n)
{
    int blk_idx = -1;

    blk_sz = sqrt(n);

    for(int i = 0; i < n; i++)
    {
        arr[i] = input[i];
        if (i % blk_sz == 0)
            blk_idx++;

        block[blk_idx] += arr[i];
    }
}

int main()
{
    int input[] = {1,5,2,4,6,1,3,5,7,10};
    int n = sizeof(input)/sizeof(input[0]);
    preprocess(input, n);

    cout << "query(3, 8) : " << query(3, 8) << endl;
    cout << "query(1, 6) : " << query(1, 6) << endl;
    update(8, 0);
    cout << "query(8, 8) : " << query(3, 8) << endl;
}
