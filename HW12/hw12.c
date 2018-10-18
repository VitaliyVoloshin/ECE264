/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include "hw12.h"

#ifdef LINKEDLIST
// Do not modify the below program, we are using ifdef block for
// ease of grading. Please include this flag in your Makefile
void LinkedListPrint(Node * head)
{
	Node *temp = head;
	while(temp!=NULL)
	{
		if(temp->next!=NULL) printf("%d,",temp->value);
		else printf("%d",temp->value);	
		temp=temp->next;
	}
	printf("\n");
}
#endif

/********** Do Not modify the file above this line, you should modify below ***********/
#ifdef TEST_CREATENODE
Node * CreateNode(int value)
{
	// Allocate memory for the new Node *
    Node * newNode = malloc(sizeof(Node));
    if(newNode == NULL) return NULL;
	
    // Create Node* with the value as 'value'
    newNode->value=value;

    // Return the newly created node
    return newNode;
}
#endif

#ifdef TEST_LINKEDLISTCREATE
// 1. head: the head of the singly linkedlist.
// 2. length: the length of the singly linkedlist.

// This function creates and initializes a singly linkedlist with length as 'length'(input argument),
// The values of the nodes within the singly linkedlist will be the same as array indddices.
// For example, if the singly linkedlist length is 4, the value of the nodes will be 0 1 2 3
void LinkedListCreate(Node * * head, int length)
{
	// Check if length is not negative
    if(length <0) return;

	// Create linked list of length as 'length'
    int n=0;
    while(n<length)
    {
        n=n+1;
        // where i left off, oct17,11pm
    }
	// do not return anything
}
#endif


#ifdef TEST_JOSEPHUS
// 1. head: the head of the singly linkedlist.
// 2. k : this variable will be used for counting if count = k, the element will be out.
// 3. elemDivisible : this variable will be used for printing. When the number of
//    remaining nodes in linked list is divisible by elemDivisible then you should 
//    print the remaining LinkedList with print functin provided to you.

// This function should solve the josephus problem using the singly linkedlist.

void Josephus(Node ** head, int k, int elemDivisible)
{
	// implement the algorithm here
	// remember to free the memory of the nodes
	// print the linked list using func when num nodes remaining div by elemDivisible
}
#endif
