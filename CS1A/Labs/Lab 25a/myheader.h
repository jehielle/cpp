/******************************************************************************
 * AUTHOR        : JJ David & Justice Flenniken
 * STUDENT ID    : 1083135 & 1071976
 * ASSIGNMENT #9 : Functions
 * CLASS	     : CS1A
 * SECTION	     : TTh: 1pm
 * DUE DATE	     : 11/21/17
 *****************************************************************************/


#ifndef MYHEADER_H_
#define MYHEADER_H_

#include <iostream> // for cin, cout
#include <iomanip>  // for setws, fixed, setprecision
#include <string>   // for strings

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
* CalcAverage
* This function receives the integer array and size and calculates the average
* 	  of the array.
* ==> This will return the average of the integers.
**************************************************************************/
double CalcAverage(const int INT_AR[],   // IN - Array of ages
				   const int AR_SIZE);   // IN - Size of the array

/**************************************************************************
* FindIntInstances
* This function receives the integer array, array size, and searchAge to then
* 	  find the number of times the user inputed integer appears.
* ==> This will return the instances of an integer found.
**************************************************************************/
int FindIntInstances(const int INT_AR[], // IN - Array of ages
		             const int AR_SIZE,  // IN - Size of the array
					 int searchInt);	 // IN - User input of age

/**************************************************************************
* FirstIntInstance
* This function receives the integer array, array size, and searchInt to then
* 	  find the first instance of the user's inputed integer.
* ==> This will return the index of the first instance of an integer.
**************************************************************************/
int FirstIntInstance(const int INT_AR[], // IN - Array of ages
					 const int AR_SIZE,  // IN - Size of the array
					 int searchInt);	 // IN - User input of age

/**************************************************************************
* SearchName
* This function receives the integer array, array size, and searchName to
* 	  determine if a name is present in the array.
* ==> This will return the index of the found name.
**************************************************************************/
int SearchName(const string NAME_AR[],   // IN - Array of names
			   const int AR_SIZE,	     // IN - Size of the array
			   string searchName);       // IN - User input of name

/**************************************************************************
* FindLargestInt
* This function receives the integer array, and array size to then find the
* 	  largest integer in the array.
* ==> This will return the position in the array of the largest integer.
**************************************************************************/
int FindLargestInt(const int INT_AR[],   // IN - Array of ages
		           const int AR_SIZE);   // IN - Size of the array

/**************************************************************************
* FindSmallestInt
* This function receives the integer array, and array size to then find the
* 	  smallest integer in the array.
* ==> This will return the position in the array of the smallest integer.
**************************************************************************/
int FindSmallestInt(const int INT_AR[],   // IN - Array of ages
		            const int AR_SIZE);   // IN - Size of the array

/**************************************************************************
* IntSum
* This function receives the integer array and array size to then sum the array.
* ==> This will return the sum of all of the values in INT_AR.
**************************************************************************/
int IntSum(const int INT_AR[],           // IN - Array of ages
		   const int AR_SIZE);           // IN - Size of the array



#endif /* MYHEADER_H_ */
