#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include "shuffle.h"

#ifdef TEST_MAIN
int main(int argc, char ** argv)
{
	char deck[MAX_SIZE] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
	
	// Check for missing inputs
	if(argc != 2) {  fprinf(stderr, "USAGE: please include the number of cards\n"); return EXIT_FAILURE;  }

	// Create a structure variable (corresponding to the original deck)
	CardDeck orig_deck;
	orig_deck.size = MAX_SIZE;
	orig_deck.cards = 0;

    	// Use memcpy(),
    	memcpy(orig_dec.cards, deck, MAX_SIZE*sizeof(orig_deck.cards[0]));
	
	// Read the number of cards from the terminal input
	orig_deck.size = strtol(argv[1], NULL, 10);

	// Call shufffle function
	shuffle(orig_deck);
    
	return EXIT_SUCCESS;
}
#endif

