#ifndef CARD_H_
#define CARD_H_

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int CARD_DECK_SIZE = 52;
const int RANK_MAX = 13;
const int SUIT_MAX = 4;

/********************************************************************************
* BASE CLASS - Card
********************************************************************************/
class Card
{
	private:
		string rank[RANK_MAX];
		string suit[SUIT_MAX];

	public:
		void setRank(string x, int currentRank)
		{
			rank[currentRank] = x;
		}

		void setSuit(string x, int currentSuit)
		{
			suit[currentSuit] = x;
		}

		//CONSTRUCTOR
		Card() //sets all elements in both arrays to "none"
		{
			int i;

			for(i = 0; i < RANK_MAX; i++)
			{
				setRank("none", i);
			}

			for(i = 0; i < SUIT_MAX; i++)
			{
				setSuit("none", i);
			}
		}

		//CONSTRUCTOR
		Card(string rank[], string suit[]) //initializing
		{
			setRank("Ace", 0);
			setRank("2", 1);
			setRank("3", 2);
			setRank("4", 3);
			setRank("5", 4);
			setRank("6", 5);
			setRank("7", 6);
			setRank("8", 7);
			setRank("9", 8);
			setRank("10", 9);
			setRank("Jack", 10);
			setRank("Queen", 11);
			setRank("King", 12);

			setSuit("Hearts", 0);
			setSuit("Diamonds", 1);
			setSuit("Clubs", 2);
			setSuit("Spades", 3);
		}

		//PRINT FUNCTION
		string print(int rankNum, int suitNum)
		{
			string printOutput;

			printOutput = rank[rankNum] + " of " + suit[suitNum]; //output: Ace of Spades

			return printOutput;
		}

		//DECONSTRUCTOR
		virtual ~Card(void)
		{
			cout << "OBJECT IS PRINTING." << endl;
		}
};


/********************************************************************************
* DERIVED CLASS - DECKOFCARDS
********************************************************************************/
class DeckOfCards : public Card
{
	private:
		string deck[CARD_DECK_SIZE];
		int currentCard;

	public:


		void printDeck(int rankNum, int suitNum)
		{
			for(int count = 0; count < CARD_DECK_SIZE; count++)
			{
				deck[count] = print(rankNum, suitNum);
				cout << deck[count] << endl;
			}
		}
		
		//CONSTRUCTOR
		DeckOfCards() //initializing
		{
			deck[CARD_DECK_SIZE] = { NULL };
			currentCard = 0;
		}
		
		void shuffle()
		{
			currentCard = 0;
			
			for(int first = 0; first < CARD_DECK_SIZE; first++)
			{
				//perfect shuffle here
			}
		}

};



#endif /* CARD_H_ */
