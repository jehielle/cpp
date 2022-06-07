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
 * FUNCTION GetComputerPlay
 * ____________________________________________________________________________
 * This function randomly selects a play for the computer and returns the
 * character representing their play.
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 		<none>
 *
 * POST-CONDITIONS
 * 		This function will choose a random play for the computer.
 *****************************************************************************/

char GetComputerPlay()
{
	int myRandomValue; // IN  - the random value chosen from 1-3
	char cPlay;		   // OUT - play of the computer (R, P, or S)
	

	myRandomValue = rand()% 3 + 1;

	// PROCESSING - This will calculate the computer's play

	 switch(myRandomValue)
   {
      case 1 : cPlay = 'S';
                break;
      case 2 : cPlay = 'R';
                break;
      case 3 : cPlay = 'P';
                break;

  
    }
  return  cPlay;
}
