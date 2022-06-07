// ----------------------------------------------------------------------------
// File name: yeahman.cpp                                                     -
// Project name: World of Pointers                                            -
// ----------------------------------------------------------------------------
// Creator's name and email: Jehielle David jdavid21@saddleback.edu           -
// Course-Section: CS1B                                                       -
// Creation Date: 3/6/18                                                      -
// Date of Last Modification: 3/6/18                                          -
// ----------------------------------------------------------------------------
// Purpose: World of Pointers                                                 -
// ----------------------------------------------------------------------------
// Algorithm:                                                                 -
// Step 1: Declare an int variable named number and assign an initial value   -
// Step 2: Declare a pointer variable named pNumber that points to an int/pter-
// Step 3: Assign the address of the variable number to pointer pNumber       -
// Step 4: Print content of pNumber                                           -
// Step 5: Print address of number                                            -
// Step 6: Print value pointed to by pNumber                                  -
// Step 7: Print value of number                                              -
// Step 8: Re-assign value pointed to by pNumber                              -
// Step 9: Print content of pNumber                                           -
// Step 10: Print address of number                                           -
// Step 11: Print the value pointed to by pNumber                             -
// Step 12: Print value of number. The value of number was changed via pointer-
// Step 13: Print the address of the pointer variable pNumber                 -
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
// - number            integer      88                                        -
// - pNumber           int pointer  address of number                         -
// ----------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
	int number;			//1. Declare an int variable named number and assign an initial value
	int * pNumber;		//2. Declare a pointer variable named pNumber that points to an int (or int pointer)
	pNumber = &number;	//3. Assign the address of the variable number to pointer pNumber

	number = 88;
	
	system("CLS");
	
	cout << "4. Contents of pNumber: " << pNumber;
	cout << endl;
	
	cout << "5. Address of number: "   << &number;
	cout << endl;
	
	cout << "6. Value pointed to by pNumber: " << *pNumber;
	cout << endl;
	
	cout << "7. Value of number: " << number;
	cout << endl;
	
	//8. Re-assign value pointed to by pNumber (results in number equaling the new value)
	*pNumber = 99;
	
	cout << "9. Contents of pNumber: " << pNumber;
	cout << endl;
	
	cout << "10. Address of number: " << &number;
	cout << endl;
	
	cout << "11. Value pointed to by pNumber: " << *pNumber;
	cout << endl;
	
	cout << "12. Value of number: " << number;
	cout << endl;
	
	cout << "13. Address of pNumber: " << &pNumber;
	
	return 0;
}