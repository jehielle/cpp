/***************************************************************************
 * AUTHER     : Christopher Hibler & JJ David
 * STUDENT ID : 1079891 & 1083135
 * LAB #22    : Intro to Functions
 * CLASS      : CS1A
 * SECTION    : TTH: 1pm
 * DUE DATE   : 11/2/17
 ***************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

// PROTOTYPES
int    AddTwoInts    (int num1, int num2);
double MultiTwoInts  (int num1, int num2);
int    LargestTwoInts(int num1, int num2);
double AverageTwoInts(int num1, int num2);

/***************************************************************************
 * Intro to Functions
 *---------------------------------------------------------------------------
 * This program will output the sum, product, largest, and average of two
 * numbers input by the user, until the value -999 is input.
 *---------------------------------------------------------------------------
 * INPUT: The inputs will be two numbers input by the user:
 *
 * 		n1 : The first integer
 * 		n2 : the second integer
 *
 * OUTPUT: The outputs will be the sum of the two numbers input by the user,
 * as well as the product, largest, and average of the two numbers.
 *
 * 		sum     : holds the sum of two numbers
 * 		product : holds the product of two numbers
 * 		largest : holds the largest of two numbers
 * 		average : holds the average of two numbers
 ***************************************************************************/
int main()
{
	/***********************************************************************
	 * CONSTANTS
	 * ----------------------------------------------------------------------
	 * OUTPUT - USED FOR CLASS HEADING
	 * ----------------------------------------------------------------------
	 * PROGRAMMER : Programmer's Name
	 * CLASS      : Student's Course
	 * SECTION    : Class Days and Times
	 * LAB_NUM    : Lab Number (specific to this lab)
	 * LAB_NAME   : Title of the Lab
	 * ----------------------------------------------------------------------
	 * FORMATTING FOR LAB 22
	 * ----------------------------------------------------------------------
	 * COL_WORD   : Formatting for the words before the numbers(ex: The SUM is:)
	 * COL_NUM    : Formatting for the numbers after the words(ex: 9)
	 * COL_INPUT  : Formatting for the width of the prompts
	 ***********************************************************************/
    const char PROGRAMMER[] = "Christopher Hibler & JJ David";
    const char CLASS[]      = "CS1A";
    const char SECTION[]    = "TTH: 1:00p - 4:20p";
    const int  LAB_NUM      = 22;
    const char LAB_NAME[]   = "Intro to Functions";

    const int COL_WORD      = 15;
    const int COL_NUM       = 6;
    const int COL_INPUT     = 26;

    // variable declarations go here
    int    n1;      // INPUT      - first of two numbers used for calculations
	int    n2;      // INPUT      - second of two numbers used for calculations
	int    sum;     // CALC & OUT - holds the sum of two numbers
	int    largest; // CALC & OUT - holds the largest of two numbers
	double product; // CALC & OUT - holds the product of two numbers
	double average; // CALC & OUT - holds the average of two numbers

    // OUTPUT - Class Heading
    cout << left;
    cout << "*************************************************\n";
    cout << "* PROGRAMMED BY : "  << PROGRAMMER << endl;
    cout << "* "      << setw(14) << "CLASS"    << ": " << CLASS    << endl;
    cout << "* "      << setw(14) << "SECTION"  << ": " << SECTION  << endl;
    cout << "* LAB #" << setw(9)  << LAB_NUM    << ": " << LAB_NAME << endl;
    cout << "*************************************************\n\n";
    cout << right;

    /***********************************************************************
     * INPUT - this allows the user to input two integers, as long as the
     * value inputed is not -999 (will cause program to terminate)
     ***********************************************************************/

    cout << left << setw(COL_INPUT) << "Enter the first integer: ";
    cin  >> n1;
    cin.ignore(1000, '\n');

    while(n1 != -999)
    {

    cout << left << setw(COL_INPUT) << "Enter the second integer: ";
	cin  >> n2;
	cin.ignore(1000, '\n');

    /***********************************************************************
     * PROCESSSING - calls upon functions in order to calculate the sum,
     * product, largest, and average of the two integers
     ***********************************************************************/
	sum     = AddTwoInts(n1, n2);

	product = MultiTwoInts(n1, n2);

	largest = LargestTwoInts(n1, n2);

	average = AverageTwoInts(n1, n2);


    /***********************************************************************
     * OUTPUT - outputs the sum, product, largest, and average of the two
     * integers
     * ex:
     *
	 * The SUM is:         9
	 * The PRODUCT is:    18
	 * The LARGEST is:     6
	 * The AVERAGE is:   4.5
     ***********************************************************************/

	cout << endl;
	cout << left  << setw(COL_WORD) << "The SUM is:"
		 << right << setw(COL_NUM)  << sum << endl;

	cout << left  << setw(COL_WORD) << "The PRODUCT is:"
		 << right << setw(COL_NUM)  << product << endl;

	cout << left  << setw(COL_WORD) << "The LARGEST is:"
		 << right << setw(COL_NUM)  << largest << endl;

	cout << left  << setw(COL_WORD) << "The AVERAGE is:"
		 << right << setw(COL_NUM)  << average << endl;

	cout << endl << endl << endl;

	cout << left << setw(COL_INPUT) << "Enter the first integer: ";
	cin  >> n1;
	cin.ignore(1000, '\n');

	cout << right;
    }

	return 0;
}


