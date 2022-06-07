/******************************************************************************
 * AUTHOR        : JJ David & Nathan Smith
 * STUDENT ID    : 1083135 & 387089
 * LAB 25b       : Array Train - Set #2
 * CLASS	     : CS1A
 * SECTION	     : TTh: 1pm
 * DUE DATE	     : 11/28/17
 *****************************************************************************/

#include "myheader.h"

/******************************************************************************
 * FUNCTION OutputArFile
 * ____________________________________________________________________________
 * This function outputs array contents in table format to console
* ==> returns nothing
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 		Needs string array and int array.
 * POST-CONDITIONS
 * 		<none>
 *****************************************************************************/

void OutputArFile(string stringAr[],
				  int intAr[],
			      const int AR_SIZE,
				  ofstream &OutputFile)
{
	int index;


	const int NAME_COL = 14;
	const int AGE_COL = 13;

	OutputFile << setw(NAME_COL) << "NAME" << setw(NAME_COL) << "AGE\n";
	OutputFile << endl;

	for(index = 1; index < AR_SIZE; index++)
	{

		OutputFile << setw(NAME_COL) << stringAr[index]
				   << setw(AGE_COL)  << intAr[index] << endl;
	}

}
