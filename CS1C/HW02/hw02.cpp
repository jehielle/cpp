 // ---------------------------------------------------------------------------
// File name: hw02.cpp                                                        -
// ----------------------------------------------------------------------------
// Creator's name and email: Jehielle David jdavid21@saddleback.edu           -
//-----------------------------------------------------------------------------

#include "card.h"

//MAIN
int main()
{
	DeckOfCards currentCard;
	int perfectShuffleNum = 0; //the number of perfect shuffles necessary to return to deck to its original configuration
	int suitNum = 0;		   //num of suits in a deck is 4
	int rankNum = 0;           //num of ranks/faces in a deck is 13

	//THE ARRAYS
	string rank[RANK_MAX];
	string suit[SUIT_MAX];
	DeckOfCards deck[CARD_DECK_SIZE]; //card deck size is 52

	cout << "-----------------------------"         << endl;
	cout << "    CS1C: PERFECT SHUFFLE    "         << endl;
	cout << "-----------------------------"         << endl;
	cout << ">PRINTING: "                           << endl;
	cout << "The initialized deck before shuffle: " << endl << endl;

	//INITIALIZE - the deck
	//deck is initialized by constructor

	//PRINT - deck before shuffle
	deck[CARD_DECK_SIZE].printDeck(rankNum, suitNum);
	cout << endl << endl;

	cout << ">PRINTING: "                                          << endl;
	cout << "The two half-decks after the first perfect shuffle: " << endl << endl;

	//SHUFFLE & PRINT - deck after first perfect shuffle
	deck[CARD_DECK_SIZE].shuffle();
	deck[CARD_DECK_SIZE].printDeck(rankNum, suitNum);
	cout << endl << endl;

	cout << ">PRINTING: "      << endl;
	cout << "The final deck: " << endl << endl;

	//SHUFFLE & PRINT - shuffles deck until it is back to its original configuration
	//final deck here
	cout << endl << endl;

	cout << ">PRINTING: "      << endl;
	cout << "How many perfect shuffles are necessary to return the deck to its original configuration: " << perfectShuffleNum;
	
	cout << endl;
	
	
	return 0;
}


