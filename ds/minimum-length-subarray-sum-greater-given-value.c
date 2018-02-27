// Last Update:2018-03-09 15:13:02
/**
 * @file minimum-length-subarray-sum-greater-given-value.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-09
 */
#include <iostream>
using namespace std;

int smallestSubWithSum(int arr[], int n, int x, int *s)
{
    int curr_sum = 0, min_len = n + 1;
    
    int start = 0, end = 0;
    while(end < n)
    {
        while(curr_sum <= x && end < n)
            curr_sum += arr[end++];

        while(curr_sum > x && start < n)
        {
            if(end - start < min_len)
            {
                *s = start;
                min_len = end - start;
            }

            curr_sum -= arr[start++];
        }
    }
    return min_len;
}

int main()
{
    int arr1[] = {1, 4, 45, 6, 10, 19};
    int x = 51, s1;
    int n1 = sizeof arr1/sizeof arr1[0];
    int res1 = smallestSubWithSum(arr1, n1, x, &s1);
    (res1 == n1 + 1)? cout << "Not possible" << endl:
                      cout << "start from: " << s1 << ",len: " << res1 << endl;

    int arr2[] = {1, 10, 5, 2, 7}, s2;
    int n2 = sizeof arr2/sizeof arr2[0];
    x = 9;
    int res2 = smallestSubWithSum(arr2, n2, x, &s2);
    (res2 == n2 + 1)? cout << "Not possible" << endl:
                      cout << "start from: " << s2 << ",len: " << res2 << endl;

    int arr3[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250}, s3;
    int n3 = sizeof arr3/sizeof arr3[0];
    x = 280;
    int res3 = smallestSubWithSum(arr3, n3, x, &s3);
    (res3 == n3 + 1)? cout << "Not possible" << endl:
                      cout << "start from: " << s3 << ",len: " << res3 << endl;
    return 0;
}
