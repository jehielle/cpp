/*****************************************************************************
 * AUTHORS		: JJ David & Lucy Cummins
 * STUDENT IDs  : 1083135 & 1093492
 * LAB #15 		: Pocket Money
 * CLASS 		: TTh - 1pm
 * SECTION 		: CS1A
 * DUE DATE 	: 10/19/17
 *****************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/******************************************************************************
 *  Pocket Money Program
 * ----------------------------------------------------------------------------
 *  This program receives the pocket money left over from the previous
 *  	week and the amount spent in the current week from the user and
 *  	calculates how much pocket money is remaining. Each week the user
 *  	is allocated $20.00.
 *-----------------------------------------------------------------------------
 * INPUT:
 *       name        : The user's name.
 *       amtLeftover : Amount leftover from the previous week.
 *       spent       : Amount spent this week.
 *
 * OUTPUT:
 *		 name        : User's Name
 *		 pocketMoney : Amount of pocket money remaining
 *****************************************************************************/

int main()
{
	/**************************************************************************
	 * CONSTANTS
	 * ------------------------------------------------------------------------
	 * OUTPUT - USED FOR CLASS HEADING
	 * ------------------------------------------------------------------------
	 * PROGRAMMER : Programmer's Name
	 * CLASS	  : Student's Course
	 * SECTION	  : Class Days and Times
	 * LAB_NUM	  : Lab Number (specific to this lab)
	 * LAB_NAME	  : Title of the Lab
	 * ------------------------------------------------------------------------
	 * USED FOR PROCESSING
	 * ------------------------------------------------------------------------
	 * ALLOWANCE  : Money received weekly
	 * ------------------------------------------------------------------------
	 * USED FOR FORMATTING
	 * ------------------------------------------------------------------------
	 * PROMPT_COL : the set width for the prompts
	 *************************************************************************/
	const char PROGRAMMER[] = "JJ David & Lucy Cummins";
	const char CLASS[]		= "CS1A";
	const char SECTION[]	= "TTh: 1:00p - 4:20p";
	const int  LAB_NUM		= 15;
	const char LAB_NAME[]	= "Pocket Money";

	const float ALLOWANCE   = 20.0;

	const int PROMPT_COL    = 34;

	char  name[30];    //IN & OUT   - Name of the user
	float amtLeftover; //IN         - Money leftover from previous week
	float spent;       //IN         - Money spent in current week
	float pocketMoney; //OUT & CALC - Pocket money for remainder of week

	// OUTPUT - Class Heading
	cout << left;
	cout << "***************************************************\n";
	cout << "* PROGRAMMED BY :  "  << PROGRAMMER << endl;
	cout << "* "      << setw(14) << "CLASS"    << ":  " << CLASS    << endl;
	cout << "* "      << setw(14) << "SECTION"  << ":  " << SECTION  << endl;
    cout << "* LAB #" << setw(9)  << LAB_NUM    << ":  " << LAB_NAME << endl;
    cout << "***************************************************\n\n";
    cout << right;

   // INPUT: read in name, money leftover, and money spent from the user
    cout << left << setw(PROMPT_COL) << "What is your name?";
    cin.getline(name, 30);

    cout << setw(PROMPT_COL) << "How much is left from last week?";
    cin  >> amtLeftover;

    cout << setw(PROMPT_COL) << "How much have you spent?";
    cin  >> spent;

    cout << right;
    cout << endl;


   // PROCESSING: calculate the pocket money for remainder of the week
    pocketMoney = (ALLOWANCE + amtLeftover) - spent;

   // OUTPUT:
    cout << setprecision(2)  << fixed;
    cout << "Hello " << name << "!" << endl;
    cout << "You now have $ " << pocketMoney << " left.";

    return 0;
}
