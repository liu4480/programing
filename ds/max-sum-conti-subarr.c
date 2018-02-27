// Last Update:2018-03-07 14:44:42
/**
 * @file max-sum-conti-subarr.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-07
 */
#include <iostream>
using namespace std;
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int maxSubArraySum(int a[], int size, int * left, int * right)
{
    int max_so_far = a[0];
    int curr_max = a[0];
    int l = 0;
    for(int i = 1; i < size; i++)
    {
        curr_max += a[i];
        if(curr_max < a[i])
        {
            curr_max = 0;
            l = i + 1;
        }
        if(max_so_far < curr_max)
        {
            max_so_far = curr_max;
            *left = l;
            *right = i;
        }
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof a/sizeof a[0];
    int left = 0, right = 0;
    int max_sum = maxSubArraySum(a, n, &left, &right);
    cout << "Maximum contiguous sum is " << max_sum << endl;
    cout << "starting index " << left << endl;
    cout << "ending index" << right << endl;
    return 0;
}
