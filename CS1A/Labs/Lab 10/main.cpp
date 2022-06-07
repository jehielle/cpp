/******************************************************************************
 * AUTHORS    : JJ David & Leo Sanchez
 * STUDENT ID : 1083135 & 1041160
 * LAB #10	  : Intro to Programming Lab
 * CLASS	  : CS1A
 * SECTION	  : TTh: 1pm
 * DUE DATE	  : 10/03/17
 *****************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const char PROGRAMMER[] = " JJ David & Leo Sanchez";
	const char CLASS[]		= "CS1A";
	const char SECTION[]	= "TTh: 1:00p - 2:50p";
	const int  LAB_NUM		= 10;
	const char LAB_NAME[]	= "Intro to Programming";

	// OUTPUT - Class Heading

	cout << left;
	cout << "***************************************************\n";
	cout << "* PROGRAMMED BY :  "  << PROGRAMMER << endl;
	cout << "* "      << setw(14) << "CLASS"    << ":  " << CLASS    << endl;
	cout << "* "      << setw(14) << "SECTION"  << ":  " << SECTION  << endl;
    cout << "* LAB #" << setw(9)  << LAB_NUM    << ":  " << LAB_NAME << endl;
    cout << "***************************************************\n\n";
    cout << right;

	int firstNum;   // IN. CALC & OUT - first value to sum
	int secondNum;  // IN. CALC & OUT - second value to sum
	int sum;        // CALC & OUT     - sum of 2 integers input
	float averageNum; // CALC & OUT     - average of 2 integers
	/**************************************************************************
	 * INPUT - reads in two inputs from the user (firstNum & secondNum)
	 *************************************************************************/
	cout << "Enter the first integer:  ";
	cin  >> firstNum;

	cout << "Enter the second integer:  ";
	cin  >> secondNum;

	/**************************************************************************
	 * PROCESSING - Calculates the sum of the two inputs */

	sum = firstNum + secondNum;
	averageNum = sum / 2.0;

	/**************************************************************************
	 * OUTPUT - the inputs and the sum in the following format:
	 * 					  firstNum + secondNum = sum
	 * 	 For example, if firstNum = 32 & secondNum = 41 output will be:
	 * 	       32 + 41 = 73
	 *************************************************************************/

	cout << endl << firstNum << " + " << secondNum << " = " << sum << endl;
	cout << fixed << setprecision(2); // this line must come before the cout
									  //for average
	cout << "The average is: " << averageNum << endl;

	return 0;
}
