// ***
// *** You MUST modify this file, only the ssort function
// ***

#include "sort.h"
#include <stdio.h>
#include <stdbool.h>

static bool checkOrder(int * arr, int size)
// a static function is visible only in this file
// This function returns true if the array elements are
// in the ascending order.
// false, otherwise
{
  int ind;
  for (ind = 0; ind < (size - 1); ind ++)
    {
      if (arr[ind] > arr[ind + 1])
	{
	  return false;
	}
    }
  return true;
}

#ifdef TEST_SORT
void ssort(int * arr, int size)
{
  // This function has two levels of for
  // The first level specifies which element in the array
  // The second level finds the smallest element among the unsorted
  // elements

  // After finding the smallest element among the unsorted elements,
  // swap it with the element of the index from the first level
  
  // call checkOrder to see whether this function correctly sorts the
  // elements
  
  int ind;
  int sub_ind;
  int tmp = 0;

  for (ind=0; ind < size; ++ind)
  	{
	  sub_ind = ind;
	  for (sub_ind=ind+1; sub_ind<size; ++sub_ind)
	  {
	    int next = arr[sub_ind];
		int current = arr[ind];

		char current_len[100];
		char next_len[100];
		sprintf(current_len,"%d",current);
		sprintf(next_len,"%d",next); 
		int cl = 0;
		int nl = 0;
		for (cl=0;current_len[cl]!='\n';++cl);
		for (nl=0;next_len[nl]!='\n';++nl);
		/*
		if (cl==nl)
		{ 
		  if (current > next)
		  {
		    tmp = arr[sub_ind];
		    arr[sub_ind] = arr[ind];
		    arr[ind] = tmp;
		  }
		}*/
		if (cl > nl)
		{
			tmp = arr[sub_ind];
			arr[sub_ind] = arr[ind];
			arr[ind] = tmp;
		}
	  }
	}

  if (checkOrder(arr, size) == false)
    {
      fprintf(stderr, "checkOrder returns false\n");
    }
}
#endif
