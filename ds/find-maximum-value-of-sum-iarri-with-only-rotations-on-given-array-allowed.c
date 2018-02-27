// Last Update:2018-02-23 10:44:45
/**
 * @brief 
 * @author bliu@suse.com
 * @date 2018-02-23
 * Let us calculate initial value of i*arr[i] with no rotation
 * R0 = 0*arr[0] + 1*arr[1] +...+ (n-1)*arr[n-1]
 *
 * After 1 rotation arr[n-1], becomes first element of array, 
 * arr[0] becomes second element, arr[1] becomes third element
 * and so on.
 * R1 = 0*arr[n-1] + 1*arr[0] +...+ (n-1)*arr[n-2]
 * R1 - R0 = arr[0] + arr[1] + ... + arr[n-2] - (n-1)*arr[n-1]
 * After 2 rotations arr[n-2], becomes first element of array, 
 * arr[n-1] becomes second element, arr[0] becomes third element
 * and so on.
 * R2 = 0*arr[n-2] + 1*arr[n-1] +...+ (n?1)*arr[n-3]
 * R2 - R1 = arr[0] + arr[1] + ... + arr[n-3] - (n-1)*arr[n-2] + arr[n-1]
 *
 * If we take a closer look at above values, we can observe 
 * below pattern
 *
 *Rj - Rj-1 = arrSum - n * arr[n-j]
 *
 *Where arrSum is sum of all array elements, i.e., 
 * arrSum = ∑ arr[i]
 *         i<=0<=n-1 
 */
#include <stdio.h>
int maxSum(int arr[], int n)
{
    int arrSum = 0;
    int currVal = 0;
    int rotations = 0;
    for(int i = 0; i < n; i++)
    {
        arrSum = arrSum + arr[i];
        currVal = currVal + (i *arr[i]);
    }

    int maxVal = currVal;
    for(int j = 1; j < n; j++)
    {
        currVal = currVal + arrSum - n * arr[n - j];
        if(currVal > maxVal) {
            maxVal = currVal;
            rotations = j;
        }
    }
    printf("we got max value after %d rotations.\n", rotations);
    return maxVal;
}

int main(void)
{
    int arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof arr/sizeof arr[0];
    printf("Max sum is %d\n", maxSum(arr, n));
    return 0;
}
