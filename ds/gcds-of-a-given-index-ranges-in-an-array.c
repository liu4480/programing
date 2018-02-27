// Last Update:2018-03-06 13:49:43
/**
 * @file gcds-of-a-given-index-ranges-in-an-array.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-06
 */
#include <bits/stdc++.h>
using namespace std;

int * st;

void swap(int & a, int & b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int gcd(int a, int b)
{
    if(a < b)
        swap(a, b);

    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int fingGcd(int ss, int se, int qs, int qe, int si)
{
    if (ss > qe || se < qs)
        return 0;
    if (qs <= ss && qe >= se)
        return st[si];

    int mid = ss + (se - ss) / 2;
    return gcd(fingGcd(ss, mid, qs, qe, si * 2 + 1),
               fingGcd(mid + 1, se, qs, qe, si * 2 + 2));
}

int fingRangeGcd(int ss, int se, int arr[], int n)
{
    if (ss < 0 || se > n - 1 || ss > se)
    {
        cout << "Invalid Aruments" << endl;
        return -1;
    }
    return fingGcd(0, n - 1, ss, se, 0);
}

int constructST(int arr[], int ss, int se, int si)
{
    if ( ss == se)
    {
        st[si] = arr[ss];
        return st[si];
    }
    int mid = ss + (se - ss) / 2;
    st[si] = gcd(constructST(arr, ss, mid, si * 2 + 1),
                 constructST(arr, mid + 1, se, si * 2 + 2));
    return st[si];
}

void constructSegmentTree(int arr[], int n)
{
    int height = (int)(ceil(log2(n)));
    int size = 2 * (int)pow(2, height) - 1;
    st = new int[size];
    constructST(arr, 0, n - 1, 0);
    //return st;
}

int main()
{
    int a[] = {2, 3, 6, 9, 5};
    int n = sizeof(a)/sizeof(a[0]);

    constructSegmentTree(a, n);

    int l = 1;

    int r = 3;
    cout << "GCD of given range is:";
    cout << fingRangeGcd(l, r, a, n) << endl;
}
