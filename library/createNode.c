#include<stdio.h>
#include<stdlib.h>
#include"nodeStruct.h"
int i;
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
	
	for( i=0;i<=99;i++)
	{
		newNode->data[i]=data[i];
	}
	
	//newNode->data=data;
	printf("LinkedList data is : %s \n", newNode->data );
	newNode->link=NULL;
	return newNode;
}

