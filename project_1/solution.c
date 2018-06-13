/******************************************************************************
 * Filename:		"solution.c"
 * Written by:		Andrew St. Pierre
 * Last modified:	June 12, 2018
 * Course:			ECE264 Advanced C Programming
 * ***************************************************************************/

#include <stdlib.h>
#include "solution.h"

int arraySum(int * array, int len)
{
	int ind;
	int sum = 0;
	for (ind = 0; ind < len; ind ++)
		{
			sum += array[ind];
		}
	return sum;
}


