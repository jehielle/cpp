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
 * FUNCTION GetInput
 * ____________________________________________________________________________
 * This function receives the player's name, and number of rounds in match.
 * It returns nothing.
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 		<none>
 *
 * POST-CONDITIONS
 * 		This function prompts the user for their name and the number of rounds
 * 		in the match they want to play.
 *****************************************************************************/

void GetInput(string &name, // IN - name of the player
			  int &rounds)	// IN - number of rounds in match
{
	cout << "Enter Player's Name: ";
	getline(cin, name);

	cout << "Enter Number of Rounds in Match: ";
	cin  >> rounds;

	cout << endl;
	cin.ignore(1000, '\n');
}
