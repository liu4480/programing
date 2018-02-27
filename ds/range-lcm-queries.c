// Last Update:2018-03-06 15:34:01
/**
 * @file range-lcm-queries.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-06
 */
#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int tree[4*MAX];

int arr[MAX];

int gcd(int a, int b)
{
    if(a == 0)
        return b;
    return gcd(b%a, a);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

void buid(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
        return;
    }

    //int mid = start + (end - start) / 2;
    int mid = (end + start) / 2;
    buid(2 * node, start, mid);
    buid(2 * node + 1, mid + 1, end);

    int left_lcm = tree[2 * node];
    int right_lcm = tree[2 * node + 1];

    tree[node] = lcm(left_lcm, right_lcm);
}

int query(int node, int start, int end, int l, int r)
{
    if (end < l || start > r)
        return l;

    if (l <= start && r >= end)
        return tree[node];

    //int mid = start + (end - start) / 2;
    int mid = (end + start) / 2;
    int left_lcm = query(2 * node, start, mid, l, r);
    int right_lcm = query(2 * node + 1, mid + 1, end, l, r);

    return lcm(left_lcm, right_lcm);
}

int main()
{
    //arr = {5, 7, 5, 2, 10, 12, 11, 17, 14, 1, 44};
    arr[0] = 5;
    arr[1] = 7;
    arr[2] = 5;
    arr[3] = 2;
    arr[4] = 10;
    arr[5] = 12;
    arr[6] = 11;
    arr[7] = 17;
    arr[8] = 14;
    arr[9] = 1;
    arr[10] = 44;
    buid(1, 0, 10);

    cout << query(1, 0, 10, 2, 5) << endl;
    cout << query(1, 0, 10, 5, 10) << endl;
    cout << query(1, 0, 10, 0, 10) << endl;
    return 0;
}
