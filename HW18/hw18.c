#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hw18.h"

void PrintAnswer(ListNode* head, ListNode* min1, ListNode* min2)
{
	ListNode* temp = head;
	int i;
	while(temp!=NULL)
	{
		i = 0;
		while(i < head -> treenode->dimension)
		{
			if(i == 0)
				printf("(%d, ", temp->treenode->data[i]);
			else if(i == head -> treenode->dimension-1)
				printf("%d)\n", temp->treenode->data[i]);
			else
				printf("%d, ", temp->treenode->data[i]);
			i+=1;
		}
		temp = temp->next;
	}
	i = 0;
	while(i < head -> treenode->dimension)
	{
		if(i == 0)
			printf("(%d, ", min1->treenode->data[i]);
		else if(i == head -> treenode->dimension-1)
			printf("%d) <-> ", min1->treenode->data[i]);
		else
			printf("%d, ", min1->treenode->data[i]);
		i+=1;
	}

	i = 0;
	while(i < head -> treenode->dimension)
	{
		if(i == 0)
			printf("(%d, ", min2->treenode->data[i]);
		else if(i == head -> treenode->dimension-1)
			printf("%d)\n", min2->treenode->data[i]);
		else
			printf("%d, ", min2->treenode->data[i]);
		i+=1;
	}
}

#ifdef TEST_MIN
void FindMin(ListNode* head)
{
	// Find pair of ListNodes with least distance between them
    int minDis = 0;
    int tmpDis = 0;
    int i = 0;
    ListNode * tmp1 = head;
    ListNode * tmp2 = NULL;
    ListNode * minNode1 = NULL;
    ListNode * minNode2 = NULL;
	while(tmp1->next != NULL)
    {
        tmp2 = tmp1->next;
        if(tmp2->next == NULL)
        {
            tmpDis = FindDist(tmp1->treenode,tmp2->treenode);
            if(tmpDis < minDis)
            {  
                minNode1 = tmp1;
                minNode2 = tmp2;
                minDis = tmpDis;
            }
            break;
        }
        while(tmp2->next != NULL)
        {
            tmpDis = FindDist(tmp1->treenode,tmp2->treenode);
            if(tmpDis < minDis)
            {  
                minNode1 = tmp1;
                minNode2 = tmp2;
                minDis = tmpDis;
            }
            tmp2=tmp2->next;
        }
        tmp1 = tmp1->next;
    }
    
	// Call print function
    tmp1 = minNode1;
    tmp2 = minNode2;
    while(i<head->treenode->dimension)
    {
        if(minNode1->treenode->data[i] < minNode2->treenode->data[i])
        {  PrintAnswer(head, minNode2, minNode1); return;  }
        else if(minNode1->treenode->data[i] > minNode2->treenode->data[i])
        {  PrintAnswer(head, minNode1, minNode2); return;  }
        else i++;
    }
    return;
}
#endif

#ifdef TEST_DIST
int FindDist(TreeNode* x, TreeNode* y)
{
	// Find the eucledian distance between x->data and y->data
    int distance = 0;
    for(int i=0; i<x->dimension; i++)
    {  distance+=(x->data[i]-y->data[i])*(x->data[i]-y->data[i]);  }
	return (int)distance;
}
#endif

#ifdef TEST_CREATENODE
ListNode * CreateNode(int n, int dim, int* arr)
{
	ListNode * newLNode = malloc(sizeof(ListNode));
	TreeNode * newTNode = malloc(sizeof(TreeNode));
	newTNode->dimension = dim;
	newTNode->left = NULL;
	newTNode->right = NULL;
	newTNode->data = malloc(sizeof(int)*(dim));
	for(int i=0; i<newTNode->dimension; i++)
    {  memcpy(&newTNode->data[i], &arr[i], 1);  }
	newLNode->treenode = newTNode;
	return newLNode;
}
#endif

#ifdef TEST_LINKEDLISTCREATE
// Fill an array with count integers from a file
void fillArray(int * arr, int count, FILE * fptr)
{
    int ind=0;
    while(ind<count)
    {
        if(fscanf(fptr,"%d",&arr[ind]) != 1)
        {  fclose(fptr); free(arr);  }
        ind++;
    }
}
void LinkedListCreate(ListNode ** head, int n, int dim, FILE * fptr)
{
	// malloc an array of length dim
	int * arr = malloc(sizeof(int)*(dim));
	if(arr==NULL) {  printf("ERROR: LinkedListCreate\n"); return;  }

	int i=0;
	while(i<n)
	{
		fillArray(arr,dim,fptr);
		ListNode * newLNode = CreateNode(n,dim,arr);
		newLNode->next = *head;
		*head = newLNode;
		i+=1;
	}
	fclose(fptr);
}
#endif
