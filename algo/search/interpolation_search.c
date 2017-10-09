#include "search.h"

int interpolation_search(int arr[], int n, int x)
{
    int lo = 0, hi = n - 1;

    while(lo <= hi && x >= arr[lo] && x <= arr[hi])
    {
        int pos = lo + (((double)(hi - lo)/(arr[hi] - arr[lo])) * (x - arr[lo]));
        if(pos == x)
            return pos;

        if(arr[pos] < x)
            lo = pos + 1;
        else
            hi = pos - 1;
    }
    return -1;
}
