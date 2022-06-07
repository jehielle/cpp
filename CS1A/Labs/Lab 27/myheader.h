//This is my header file called myheader.h
#ifndef MYHEADER_H_
#define MYHEADER_H_

//processor directive go here
#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>

using namespace std;

//Global Constants
const int TOTAL_MOVIES = 5;
const int TOTAL_USERS = 4;


// prototypes

/***************************************************************************
 * PrintHeader
 * 	 This function receives an assignment name, type
 *   and number then outputs the appropriate header
 *   ==> returns nothing - This will output the class heading.
 **************************************************************************/
void PrintHeader(string asName,       // IN & OUT - name of the lab/assignment
				 int    asNum,        // IN & OUT - number of the lab/assignment
				 char   asType = 'L');// IN       - whether lab or assignment)
									  // 		   ('L' = Lab,
									  // 		    'A' = Assignment)

/***************************************************************************
 * ReadInputToAr
 * 	 This function receives inputs from the input file and puts it into the
 * 	 array.
 *   ==> returns nothing - This will put inputs into the array.
 **************************************************************************/
void ReadInputToAr(int ratingsAr[][TOTAL_MOVIES]); // IN/OUT - The 2D array

/***************************************************************************
 * CalcRowAvg
 * 	 This function receives the row and the ratings array. It will calculate
 * 	 the average of the numbers in the row.
 *   ==> returns the average of the row.
 **************************************************************************/
double CalcRowAvg( int fRow,						// IN - the row of numbers
				   int ratingsAr[][TOTAL_MOVIES]);	// IN - The 2D array

/***************************************************************************
 * CalcColAvg
 * 	 This function receives the column and the ratings array. It will calculate
 * 	 the average of the numbers in the row.
 *   ==> returns the average of the column.
 **************************************************************************/
double CalcColAvg(int fCol,						  // IN - the column of numbers
				  int ratingsAr[][TOTAL_MOVIES]); // IN - The 2D array

/***************************************************************************
 * CalcMax
 * 	 This function receives the ratings array.
 *   ==> returns the largest integer.
 **************************************************************************/
int CalcMax(int ratingsAr[][TOTAL_MOVIES]);			// IN - The 2D array

/***************************************************************************
 * CalcMin
 * 	 This function receives the ratings array.
 *   ==> returns the smallest integer.
 **************************************************************************/
int CalcMin(int ratingsAr[][TOTAL_MOVIES]);			// IN - The 2D array

#endif /* MYHEADER_H_ */
