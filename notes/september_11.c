/******************************************************************************
 * FILENAME: 
 * WRITTEN BY:
 * LAST MODIFIED: 
 * ***************************************************************************/

/**************************************
 * FILE OPENING/CLOSING 
 * ***********************************/
FILE * fptr;
fptr = fopen(filename, "r"); 	// r = read, w = write, a = append
fclose(fptr); 					// Closing file

/**************************************
 * STREAM
 * ***********************************/

do {
	int ch;
	ch = fgetc(fptr);
	// ...
} while (ch != EOF);			// Will not work if char ch... needs int

/* OR */
while (!feof(fptr))
{
	// ...
}

/**************************************
 * ASCII to INT CONV.
 * ***********************************/
// ex1. reading char by char '1234'
// 1 = '1' - '0'
// ex2. using fscanf
int x;
fscanf(fptr, "%d", &x);
// x will be 1234 (number)


/**************************************
 * Heap Memory 
 * ***********************************/
char * ptr;
ptr = malloc(sizeof(char)*numElem);
// * 1. creates ptr in stack mem
// * 2. heap mem returns start value of address in heap
// * 3. ptr's value stores an address (heap)

// Alternate method
ptr = malloc(sizeof(*ptr)*numElem);




