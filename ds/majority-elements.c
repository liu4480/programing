// Last Update:2018-03-12 13:01:56
/**
 * @file majority-elements.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-12
 */
#include <stdio.h>
#define bool int

int findCandidate(int *, int);
bool isMajority(int *, int, int);

void printMajority(int a[], int size)
{
    int cand = findCandidate(a, size);

    if (isMajority(a, size, cand))
        printf(" %d ", cand);
    else
        printf("No Majority Element");
}

int findCandidate(int a[], int size)
{
    int maj_index = 0, count = 1;
    int i;
    for(i = 1; i < size; i++)
    {
        if (a[maj_index] == a[i])
            count++;
        else
            count--;
        if (count == 0)
        {
            maj_index = i;
            count = 1;
        }
    }
    return a[maj_index];
}

bool isMajority(int a[], int size, int cand)
{
    int i, count = 0;
    for(i = 0; i < size; i++)
        if(a[i] == cand)
            count++;
    if(count > size/2)
        return 1;
    return 0;
}

int main()
{
    int a[] = {1, 3, 3, 1, 2, 1, 1};
    int size = sizeof a/sizeof a[0];
    printMajority(a, size);
    return 0;
}
