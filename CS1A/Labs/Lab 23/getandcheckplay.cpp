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
 * FUNCTION GetAndCheckPlay
 * ____________________________________________________________________________
 * This function receives a play from the user (rock, paper, or scissors), and
 * error-checks whether or not the user types in an invalid input.
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 		<none>
 *
 * POST-CONDITIONS
 * 		This function will output a menu for the user to choose the following:
 *
 * 		"*********************"
 *      "** CHOOSE YOUR PLAY **"
 *      "*********************"
 * 		"R - Rock"
 *		"P - Paper"
 *		"S - Scissors"
 *****************************************************************************/

char GetAndCheckPlay()
{

	char uPlay; // IN - the user's choice of rock, paper, or scissors

cout << "*********************"  << endl;
cout << "** CHOOSE YOUR PLAY **" << endl;
cout << "*********************"  << endl;
cout << "R - Rock"     << endl
	 << "P - Paper"    << endl
	 << "S - Scissors" << endl;

// PROCESSING - This will error check if the user entered the correct play
	do
	{

		cout << "Enter your play: ";
		cin.get(uPlay);
		cin.ignore(1000,'\n');
		
		cout << endl;

		uPlay = toupper(uPlay);

		if (!(uPlay == 'R' || uPlay == 'P' || uPlay == 'S'))
		{
			cout << "** INVALID INPUT - Please Enter (R, P, or S) **\n\n";
			cout << "R - Rock"     << endl
				 << "P - Paper"    << endl
				 << "S - Scissors" << endl;
		}



	}while(!(uPlay == 'R' || uPlay == 'P' || uPlay == 'S'));


	return uPlay;

}
