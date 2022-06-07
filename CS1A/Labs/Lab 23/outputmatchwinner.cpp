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
 * FUNCTION OutputMatchWinner
 * ____________________________________________________________________________
 * This function outputs the user's name and the percentage of wins or losses
 * for the player. It returns nothing.
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 		name        : name of the user
 * 		percentWon  : percentage of user wins
 * 		percentLost : percentage of user loses
 *
 * POST-CONDITIONS
 * 		This function prompts the user for their name and the number of rounds
 * 		in the match they want to play.
 *****************************************************************************/

void OutputMatchWinner(string name, // OUT - name of the user
					   double percentWon, // OUT - percentage of user wins
					   double percentLost)// OUT - percentage of user loses

{
	cout << "***********************************" << endl;
	cout << "********** FINAL RESULTS **********" << endl;
	cout << "***********************************" << endl << endl;

	// PROCESSING - This will  output if the user won or lost and the
	//				percentage they won or lost
	if(percentWon>percentLost)
	{
		cout << name << " is the WINNER, WINNER, CHICKEN DINNER!!" << endl;
		cout << name << " won " << fixed<< setprecision(0) << percentWon
				     << "% of the time!";
	}
	else
	{
		cout << name << " LOST!!!!!!!!" << endl;
		cout << name << " lost " << fixed << setprecision(0) << percentLost
				     << "% of the time!";
	}

}
