// ----------------------------------------------------------------------------
// File name: fileIO.cpp                                                      -
// ----------------------------------------------------------------------------
// Creator's name and email: Jehielle David jdavid21@saddleback.edu           -
// Course-Section: CS1B                                                       -
// Creation Date: 2/1/18                                                      -
// Date of Last Modification: 2/15/18                                         -
// ----------------------------------------------------------------------------
// Purpose: File I/O                                                          -
// ----------------------------------------------------------------------------
// Algorithm:                                                                 -
// Step 1: Create the code to hold information about a car.                   -
// ----------------------------------------------------------------------------
// -                          DATA DICTIONARY                                 -
// - CONSTANTS                                                                -
// -                                                                          -
// - NAME              DATA TYPE    VALUE                                     -
// - ---------------   ----------   --------                                  -
// -                                                                          -
// - VARIABLES                                                                -
// -                                                                          -
// - NAME              DATA TYPE    INITIAL VALUE                             -
// - ---------------   ----------   -------------                             -
// -                                                                          -
// ----------------------------------------------------------------------------


#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <limits>
#include <stdlib.h>

using namespace std;

int main()
{
	const int NUMBERS = 50;
	
	ifstream  fin;	     //fstream variable - input  - fin
	ofstream  fout;	     //fstream variable - output - fout
	double    userInput; //input from user
	double    squareRoot;//square root of the individual number
	int       countNum;  //counting numbers
	
	fout.open("numbers.dat");//OPEN INPUT FILE TO WRITE INTO FILE
	
	cout << "Welcome!\nPlease enter 50 floating point numbers one after the other,"
			" separated by one space: "
		 << endl << endl;
			
	countNum = 0;	//INITIALIZED countNum FOR WHILE LOOP - USER INPUT
	//INPUT - inputs & checks invalid input
	do
	{
		cin  >> userInput;
		
		if(cin.fail())
		{
			cout << "*** ERROR - PLEASE ENTER 50 FLOATING POINT NUMBERS ***";
			cout << endl << endl;
			
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			fout  << userInput << "\n";
			countNum++;
		}
	}while(cin.fail() || countNum < NUMBERS);

	fout.close();			   //CLOSE INPUT FILE
	fin.open("numbers.dat");   //OPEN INPUT FILE TO READ FROM FILE
	fout.open("sqr_root.out"); //OPEN OUTPUT FILE TO WRITE INTO FILE

	for(countNum = 0; countNum < NUMBERS; countNum++)
	{
		fin >> userInput;
		
		//PROCESSING - calculate square root of number

		
		fout << sqrt(userInput) << "\n";
		cout << "The square root of " << userInput << " is " << sqrt(userInput) << endl;
	}
	
	fin.close();			  //CLOSE INPUT FILE
	fout.close();			  //CLOSE OUTPUT FILE
	
	
	
	return 0;
}