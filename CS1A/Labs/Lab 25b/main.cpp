/******************************************************************************
 * AUTHOR        : JJ David & Nathan Smith
 * STUDENT ID    : 1083135 & 387089
 * LAB 25b       : Array Train - Set #2
 * CLASS	     : CS1A
 * SECTION	     : TTh: 1pm
 * DUE DATE	     : 11/28/17
 *****************************************************************************/

#include "myheader.h"

/**************************************************************************
* LAB 25b: ARRAY TRAIN - SET #2
* -------------------------------------------------------------------------
* This program will use functions to do the following:
* 		- Initializes int array to value -1
* 		- Initializes string array to str.clear()
* 		- Initializes both arrays in one function
* 		- Reads from an input file into the arrays
* 		- Reads from a user into the arrays
* 		- Outputs array contents in table format to console
* 		- Outputs array contents in table format to a file
**************************************************************************/

int main()
{

	/*********************************************************************
	 * CONSTANT
	 * -------------------------------------------------------------------
	 * USED FOR ARRAYS
	 * -------------------------------------------------------------------
	 * AR_SIZE: The size of the array
	 *********************************************************************/

	const int AR_SIZE      = 8;

	string nameAr[AR_SIZE] = {"Zack", "Nikki", "Justice", "Gunner",
							  "Billy", "Chris", "James Pelligra",
							  "James Packes"};
	int ageAr[AR_SIZE]     = {20, 19, 18, 20, 19, 32, 21, 21};


	//OUTPUT - Class Heading
	PrintHeader("Array Train - Set #2", 25, 'L');

	//#1 - INITIALIZING ARRAYS
	InitializeIntAr(ageAr, AR_SIZE);
	InitializeStrAr(nameAr, AR_SIZE);
	InitializeBothAr(ageAr, nameAr, AR_SIZE);

	//#2 - INPUT  - read from file
    InputFromFile(nameAr, ageAr, AR_SIZE);

    //#3 - INPUT  - read from user
	InputFromUser(nameAr, ageAr, AR_SIZE);

	//#4 - OUTPUT - outputs to console
	cout << endl;
	OutputArConsole(nameAr, ageAr, AR_SIZE);

	// #5 - OUTPUT - array to file
	ofstream OFile;
	OFile.open("OutputFile.txt");

	OutputArFile(nameAr, ageAr, AR_SIZE, OFile);

	OFile.close();

	return 0;
}
