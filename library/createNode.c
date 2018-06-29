#include<stdio.h>
#include<stdlib.h>
#include"nodeStruct.h"
void createLinkedList(node* newListInitialise)
{
	newListInitialise=NULL;
	return;
}
node* createNode(char data[])
{
	node * newNode=(node*)malloc(sizeof(node));
	if(newNode==NULL)
	{
		printf("new node creation failed\n");
		exit(1);
	}
	newNode->data=data;
	newNode->link=NULL;
	return newNode;
}

