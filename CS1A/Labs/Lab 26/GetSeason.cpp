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
 * FUNCTION GetSeason
 *--------------------------------------------------------------------------
 * 	 This function displays the menu and validates the input of the user.
 *   ==> returns a character representing the season
 *--------------------------------------------------------------------------
 * PRE-CONDITIONS
 *	  <none>
 *
 * POST-CONDITIONS
 *	  ==> returns a character representing the season
 ***************************************************************************/

char GetSeason()
{
	const int FRUIT_SELECTOR = 16;
	
	char seasonChar;
	bool invalid;

	cout << "********************" << endl;
	cout << setw(FRUIT_SELECTOR) << "FRUIT SELECTOR" << endl;
	cout << "********************" << endl;
	cout << "(W) Winter\n";
	cout << "(S) Spring\n";
	cout << "(U) Summer\n";
	cout << "(F) Fall\n";
	cout << "(X) Exit\n";
	cout << "What season is it? ";

	do
	{
		cin.get(seasonChar);
		cin.ignore(1000, '\n');

		seasonChar = toupper(seasonChar);

		invalid = seasonChar != 'W' && seasonChar != 'S' &&
				  seasonChar != 'U' && seasonChar != 'F' &&
				  seasonChar != 'X';

		if(invalid)
		{
			cout << "\n*** INVALID INPUT - Please input a W, S, U, F or X ***";
			cout << endl << endl;

			cout << "********************" << endl;
			cout << setw(FRUIT_SELECTOR) << "FRUIT SELECTOR" << endl;
			cout << "********************" << endl;
			cout << "(W) Winter\n";
			cout << "(S) Spring\n";
			cout << "(U) Summer\n";
			cout << "(F) Fall\n";
			cout << "(X) Exit\n";
			cout << "What season is it? ";
		}//END IF

	}while(invalid);


		return seasonChar;
}



