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
 * FUNCTION CheckWin
 * ____________________________________________________________________________
 * This function checks if the user has won, returns true if they won or
 * false if the computer won.
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 		uPlay : play of the user (R, P, or S)
 * 		cPlay : play of the computer (R, P, or S)
 *
 * POST-CONDITIONS
 * 		This function returns true or false depending on whether or not the
 * 		user won.
 *****************************************************************************/

bool CheckWin(char uPlay, // play of the user (R, P, or S)
			  char cPlay) // play of the computer (R, P, or S)
{
	bool userWin;

	// PROCESSING - This will see if the user won or lost
	userWin = ((uPlay == 'S' && cPlay == 'P') ||
			   (uPlay == 'P' && cPlay == 'R') ||
			   (uPlay == 'R' && cPlay == 'S'));

	if(userWin)
	{
		userWin = true;
	}
	else
	{
		userWin = false;
	}
	
	return userWin;
}
