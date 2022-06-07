/***************************************************************************
 * AUTHER     : JJ David & Nikki Navid
 * STUDENT ID : 1083135 & 1074622
 * LAB #26    : Enumerated Types
 * CLASS      : CS1A
 * SECTION    : TTH: 1pm - 4:20pm
 * DUE DATE   : 11/28/17
 ***************************************************************************/
#include "MyHeader.h"

/***************************************************************************
 * FUNCTION PrintHeader
 *--------------------------------------------------------------------------
 * 	 This function receives an assignment name, type
 *   and number then outputs the appropriate header
 *   ==> returns nothing - This will output the class heading.
 *--------------------------------------------------------------------------
 * PRE-CONDITIONS
 *	  The following need a defined value passed in
 *			asName   : assignment name
 *			userName : programmer name
 *			userID   : programmer Id
 *			asNum    : assignment number
 *			asType   : assignment type(L or A)
 *
 * POST-CONDITIONS
 *	  ==>  Returns nothing - This function will output the class heading.
 ***************************************************************************/
void PrintHeader(string asName,   // IN - assignment Name      – used for output
				 string userName, // IN - the programmers name - used for output
				 string userID,   // IN - the programmers Id   - used for output
		         string asNum,    // IN – assign. number       – used for output
				 char   asType)   // IN - assignment type
								  //    - (LAB or ASSIGN)      – used for output
{
cout << left;
cout << "**************************************************\n";
cout << "* PROGRAMMED BY : " << userName << endl;
cout << "* " << setw(14) << "STUDENT ID" << ": " << userID << endl;
cout << "* " << setw(14) << "CLASS"      << ": CS1A - TTh 1pm-4:20pm\n";
cout << "* " ;

// PROCESSING – This will adjust setws and format appropriately
// based on if this is a lab ‘L’ or assignment

if (toupper(asType) == 'L')
{
cout << "LAB #" << setw(9);
}

else
{
cout << "ASSIGNMENT #" << setw(2);
}

cout << asNum << ": " << asName << endl;
cout << "**************************************************\n\n";
cout << right;
}
