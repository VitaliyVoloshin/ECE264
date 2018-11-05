/****************** Modify this file at specified place ***********************/
#include <stdio.h>
#include <stdlib.h>
#include "hw15.h"

#ifdef LINKEDLIST
// Do not modify this function.
void LinkedListPrint(Node * head)
{
	Node *temp = head;
	while(temp!=NULL)
	{
		if(temp->next!=NULL)
		{  printf("%d,",temp->value);  }
		else
		{  printf("%d\n",temp->value);  }
		temp=temp->next;
	}
}
#endif

/********** Do Not modify the file above this line, you can modify below ******/
#ifdef TEST_CREATENODE
Node * CreateNode(int val)
{
    // Allocate mem for the new Node + check for mem fail
    Node * newNode = malloc(sizeof(Node));

    // Create Node with value "val"
    newNode->value = val;

    // Set next pointer to NULL
    newNode->next = NULL;

    // Return the newly created node
    return newNode;
}
#endif

#ifdef TEST_LINKEDLISTCREATE
int countFromFile(char * file_name)
{
    FILE * fptr = fopen(file_name, "r");
    if(fptr==NULL) return EXIT_FAILURE;
    int value=0,count=0;
    while(fscanf(fptr, "%d", &value)==1) count++;
    fclose(fptr);
    return count;
}

void LinkedListInsert(Node ** head, int v)
{
    Node * newNode = CreateNode(v);
    newNode->next = *head;
    *head = newNode;
}

void LinkedListCreate(Node ** head, char* name)
{
    // We are given a string corresponding to a file with input data
    // Lets open it
    FILE * finput = fopen(name,"r");

    // Check fail...
    if(finput==NULL) return EXIT_FAILURE;

    // Lets get a count of items in this file
    int count = countFromFile(name);

    // 

}
#endif

#ifdef TEST_REMOVED
void DeleteNode(Node ** head, int v)
{
    // If nothing in list, do nothing
    if(*head==NULL) return;

    // Store the head
    Node * temp = *head;

    // If the node we are looking for is at the very first node
    if((temp->value) == v)
    {
        // Update the head and free temp node
        *head = temp->next;
        free(temp);
        return;
    }

    // Traverse! Break when reach node right before target
    while(((temp->next) != NULL) && (((temp->next)->value) != v))
    {  temp = temp->next;  }

    // Check if we over-traversed...
    if((temp->next) == NULL) return;

    // Save the pointer to the next of the node to be deleted
    Node * newNext = temp->next->next;

    // Unlink the node from the LL
    free(temp->next);

    // Append the rest of the list using pointer to the next of deleted
    temp->next = newNext;
}

// This function will remove repetitions of a linked list value
void RemoveDuplicate(Node *headRef)
{
	/*
	This function will remove repetitions from the linked list referenced by headRef.
	Each time we check for a new Node in the linked list, we will check if it is distinct from
	the Nodes already present in the list ( upto the previous Node).
	So for each occurrence after its first, we will be deleting that node.
	To delete a node: we will map the next Node of the previous Node to the Node after the current Node.
	*/

    // Print the linked list after all repetitions have been removed
    LinkedListPrint(headRef);
}
#endif
