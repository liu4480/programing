// Last Update:2018-02-28 15:20:03
/**
 * @file min-swaps.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-02-28
 */
#include <stdio.h>
#include <stdlib.h>

struct kv {
    int key;
    int value;
};

void swap_utils(int *a, int *b)
{
    printf("swapping %d and %d\n", *a, *b);
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int swap(int arr[], struct kv pairs[], int index_kv, int l, int h)
{
    if(l > h)
        return -2;
    if(((h - l + 1)& 1) == 1)
        return -1;
    
    int key_index = -1, value_index = -1, i;

    if (h - l == 1)
        return 0;

    for(i = l; i <= h; i++)
    {
        if(arr[i] == pairs[index_kv].key)
            key_index = i;
        if(arr[i] == pairs[index_kv].value)
            value_index = i;
    }
    printf("key:arr[%d]=%d, value:arr[%d]=%d\n", key_index, arr[key_index], value_index, arr[value_index]);
    if(key_index%2 == 1)
        key_index -= 1;
    else
        key_index += 1;
    swap_utils(&arr[key_index], &arr[value_index]);
    return swap(arr, pairs, index_kv + 1, l + 2, h) + 1;
}
int main()
{
   int array[] = {3,5,6,4,2,1};
   struct kv pairs[] = {{3,1}, {5,4}, {6,2}};

   int len = sizeof(array)/sizeof(array[0]); 
   int minswap,counter;
   printf("\nArray is: [ ");
   for (counter = 0;counter < len; counter++)
   {
      printf("%d ",array[counter]);
   }
   printf ("]\n\nPairs:\n");
   for (counter = 0;counter < len/2; counter++)
   {
      printf("%d <-> %d\n", pairs[counter].key, pairs[counter].value);
   }
   minswap = swap(array,pairs,0,0,len-1); 

   printf ("\nMinimum swap required = %d\n\nnew array: [ ",minswap);
   for (counter = 0;counter < len; counter++)
   {
      printf("%d ",array[counter]);
   }
   printf("]\n\n");

   return 0;

}
