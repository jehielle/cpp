/******************************************************************************
 * AUTHOR        : JJ David, Nina Brock
 * STUDENT ID    : 1083135, 378941
 * LAB #23       : Functions - Rock Paper Scissors
 * CLASS	     : CS1A
 * SECTION	     : TTh: 1pm
 * DUE DATE	     : 11/14/17
 *****************************************************************************/

#include "myheader.h"

/******************************************************************************
 * This program will allow the player to play Rock, Paper, Scissors. In this
 * version if there is a tie the computer wins. The user must beat the
 * computer to win a round.
 *****************************************************************************/

int main()
{

	srand(time(NULL));

    string userName;	// IN&OUT   - name of the player

    char userPlay;		// IN       - the user's choice of rock, paper, or
    					//            scissors
    char computerPlay;  // CALC     - the computer's choice of rock, paper, or
    					// 		      scissors

    bool outcome;		// CALC     - the outcome

    int numRounds;		// IN&OUT   - number of rounds in match
    int numOfWins;		// CALC     - counts the number of wins
    int numOfLoses;		// CALC     - counts the number of losses
    int count;			// CALC     - counts the number of rounds

    float percentLoses; // CALC&OUT - percentage of losses
    float percentWins;  // CALC&OUT - percentage of wins

    // OUTPUT - Print Header
	PrintHeader("Functions - Rock Paper Scissors", 23, 'L');


    numOfWins=0;
    numOfLoses=0;

    GetInput(userName, numRounds);

	// PROCESSING - This will allow the user to play multiple rounds
    for ( count = 1; count <= numRounds; count = count + 1 )
    {

      userPlay = GetAndCheckPlay();
      computerPlay = GetComputerPlay();
      OutputChoices(userPlay,computerPlay, userName);

      outcome = CheckWin(userPlay, computerPlay);
      OutputWin(userName, outcome);


      if (outcome)
      {
        numOfWins++;
      }
      else
      {
        numOfLoses++;
      }


    }


	// PROCESSING - This will calculate the percentage of wins and loses

    percentWins = (double(numOfWins)/numRounds)*100;
    percentLoses = (double(numOfLoses)/numRounds)*100;

    OutputMatchWinner(userName, percentWins, percentLoses);

    return 0;
  }
