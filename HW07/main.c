//You must modify specific portions of this file
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#ifdef TEST_MERGE
/* The merge(arr, l, m, r) is key process that assumes that arr[l..m] and 
arr[m+1..r] are sorted and merges the two sorted sub-arrays into one. */
void merge(int arr[], int l, int m, int r) 
{
	// l = index of start of left sub array
	// r = index of right sub array = n-1
	// m =  endpoint of the left sub array = l+(r-l)/2
	
    int n1 = m - l + 1; 	// # elements in the left sub array
    int n2 =  r - m; 		// # elements in trhe right sub array
  
    // Create temporary arrays dynamically to help with sorting
    int *L=malloc(sizeof(* L) * n1); 
    int *R=malloc(sizeof(* R) * n2); 
    // NOTE:
    //	L[] is the left sub array
    //	R[] is the right sub array 
 
    // Initialise variables
	int i = 0;	
	int l_ind = 0;
	int r_ind = 0;

	// Copy data to temp arrays L[] and R[]
	for (i=0; i<n1; i++)
	{
		L[i] = arr[l+i];
	}
	for (i=0; i<n2; i++)
	{
		R[i] = arr[m+i+1];
	}

	i = l;
	while (i <= r)
	{
		// Even arrays
		if ((l_ind == n1) && (r_ind == n2))
		{	
			break;
		}
		// Odd arrays (R longer than L)
		else if (l_ind == n1)
		{
			arr[i] = R[r_ind];	
			break;
		}
		// Odd arrays (L longer than R)
		else if (r_ind == n2)
		{
			arr[i] = L[l_ind];	
			break;	
		}

		// Select the min of the two heads
		if (L[l_ind] <= R[r_ind])
		{
			arr[i] = L[l_ind];
			i++;
			if (l_ind < n1)
			{
				l_ind++;
			}
		}
		else if (R[r_ind] <= L[l_ind])
		{
			arr[i] = R[r_ind];
			i++;
			if (r_ind < n2)
			{
				r_ind++;
			}
		}
	}
 	// DO not modify below this line until specified in comments
}
#endif

/* Merge Sort uses recursion to call itself. Thus, efficiently dividing the array into two halves.
Then it must sort each half individually and finally join them back together using merge() into a single sorted array*/ 
#ifdef TEST_MERGESSORT
void mergeSort(int arr[], int l, int r) 
{
 	// int l defines the start index of the left sub array
    // int r defines the end index of the right sub array
    	
	// Variable declaration
	int m = l+(r-l)/2;
	int x = 0;
	
	// Recursion condition
	if (m > 1)
	{
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		//merge(arr,l,m,r);
	}
	else if (m == 1)
	{
		// Sort first half arr[l...m]
		if (arr[l] > arr[m])
		{
			x = arr[l];
			arr[l] = arr[m];
			arr[m] = x;
		}

		// Sort second half arr[m+1...r]
		if (arr[m+1] > arr[r])
		{
			x = arr[m+1];
			arr[m+1] = arr[r];
			arr[r] = x;
		}

		// Call merge() to arrange in order
		merge(arr, l, m, r);
		//break;
	}

	merge(arr,l,m,r); 
    
	// DO not modify below this line until specified in comments
	
} 
#endif


int main(int argc, char * * argv)
{
  	// read input file
  	if (argc != 3)
    {
      	fprintf(stderr, "need the name of input and output file\n");
      	return EXIT_FAILURE;
    }
  	// open file to read
  	FILE * fptr = fopen(argv[1], "r"); 
  	if (fptr == NULL)
    {
      	fprintf(stderr, "fopen fail\n");
      	// do not fclose (fptr) because fptr failed
      	return EXIT_FAILURE;
    }
  	// count the number of integers
  	int value;
  	int count = 0;
  	while (fscanf(fptr, "%d", & value) == 1)
    {
      	count ++;
    }
  	// allocate memory to store the numbers
  	int * arr = malloc(sizeof(int) * count);
  	if (arr == NULL) // malloc fail
    {
      	fprintf(stderr, "malloc fail\n");
      	fclose (fptr);
      	return EXIT_FAILURE;
    }
  	// return to the beginning of the file
 	fseek (fptr, 0, SEEK_SET);
  	int ind = 0;
  	while (ind < count)
    {
      	if (fscanf(fptr, "%d", & arr[ind]) != 1)
	{
	  	fprintf(stderr, "fscanf fail\n");
	  	fclose (fptr);
	  	free (arr);
	  	return EXIT_FAILURE;
	}
      	ind ++;
    }
  	fclose(fptr);

	#ifdef TEST_MERGESORT 
	// Call mergeSort for whole array
 	mergeSort(arr, 0, count-1); 
	#endif
  	
	//int i;
   	/* open the file for writing*/
  	FILE * fp = fopen(argv[2], "w"); 
  	if (fp == NULL)
    {
       	fprintf(stderr, "fopen fail\n");
    }
  	for (ind = 0; ind < count; ind ++)
    {
       	fprintf (fp,"%d\n", arr[ind]);
    }
 
  	free (arr);
  	return EXIT_SUCCESS;
}
