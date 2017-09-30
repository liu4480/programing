/*************************************************************************
    > File Name: test.c
    > Author: bin liu
    > Mail: bliu@suse.com 
    > Created Time: Tue 06 Sep 2016 10:53:15 AM CST
	there are M nodes in a ring, you have start from node 0, after n steps,
	how many routines can you go back to node 0.
 ************************************************************************/

#include<stdio.h>

int cal(int pos, int step, int nodes)
{
	if(pos != 0 && step==0)
		return 0;
	if(pos==0 && step==1)
		return 0;
	if(pos == 0 && step == 0)
	{
	    printf("%d\t%d\t%d\n",pos,step,nodes);
		return 1;
	}
	printf("%d\t%d\t%d\n",pos,step,nodes);
	return cal((pos-1+nodes)%nodes,step-1, nodes) + cal((pos+1)%nodes, step-1, nodes);
}

void main()
{
    int num = cal(0,1,3);
	printf("%d\n", num);
}
