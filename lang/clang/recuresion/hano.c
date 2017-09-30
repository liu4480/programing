#include<stdio.h>

void hanoi(int n, int p1, int p2, int p3)
{
    if(n == 1)
        printf("move disk from %d to %d\n", p1, p3);
    else
    {
        //move n-1 disks to p2
        hanoi(n-1, p1, p3, p2);
        // move the largest disk from p1 to p3
        printf("move disk from %d to %d\n", p1, p3);
        //finally move the n-1 disks from p2 to p3
        hanoi(n-1, p2, p1, p3);
    }
}

int main()
{
    hanoi(3, 1, 2, 3);
}
