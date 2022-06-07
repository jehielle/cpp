/******************************************************************************
 * AUTHOR		: Jon Brubaker & JJ David
 * STUDENT ID	: 1006149 & 1083135
 * LAB # 13 	: Output - Geometry
 * CLASS 		: CS1A
 * SECTION		: TTH: 1:00p
 * DUE DATE		: 10/17/17
 *****************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/******************************************************************************
 * Output - Geometry
 *_____________________________________________________________________________
 * This program will obtain from the user the dimensions of 3 geometric objects
 * - a triangle, a rectangle and a circle.
 *****************************************************************************/

int main ( )
{

	/*************************************************************************
	* CONSTANTS
	* ------------------------------------------------------------------------
	* OUTPUT - USED FOR CLASS HEADING
	* ------------------------------------------------------------------------
	* PROGRAMMER  : Programmer's Name
	* CLASS	      : Student's Course
	* SECTION	  : Class Days and Times
	* LAB_NUM	  : Lab Number (specific to this lab)
	* LAB_NAME	  : Title of the Lab
	*************************************************************************/

	const char PROGRAMMER[] = "Jonathan Brubaker & JJ David";
	const char CLASS[]		= "CS1A";
	const char SECTION[]	= "TTh: 1:00p - 2:50p";
	const int  LAB_NUM		= 13;
	const char LAB_NAME[]	= "Output - Geometry";

	// OUTPUT - Class Heading
	cout << left;
	cout << "***************************************************\n";
	cout << "* PROGRAMMED BY :  " << PROGRAMMER << endl;
	cout << "* "      << setw(14) << "CLASS"    << ":  " << CLASS    << endl;
	cout << "* "      << setw(14) << "SECTION"  << ":  " << SECTION  << endl;
	cout << "* LAB #" << setw(9)  << LAB_NUM    << ":  " << LAB_NAME << endl;
	cout << "***************************************************\n\n";
	cout << right;

 	float	heightTri;		   // IN & CALC     - height of given geometric
 	                           // 				  shape
 	float	heightRec;		   // IN & CALC     - height of given geometric
 							   // 				  shape
	float	base;			   // IN & CALC	    - base of given geometric shape
	float	width;			   // IN & CALC	    - width of given geometric
							   //				  shape
	float	radius;			   // IN & CALC     - radius of given geometric
							   //				  shape
	float	areaTri;		   // CALC & OUT	- calculated area of triangle
	float	areaRec;		   // CALC & OUT	- calculated area of rectangle
	float	areaCirc;	       // CALC & OUT    - calculated area of circle

	/**************************************************************************
	 * CONSTANTS
	 * ------------------------------------------------------------------------
	 * ASSIGN & CALC - pi value
	 *
	 * OUTPUT - margin sizes for inputs & shapes
	 *************************************************************************/

	const float PI = 3.14159;
	const int INPUT_SIZE = 35;
	const int SPACE_TRI  = 18;
	const int SPACE_REC  = 19;
	const int SPACE_CIRC = 16;

// TRIANGLE

	/**************************************************************************
	 * INPUT - reads in two inputs from the user (height & base)
	 *************************************************************************/

	cout << left << setw(INPUT_SIZE) << "Enter the height of the triangle: ";
	cin  >> heightTri;

	cout 		 << setw(INPUT_SIZE) << "Enter the base of the triangle: ";
	cin  >> base;

	/**************************************************************************
	 * PROCESSING - Calculates the area of the triangle
	 *************************************************************************/

	areaTri  = heightTri * base / 2;

// RECTANGLE

	/**************************************************************************
	 * INPUT - reads in two inputs from the user (width & height)
	 *************************************************************************/

	cout << endl << setw(INPUT_SIZE) << "Enter the width of the rectangle: ";
	cin  >> width;

	cout         << setw(INPUT_SIZE) << "Enter the height of the rectangle: ";
	cin  >> heightRec;

	/**************************************************************************
	 * PROCESSING - Calculates the area of the rectangle
	 * ***********************************************************************/

	areaRec  = width * heightRec;

// CIRCLE

	/**************************************************************************
	 * INPUT - one input from user (radius)
	 *************************************************************************/

	cout << endl << setw(INPUT_SIZE) << "Enter the radius of the circle: ";
	cin  >> radius;

	/**************************************************************************
	 * PROCESSING - Calculates the area of the circle
	 * ***********************************************************************/

	areaCirc = PI * (radius*radius);

	/**************************************************************************
	 * OUTPUT - Output the area using setw constants stated in data table.
	 *************************************************************************/

	cout << endl  << endl;
	cout << right << setw(SPACE_TRI)  << "Triangle Area";
	cout 		  << setw(SPACE_REC)  << "Rectangle Area";
	cout		  << setw(SPACE_CIRC) << "Circle Area" << endl;

	cout 		  << setw(SPACE_TRI)  << areaTri;
	cout 		  << setw(SPACE_REC)  << areaRec;
	cout 		  << setw(SPACE_CIRC) << areaCirc << endl;

	cout		  << setprecision(3);
	cout 		  << setw(SPACE_TRI)  << areaTri;
	cout 		  << setw(SPACE_REC)  << areaRec;
	cout 		  << setw(SPACE_CIRC) << areaCirc << endl;

	cout		  << showpoint;
	cout 		  << setw(SPACE_TRI)  << areaTri;
	cout 		  << setw(SPACE_REC)  << areaRec;
	cout 		  << setw(SPACE_CIRC) << areaCirc << endl;

	cout		  << fixed;
	cout 		  << setw(SPACE_TRI)  << areaTri;
	cout 		  << setw(SPACE_REC)  << areaRec;
	cout 		  << setw(SPACE_CIRC) << areaCirc << endl;

	cout		  << setprecision(5);
	cout 		  << setw(SPACE_TRI)  << areaTri;
	cout 		  << setw(SPACE_REC)  << areaRec;
	cout 		  << setw(SPACE_CIRC) << areaCirc;


	/**************************************************************************
	 * We chose JJ's header and Jonathan's lab due to the header being properly
	 * aligned and the lab already containing comments and data tables.
	 **************************************************************************/

	return 0;
}
