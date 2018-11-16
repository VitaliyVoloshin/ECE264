#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hw18.h"

#ifdef TEST_MAIN
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
  printf("n value: %d\n",n);

	// dim is the second element in the file
  int dim = 0;
  if(fscanf(fptr,"%d",&dim) != 1)
  {  fclose(fptr); return EXIT_FAILURE;  }
  printf("dim value: %d\n",dim);

  // Call LinkedListCreate
  ListNode * head = NULL;
  LinkedListCreate(&head, n, dim, fptr);

	// Call FindMin
  //FindMin(head);

  // Cleanup
  //fclose(fptr);
  return EXIT_SUCCESS;
}
#endif
