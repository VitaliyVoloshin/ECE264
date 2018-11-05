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
void LinkedListReverse(Node ** head)
{
    Node * prev = NULL;
    Node * current = *head;
    Node * next = NULL;
    while(current != NULL)
    {
        // Copy the next node
        next = current->next;
        // Reverse the current node's pointer
        current->next = prev;
        // Move pointers by 1 position
        prev = current;
        current = next;
    }
    *head = prev;
}

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
    // Variable declaration
    int ind=0;
    int tmp;

    // We are given a string corresponding to a file with input data
    // Lets open it
    FILE * finput = fopen(name,"r");

    // Check fail...
    if(finput==NULL) return;

    // Lets get a count of items in this file
    int count = countFromFile(name);

    // Lets create the LL by inserting each of these values one at a time
    while(ind<count)
    {
        if(fscanf(finput,"%d",&tmp) != 1) fclose(finput);
        LinkedListInsert(head,tmp);
        ind++;
    }
    LinkedListReverse(head);
}
#endif

#ifdef TEST_REMOVED
void DeleteNode(Node ** head, int ind)
{
    int idx=0;

    // If nothing in list, do nothing
    if(*head==NULL) return;

    // Store the head
    Node * temp = *head;

    // If the node we are looking for is at the very first node
    if(ind == 0)
    {
        // Update the head and free temp node
        *head = temp->next;
        free(temp);
        return;
    }

    // Traverse! Break when reach node right before target
    while(((temp->next) != NULL) && (idx < ind))
    {  temp = temp->next; idx++;  }

    // Check if we over-traversed...
    if((temp->next) == NULL) return;

    // Save the pointer to the next of the node to be deleted
    Node * newNext = temp->next->next;

    // Unlink the node from the LL
    free(temp->next);

    // Append the rest of the list using pointer to the next of deleted
    temp->next = newNext;
}
int LinkedListExists(Node * head, int val)
{
    Node * temp = head;
    while(temp != NULL)
    {
        if(temp->value == val) return 1;
        temp=temp->next;
    }
    return 0;
}
// This function will remove repetitions of a linked list value
void RemoveDuplicate(Node * headRef)
{
    // Declare some pointers
    Node * prevSeenHead = NULL;
    Node * tempHead = headRef;
    int ind = 0;

    while(tempHead != NULL)
    {
        if(LinkedListExists(prevSeenHead,tempHead->value))
        {  
            /* REMOVE THIS NODE */
            DeleteNode(&tempHead,ind);
            LinkedListPrint(tempHead);
            printf("\n");
            //tempHead = tempHead->next;
            ind++;
        }
        else
        {  
            LinkedListInsert(&prevSeenHead, tempHead->value);
            ind++;
            tempHead = tempHead->next;
        }   
    }

    // Print the linked list after all repetitions have been removed
    LinkedListPrint(tempHead);
}
#endif
