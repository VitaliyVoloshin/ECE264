#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef TEST_DIV
void divide(CardDeck orig_deck, CardDeck * upper_deck, CardDeck * lower_deck)
{
	// Dividing the decks into lower and upper decks
	for(int i=0, i < (orig_deck.size - 1); i++)
	{
		// Copy cards into upper and lower decks from original
		strncpy((upper_deck[i])->cards, orig_deck.cards, i+1);
		strncpy((lower_deck[i])->cards, orig_deck.cards+(i+1), orig_deck.size-i-1);

		// Update the size of the upper and lower decks
		upper_deck[i]->size = i+1;
		lower_deck[i]->size = orig_deck.size-i-1;
	}
}
#endif

#ifdef TEST_INTER
void interleave(CardDeck upper_deck, CardDeck lower_deck)
{
	// Check that upper deck !empty
	if (upper_deck.size == 0)

	// Check that lower deck !empty
	
	// Pick from upper deck
	
	// Update and call recursively
	
	// Pick from lower deck
	
	// Update and call recursively
   
	
	// Follow instructions in the README, to understand the working of the recursive function.
    // Use print_deck(…) to print each resulting order.
    // Tip: There should be no uncertainty in this function.
        // If you think a random number generator is needed, you are on the wrong track.
    // Tip: To copy the elements of one array from one array to another (e.g., the array of cards in a CardDeck),
        //you could use memcpy(…).
        //The = operator will simply copy the address, not the elements themselves.
}
#endif

#ifdef TEST_SHUF
void shuffle(CardDeck orig_deck)
{
    // Declare a variable to hold the number of pairs
	int number_pairs = orig_deck->size - 1;
	if(number_pairs == 0) return EXIT_FAILURE;

	// Instantiate pointers to hold both upper and lower decks (after division)
	CardDeck * upper_deck = NULL;
	CardDeck * lower_deck = NULL;

	// allocate memory based on number of pairs
	upper_deck = malloc(numpairs*sizeof(CardDeck));
	lower_deck = malloc(numpairs*sizeof(CardDeck));

	// Call divideDeck to fill upper_deck and lower_deck
	divide(orig_deck, upper_deck, lower_deck);

	// Run a loop through all the pairs and call interleave for each
	for(int i = 0; i < number_pairs; i++) {  interleave(upper_deck[i], lower_deck[i]);  }
	
	// Free memory allocated to upper and lower decks
	free(upper_deck);
	free(lower_deck);
}
#endif
