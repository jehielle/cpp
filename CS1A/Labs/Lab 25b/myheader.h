/******************************************************************************
 * AUTHOR        : JJ David & Nathan Smith
 * STUDENT ID    : 1083135 & 387089
 * LAB 25b       : Array Train - Set #2
 * CLASS	     : CS1A
 * SECTION	     : TTh: 1pm
 * DUE DATE	     : 11/28/17
 *****************************************************************************/

#ifndef MYHEADER_H_
#define MYHEADER_H_

#include <iostream> // for cin, cout
#include <iomanip>  // for setws, fixed, setprecision
#include <string>   // for strings
#include <fstream>  // for files

using namespace std;

/**************************************************************************
* PrintHeader
* This function receives an assignment name, type
* and number then outputs the appropriate header
* ==> returns nothing - This will output the class heading.
**************************************************************************/
void PrintHeader(string asName,// IN - assignment Name – used for output
				 int asNum,    // IN – assign. number – used for output
				 char asType); // IN - assignment type
							   // - (LAB or ASSIGN) – used for output*/

/**************************************************************************
* InitializeIntAr
* This function will initialize int array to -1.
* ==> returns nothing
**************************************************************************/
void InitializeIntAr(int intAr[],
					 const int AR_SIZE);

/**************************************************************************
* InitializeStrAr
* This function initializes string array to str.clear()
* ==> returns nothing
**************************************************************************/
void InitializeStrAr(string stringAr[],
					 const int AR_SIZE);

/**************************************************************************
* InitializeBothAr
* This function initializes both arrays in one function
* ==> returns nothing
**************************************************************************/
void InitializeBothAr(int intAr[],
					  string stringAr[],
					  const int AR_SIZE);

/**************************************************************************
* InputFromFile
* This function reads from an input file into the arrays
* ==> returns nothing
**************************************************************************/
void InputFromFile(string stringAr[],
				   int intAr[],
				   const int AR_SIZE);

/**************************************************************************
* InputFromUser
* This function reads from a user into the arrays
* ==> returns nothing
**************************************************************************/
void InputFromUser(string stringAr[],
				   int intAr[],
				   const int AR_SIZE);

/**************************************************************************
* OutputArConsole
* This function outputs array contents in table format to console
* ==> returns nothing
**************************************************************************/
void OutputArConsole(string stringAr[],
					int intAr[],
					const int AR_SIZE);

/**************************************************************************
* OutputArFile
* This function outputs array contents in table format to a file
* ==> returns nothing
**************************************************************************/
void OutputArFile(string stringAr[],
				  int intAr[],
			      const int AR_SIZE,
				  ofstream &OutputFile);


#endif /* MYHEADER_H_ */
