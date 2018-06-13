/******************************************************************************
 * Filename:		"testing.c"
 * Written by:		Andrew St. Pierre
 * Last modified:	June 12, 2018
 * Course:			ECE 264 Advanced C Programming
 * ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "solution.h"


void printArray(int * array, int len)
{
	printf("{");
	int ind;
	for(ind = 0; ind < len; ++ind)
		{
			printf("%d",array[ind]);
			if(ind != len - 1)
				{
					printf(", ");
				}
		}
	printf("}");

	printf("\n");
	//fflush(stdout);
}


void test_arraySum(int * array, int len, int expected)
{
	printArray(array,len);
	int sum = arraySum(array,len);
	printf("  sum = %d, expected = %d",sum,expected);
	if(sum != expected)
		{
			printf("FAIL");
		}
	printf("\n");
}


void test_00()
{
	printf("running test 00... ");
	int array1[] = {-4,-1,0,1,4,6,1,10};
	int len1 = 8;
	int expected1 = 17;
	test_arraySum(array1,len1,expected1);
	printf("\n");
}


int main(int argc, char * * argv)
{
	printf("\n");
	printf("welcome to ECE264, we are working on assignment 01. \n \n");
	test_00();

	return EXIT_SUCCESS;
}
