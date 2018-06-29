#include<stdio.h>
#include<stdlib.h>
#include"nodeStruct.h"
//node* head=NULL;
//node* tail=NULL;

void printList(node* head)
{
	node* temp=head;
	while(temp!=NULL)
	{
		printf("%s\n",temp->data);
		temp=temp->link;	
	}
} 

