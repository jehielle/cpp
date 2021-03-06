#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	/**************************************************************************
	 * CONSTANTS
	 * ------------------------------------------------------------------------
	 * OUTPUT - USED FOR CLASS HEADING
	 * ------------------------------------------------------------------------
	 * PROGRAMMER : Programmer's Name
	 * CLASS	  : Student's Course
	 * SECTION	  : Class Days and Times
	 * LAB_NUM	  : Lab Number (specific to this lab)
	 * LAB_NAME	  : Title of the Lab
	 *************************************************************************/
	const char PROGRAMMER[] = "Amy Hogan & JJ David";
	const char CLASS[]		= "CS1A";
	const char SECTION[]	= "TTh: 1:00p - 2:50p";
	const int  LAB_NUM		= 11;
	const char LAB_NAME[]	= "Output - Geometry";

	// OUTPUT - Class Heading
	cout << left;
	cout << "***************************************************\n";
	cout << "* PROGRAMMED BY :  "  << PROGRAMMER << endl;
	cout << "* "      << setw(14) << "CLASS"    << ":  " << CLASS    << endl;
	cout << "* "      << setw(14) << "SECTION"  << ":  " << SECTION  << endl;
    cout << "* LAB #" << setw(9)  << LAB_NUM    << ":  " << LAB_NAME << endl;
    cout << "***************************************************\n\n";
    cout << right;

    /**************************************************************************
     * CONSTANTS
     * ------------------------------------------------------------------------
     * PI : 3.14159
     *************************************************************************/
    const float PI = 3.14159;

    float		heightTri;		   // IN & OUT   - inputs height of triangle
	float 		baseTri;    	   // IN & OUT   - inputs base of triangle
    float 		widthRec;   	   // IN & OUT   - inputs width of rectangle
    float 		heightRec;  	   // IN & OUT   - inputs height of rectangle
    float		radiusCirc; 	   // IN & OUT   - inputs radius of circle
	float 		areaTri;		   // CALC & OUT - calculates area of triangle
	float		circumferenceTri;  // CALC & OUT - calculates circumference of
								   //			   triangle
	float		areaRec;		   // CALC & OUT - calculates area of rectangle
	float		circumferenceRec;  // CALC & OUT - calculates circumference of
								   //			   rectangle
	float		areaCirc;		   // CALC & OUT - calculates area of circle
	float		circumferenceCirc; // CALC & OUT - calculates circumference of
								   //			   circle

	cout			 << "Enter the height of the triangle: ";
	cin  			 >> heightTri;
	cout 			 << "Enter the base of the triangle:   ";
	cin 			 >> baseTri;

	areaTri			 = heightTri * baseTri / 2;
	circumferenceTri = baseTri * 3;

	cout 			 << endl;
	cout			 << "TRIANGLE OBJECT" << endl;
	cout			 << "\tArea" << setw(18) << "Perimeter" << endl;
	cout 			 << right << setw(9) << areaTri << right << setw(9) << "\t";
	cout			 << circumferenceTri;
	cout 			 << endl << endl;
	cout			 << endl;

	cout			 << "Enter the width of the rectangle:  ";
	cin				 >> widthRec;
	cout 			 << "Enter the height of the rectangle: ";
	cin 			 >> heightRec;
	cout			 << endl;

	areaRec			  = widthRec * heightRec;
	circumferenceRec  = (widthRec + heightRec) * 2;

	cout			 << "RECTANGLE OBJECT" << endl;
	cout 			 << "\tArea" << setw(18) << "Perimeter" << endl;
	cout			 << right << setw(9) << areaRec << setw(18) << "\t";
	cout			 << circumferenceRec;
	cout			 << endl << endl << endl;

	cout 			 << "Enter the radius of the circle: ";
	cin 			 >> radiusCirc;
	cout			 << endl;

	areaCirc 		  = PI * (radiusCirc * radiusCirc);
	circumferenceCirc = PI * radiusCirc * 2;

	cout			 << "CIRCLE OBJECT" << endl;
	cout			 << "\tArea" << setw(18) << "Circumference" << endl;
	cout			 << right << setw(9) << areaCirc << setw(18) << "\t";
	cout			 << circumferenceCirc;
	cout			 << endl << endl << endl << endl;

    return 0;
}
