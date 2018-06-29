#include<stdlib.h>
#include"nodeStruct.h"
//node* head=NULL;
//node* tail=NULL;
node* addNode(node** head,node** tail,node* newNode)
{
	if(*head==NULL)
	{
		*head=newNode;
		*tail=newNode;
	}
	else
	{
		(*tail)->link=newNode;
		*tail=newNode;	
	}
	printf("gjh %s %s",(*head)->data,(*tail)->data);
	return *head;
}

