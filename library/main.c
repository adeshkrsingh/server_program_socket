#include<stdio.h>
#include<stdlib.h>
#include"nodeStruct.h"
#include"mylib.h"
node* head=NULL;
node* tail=NULL;
void main()
{
	node* newNode=createNode("sapna");
	head=addNode(&head,&tail,newNode);


	
	printf("%d",tail);
	newNode=createNode("sapna1");
	printf("aghj %s %s",head->data,tail->data );
	head=addNode(&head,&tail,newNode);

	newNode=createNode("sapna2");
	head=addNode(&head,&tail,newNode);

	newNode=createNode("sapna3");
	head=addNode(&head,&tail,newNode);
	printList(head);

}

