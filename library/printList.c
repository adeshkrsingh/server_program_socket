#include<stdio.h>
#include<stdlib.h>
#include"nodeStruct.h"
//node* head=NULL;
//node* tail=NULL;

void printList(node* head)
{
	int counter = 0;
	node* temp=head;
	while(temp!=NULL)
	{
		printf("%s %d \n",temp->data, (counter++));
		temp=temp->link;
	}
} 

