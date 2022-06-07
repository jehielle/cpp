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
 * FUNCTION InputFromFile
 * ____________________________________________________________________________
 * This function reads from an input file into the arrays
* ==> returns nothing
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 		Needs string array and int array.
 * POST-CONDITIONS
 * 		<none>
 *****************************************************************************/

void InputFromFile(string stringAr[],
				   int intAr[],
			       const int AR_SIZE)
{
	int index;
	ifstream inputFile;

	inputFile.open("InputFile.txt");

	for(index = 0; index < AR_SIZE; index++)
	{
		getline(inputFile, stringAr[index]);
		inputFile >> intAr[index];
		inputFile.ignore(1000, '\n');
		inputFile.ignore(1000, '\n');
	}
	inputFile.close();
}
