#include<stdlib.h>
#include"nodeStruct.h"
//node* head=NULL;
//node* tail=NULL;
node* addNode(node* head,char data[])
{
	node* newNode=createNode(data);
	printf("\nnew node %s\n",data);
	if(head==NULL)
	{
		head=newNode;
		return head;
	}
	node* temp;
	temp=head;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	temp->link=newNode;
	
	return head;
}

