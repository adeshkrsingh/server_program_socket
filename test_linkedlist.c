// A simple C program for traversal of a linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
  int data;
  struct Node* next;
} Node ;

void printList( Node *n)
{
  while (n != NULL)
  {
     printf(" %d ", n->data);
     n = n->next;
  }
}


create(Node* head) {
  head = NULL;
  head->data = "xyz";
  head->next = NULL;
}


void addNode( Node* head, char data[]) {
    Node* newNode = ( Node*)malloc(sizeof( Node));

  //   if(newNode==NULL)
	// {
	// 	printf("new node creation failed\n");
	// 	exit(1);
	// }
	newNode->data=data;
	// newNode->next=NULL;
  newNode->next = head;
  
  head = newNode;
}



int main()
{
     Node* head;
     create(head);
    addNode(head, "adesh");
  printList(head);
 
  return 0;
}