/*************************************************************************
    > File Name: getFirstCommonNode.c
    > Author: bin liu
    > Mail: bliu@suse.com 
    > Created Time: Tue 06 Sep 2016 12:48:28 PM CST
 ************************************************************************/

#include<stdio.h>

struct Node
{
	Node* next;
	int value;
};

struct List
{
	Node* head;
};

bool insertIntoList(List* l, Node* n)
{
	if(l == NULL)
		return False;
	Node* tmp = l->head;
	if(tmp==NULL)
	{
		l->head = n;
		n->next = NULL;
		return true;
	}
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = n;
	n->next = NULL;
	return true;
}

bool deleteFromList(List* l, Node* n)
{
	Node* tmp;
	if((l == NULL)||(l->head == NULL))
		return false;
	tmp = l->head;
	if(tmp == n)
	{
		head=head->next;
		free(n);
		return true;
	}
	while(tmp->next)
	{
		if(tmp->next == n)
		{
			tmp->next = n->next;
			free(n);
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

Node* initNode(int value)
{
    Node * tmp = malloc(sizeof(Node));
	if(tmp)
	{
        tmp->value = value;
    	tmp->next = NULL;
	}
	return tmp;
}

List* construct(int*arr, int size)
{
    List*l = malloc(sizeof(List));
	if(l==NULL)
		return NULL;
	for(int i=0;i<size;i++)
	{
		Node* tmp= initNode(arr[i]);
		if(tmp)
			insertIntoList(l,tmp);
	}
	return l;
}

void destruct(List*l)
{
	while(l->head)
		deleteFromList(l,l->head);
	free(l);
}


