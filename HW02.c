/******************************************************************************
 * Filename: 		  HW02.c
 * Course:			  ECE264
 * Written by:		Andrew St. Pierre
 * Last edited:		06-11-2018
 *****************************************************************************/

// includes
#include <stdio.h>
#include <stdlib.h>

// functions
void print_integer(int n, int radix)
{
	/****************************************************************
	*	Description:
	*		This funtion will convert an integer to a 
	*		number of the user's choice.
	*
	*	Inputs:
	*		int n			=>	the input integer
	*		int radix		=> 	the desired base
	*		char* prefix	=> 	optional character to print
	*							before the converted number
	****************************************************************/

	// private variables
	int quot1 = n;
	int quot2 = n;
	int remainder;
	int idx = 0;
	int idx2 = 0;
	char* buffer[idx];
	
	while(quot1 != 0)
	{
		quot1 = quot1 / radix;
		remainder = quot2 - (quot1*radix);
		quot2 = quot1;

		buffer[idx] = remainder;
		//tem = remainder;
		//fputc(buffer[idx],stdout);

		idx += 1;
	}

	idx2 = (idx-1);

	while(idx2 >= 0)
	{
		//tem = (buffer[idx2]);
		//fputc(tem, stdout);
		//char a = '4';

		//fputc(a,stdout);
		fputc(buffer[idx2],stdout);
		//printf("%c",buffer[idx2]);
		idx2 -= 1;
	}
	printf("\n");
}

// test bench
int main(int argc, char* argv[])
{
	print_integer(100,2);	// convert 11 to base 10
	print_integer(10,10);	// convert 10 to base 10
	print_integer(100000,9);	// convert 100000 to base 10


	return EXIT_SUCCESS;
}
