// Last Update:2018-02-28 16:00:52
/**
 * @file min-swaps-2.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-02-28
 */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int rearrange(int arr[], int pair[], int size)
{
    int counter = 0, p_counter, tmp_swap, swaps = 0;
    for(counter = 0; counter < size; counter += 2)
    {
        if(arr[counter + 1] == pair[counter])
            continue;

        for(p_counter = counter + 2; p_counter < size; p_counter++)
            if(arr[p_counter] == pair[counter])
                break;
        if (p_counter == size)
        {
            printf("parter for %d (at index %d) not found\n", arr[counter], counter);
            exit(-1);
        }
        tmp_swap = arr[counter + 1];
        arr[counter + 1] = arr[p_counter];
        arr[p_counter] = tmp_swap;

        tmp_swap = pair[counter + 1];
        pair[counter + 1] = pair[p_counter];
        pair[p_counter] = tmp_swap;
        printf ("Swapped %d with %d\n",arr[counter+1],arr[p_counter]);
        swaps++;
    }
    return swaps;
}

int main()
{
   int array[] = {3,5,6,4,2,1};
   int pair[] = {1,4,2,5,6,3};

   int len = sizeof(array)/sizeof(int); 
   int minswap,counter;
   printf("\nArray is: [ ");
   for (counter = 0;counter < len; counter++)
   {
      printf("%d ",array[counter]);
   }
   printf ("]\n\nPairs:\n");
   for (counter = 0;counter < len; counter++)
   {
      printf("%d -> %d\n",array[counter],pair[counter]);
   }
   minswap = rearrange(array,pair,len); 

   printf ("\nMinimum swap required = %d\n\nnew array: [ ",minswap);
   for (counter = 0;counter < len; counter++)
   {
      printf("%d ",array[counter]);
   }
   printf("]\n\n");

   return 0;
}
