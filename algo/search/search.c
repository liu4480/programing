#include "search.h"
extern int linear_search(int arr[], int n, int x); 
extern int binary_search(int arr[], int l, int r, int x); 
extern int jump_search(int arr[], int n, int x); 
extern int interpolation_search(int arr[], int n, int x); 
extern int exponential_search(int arr[], int n, int x); 
extern int ternary_search(int arr[], int l, int r, int x);
int main()
{
    int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89,
                144, 233, 377, 610};
    int n = sizeof(arr)/sizeof(arr[0]);

    int x = 55;

    int result = binary_search(arr, 0, n - 1, x);
    (result == -1) ? printf("Element is not present in array\n")
                   : printf("Element is present at index %d of array\n", result);

    result = jump_search(arr, n, x);
    (result == -1) ? printf("Element is not present in array\n")
                   : printf("Element is present at index %d of array\n", result);

    result = interpolation_search(arr, n, x);
    (result == -1) ? printf("Element is not present in array\n")
                   : printf("Element is present at index %d of array\n", result);

    result = exponential_search(arr, n, x);
    (result == -1)? printf("Element is not present in array")
                  : printf("Element is present at index %d of array\n", result);

    result = ternary_search(arr, 0, n-1, x);
    (result == -1)? printf("Element is not present in array")
                  : printf("Element is present at index %d of array\n", result);

    return 0;
}
