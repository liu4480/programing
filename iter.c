/*************************************************************************
    > File Name: iter.c
    > Author: bin liu
    > Mail: bliu@suse.com 
    > Created Time: Tue 06 Sep 2016 11:28:09 AM CST
 ************************************************************************/

#include<stdio.h>

void printArr(int *arr, int pos,int size,int eles)
{
	int i;
	if(pos == eles)
	{
        for(i=0;i<eles;i++)
			printf("%d\t", arr[i]);
	    printf("\n");
		return;
	}
	for(i=pos;i<size;++i)
	{
        int tmp = arr[pos];
		arr[pos] = arr[i];
		arr[i] = tmp;
		printArr(arr,pos+1,size,eles);
		arr[i] = arr[pos];
		arr[pos] = tmp;
	}
}

int main()
{
	int arr[] = {1,2,3,4};
	int pos=0;
	printArr(arr,pos,sizeof(arr)/sizeof(int),2);
	return 0;
}
