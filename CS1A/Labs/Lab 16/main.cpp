/**********************************************************
 * AUTHORS		: Pierre Cruzalegui & JJ David
 * STUDENT IDs  : 1079898 & 1083135
 * LAB 16		: Selection - Party Planner
 * CLASS		: TTH - 1PM
 * SECTION		: CS1A
 * DUE DATE		: 10/24/17
 ***********************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
using namespace std;

/*****************************************************************************
 *	This program will help decide someone to decide which snacks and beverages
 *	 to serve their friend.
 *****************************************************************************/

int main ()
{
	/*************************************************************************
     * CONSTANTS
	 * ------------------------------------------------------------------------
	 * OUTPUT - USED FOR CLASS HEADING
	 * ------------------------------------------------------------------------
	 * PROGRAMMER : Programer's Name
	 * CLASS      : Student's Course
	 * SECTION    : Class Days and Times
	 * LAB_NUM    : Lab Number (specified to this lab)
	 * LAB_NAME   : Title of the Lab
	 * ------------------------------------------------------------------------
	 * OUTPUT - USED FOR FORMATTING
	 *************************************************************************/
	const char PROGRAMMER[]		 = "Pierre Cruzalegui & JJ David";
	const char CLASS[]			 = "CS1A";
	const char SECTION[]		 = "TTh: 1:00p - 4:20p";
	const int  LAB_NUM           = 16;
	const char LAB_NAME[]		 = "Selection - Party Planner";

	const int  PROMPT_COL		 = 31;
	const int  NAME_SIZE		 = 30;

		  char name[NAME_SIZE]; // name of the user's friend
		  int  age;  // age of user's friend
		  char choc; // whether or not the user's friend likes chocolate
		  char nuts; // whether or not the user's friend likes nuts

		  char snacks[NAME_SIZE]; // option for snacks
		  char drinks[NAME_SIZE]; // option for drinks

    // OUTPUT - Class Heading
	cout << left;
	cout << "**************************************************************\n";
	cout << "* PROGRAMMED BY : "    << PROGRAMMER                    << endl;
	cout << "* "	   << setw(14) << "CLASS"   << ": " << CLASS	<< endl;
	cout << "* "	   << setw(14) << "SECTION" << ": " << SECTION  << endl;
	cout << "* LAB #"  << setw(9)  << LAB_NUM  << ": " << LAB_NAME << endl;
	cout << "************************************************************\n\n";
	cout << right;

	/*************************************************************************
	 * INPUT - prompts the user for friend's name, age, and whether or not
	 * 		   they like chocolate and/or nuts
	 *************************************************************************/

	cout << left;
	cout << setw(PROMPT_COL) << "\tWhat is your friend\'s name?";
	cin.getline(name, NAME_SIZE);

	cout << setw(PROMPT_COL) << "\tHow old is your friend?";
	cin  >> age;
	cin.ignore(1000, '\n');

	cout << setw(PROMPT_COL) << "\tDo they like chocolate (Y/N)?";
	cin.get(choc);
	cin.ignore(1000, '\n');

	cout << setw(PROMPT_COL) << "\tDo they like nuts (Y/N)?";
	cin.width(2);
	cin.get(nuts);
	cin.ignore(1000, '\n');
	cout << right;

	/*************************************************************************
	 * 	PROCESSING - if then else statement for choosing snacks/drinks
	 *************************************************************************/
	if(choc == 'Y')
	{
		if(nuts == 'Y')
		{
			strncpy(snacks, "Peanut M & M\'s ", NAME_SIZE);
		}
		else
		{
			strncpy(snacks, "M & M\'s ", NAME_SIZE);
		}
	}
	else
	{
		strncpy(snacks, "Skittles ", NAME_SIZE);
	}

	if(age >= 21)
	{
		strncpy(drinks, "beer.", NAME_SIZE);
	}
	else
	{
		strncpy(drinks, "soda.", NAME_SIZE);
	}


	/*************************************************************************
	 * OUTPUT - outputs the user's friend and the food choice to serve them
	 *************************************************************************/

	cout << endl;
	cout << "\tYou should serve " << name << " " << snacks << "and " << drinks;
	cout << endl << endl << endl;


return 0;

}
