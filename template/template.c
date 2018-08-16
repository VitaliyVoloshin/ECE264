#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "template.h"

//main
int main(int argc, char ** argv)
{
	// argc = # of strings in argv
	// argv = input operands
	if (argc != 4)
	{
		fprintf(stderr, "argc is %d, not 4\n",argc);
		return EXIT_FAILURE;
	}

	long val1 = strtol(argv[1],NULL,10);
	long val2 = strtol(argv[2],NULL,10);

	long valresult = 0;
	bool valid = false;
	// determine which op to perform
	// If != A, it is an error
	if (strcmp(argv[3],"A")==0)
	{
		valresult = addop(val1,val2);
		valid = true;
	}

	if (valid == false) //unknown op given
	{
		fprintf(stderr, "unknown operation %s\n",argv[3]);
		return EXIT_FAILURE;
	}

	printf("THE RESULT IS %ld\n",valresult);
	return EXIT_SUCCESS;
}
