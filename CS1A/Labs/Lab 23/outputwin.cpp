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
 * FUNCTION OutputWin
 * ____________________________________________________________________________
 * This function outputs the user's name, and if the user won or lost after
 * each round.
 * It returns nothing.
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 		name    : name of the user
 * 		userWin : if the user won or not
 *
 * POST-CONDITIONS
 * 		This function outputs the user's name, and if the user won or lost after
 * 		each round.
 *****************************************************************************/

void OutputWin(string name, // name of the user
			   bool userWin)// if the user won
{
	// PROCESSING - This will output if the user won or lost

	if (userWin)
	{
		cout << name << " WINS!!";
		cout << endl << endl << endl;
	}
	else
	{
		cout << "Computer wins, better luck next time, " << name << "!";
		cout << endl << endl << endl;
	}

}
