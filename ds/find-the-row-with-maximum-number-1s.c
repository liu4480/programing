// Last Update:2018-03-19 16:00:56
/**
 * @file find-the-row-with-maximum-number-1s.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-19
 */
#include <stdio.h>
#include <stdbool.h>
#define R 4
#define C 4
 
// Function to find the index of first index
// of 1 in a boolean array arr[] 
int first(bool arr[], int low, int high)
{
    if(high >= low)
    {   
        // Get the middle index 
        int mid = low + (high - low)/2; 
 
        // Check if the element at middle index is first 1
        if ( ( mid == 0 || arr[mid-1] == 0) && arr[mid] == 1)
            return mid;
 
        // If the element is 0, recur for right side
        else if (arr[mid] == 0)
            return first(arr, (mid + 1), high);
     
        // If element is not first 1, recur for left side
        else
            return first(arr, low, (mid -1));
    }
    return -1;
}
int rowWithMax1s_(bool mat[R][C])
{
    // Initialize first row as row with max 1s
    int max_row_index = 0;
 
    // The function first() returns index of first 1 in row 0.
    // Use this index to initialize the index of leftmost 1 seen so far
    int j = first(mat[0], 0, C-1), i;
    if (j == -1) // if 1 is not present in first row
      j = C - 1;
 
    for (i = 1; i < R; i++)
    {
        // Move left until a 0 is found
        while (j >= 0 && mat[i][j] == 1)
        {
           j = j-1;  // Update the index of leftmost 1 seen so far
           max_row_index = i;  // Update max_row_index
        }
    }
    return max_row_index;
}
// Function that returns index of row
// with maximum number of 1s. 
int rowWithMax1s(bool mat[R][C])
{
    // Initialize max values
    int max_row_index = 0, max = -1; 
 
    // Traverse for each row and count number of 1s 
    // by finding the index of first 1
    int i, index;
    for (i = 0; i < R; i++)
    {
    index = first (mat[i], 0, C-1);
    if (index != -1 && C-index > max)
    {
        max = C - index;
        max_row_index = i;
    }
    }
 
    return max_row_index;
}
 
// Driver Code
int main()
{
    bool mat[R][C] = { {0, 0, 0, 1},
                       {0, 1, 1, 1},
                       {1, 1, 1, 1},
                       {0, 0, 0, 0}};
 
    printf("Index of row with maximum 1s is %d.\n"
                                , rowWithMax1s(mat));
 
    printf("Index of row with maximum 1s is %d.\n"
                                , rowWithMax1s_(mat));
    return 0;
}
