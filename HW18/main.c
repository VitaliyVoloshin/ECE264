#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hw18.h"

#ifdef TEST_MAIN
void cleanup(ListNode * head)
{
    if(head == NULL) return;
    ListNode * tmpNode = head;
    while(tmpNode->next != NULL)
    {
        free(tmpNode->treenode->data);
        free(tmpNode->treenode);
        head = tmpNode->next;
        cleanup(head);
        free(tmpNode);
    }
    return;
}
int main(int argc, char * * argv)
{
  // Check for input error
  if(argc != 2) return EXIT_FAILURE;

  // Open the file
  FILE * fptr = fopen(argv[1], "r");
  if(fptr==NULL) return EXIT_FAILURE;
  
  // n is the first element in the file
  int n = 0;
  if(fscanf(fptr,"%d",&n) != 1)
  {  fclose(fptr); return EXIT_FAILURE;  }

  // dim is the second element in the file
  int dim = 0;
  if(fscanf(fptr,"%d",&dim) != 1)
  {  fclose(fptr); return EXIT_FAILURE;  }

  // Call LinkedListCreate
  ListNode * head = NULL;
  LinkedListCreate(&head, n, dim, fptr);
  
  // Call FindMin
  FindMin(head);

  // Cleanup
  //cleanup(head);
  return EXIT_SUCCESS;
}
#endif
