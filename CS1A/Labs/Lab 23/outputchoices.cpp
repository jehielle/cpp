/******************************************************************************
 * AUTHOR        : JJ David, Nina Brock
 * STUDENT ID    : 1083135, 378941
 * LAB #23       : Functions - Rock Paper Scissors
 * CLASS	     : CS1A
 * SECTION	     : TTh: 1pm
 * DUE DATE	     : CHOICE_SIZE/14/17
 *****************************************************************************/

#include "myheader.h"

/******************************************************************************
 * FUNCTION OutputChoices
 * ____________________________________________________________________________
 * This function outputs the user's choice (rock, paper, or scissors).
 * It returns nothing.
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 		uPlay : play of the user (R, P, or S)
 * 		cPlay : play of the computer (R, P, or S)
 * 		name  : name of the user
 *
 * POST-CONDITIONS
 * 		This function outputs the user's choice (rock, paper, or scissors).
 *****************************************************************************/

void OutputChoices(char uPlay,  // play of the user (R, P, or S)
				   char cPlay,  // play of the computer (R, P, or S)
				   string name) // name of the user
{
	const int CHOICE_SIZE = 11;
	char userChoice[CHOICE_SIZE];
    char computerChoice[CHOICE_SIZE];



  switch(uPlay)
  {
    case 'S' : strncpy(userChoice,"SCISSORS!",CHOICE_SIZE);
               break;
    case 'R' : strncpy(userChoice,"ROCK!",CHOICE_SIZE);
               break;
    case 'P' : strncpy(userChoice,"PAPER!",CHOICE_SIZE);
               break;
  }
  switch(cPlay)
  {
    case 'S' : strncpy(computerChoice,"SCISSORS!",CHOICE_SIZE);
               break;
    case 'R' : strncpy(computerChoice,"ROCK!",CHOICE_SIZE);
               break;
    case 'P' : strncpy(computerChoice,"PAPER!",CHOICE_SIZE);
               break;
  }

  cout << name << " chooses " << userChoice << endl;
  cout << "Computer chooses " << computerChoice << endl << endl;
}
