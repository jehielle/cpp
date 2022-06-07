// ----------------------------------------------------------------------------
// File name: problem16.cpp                                                   -
// ----------------------------------------------------------------------------
// Creator's name and email: Jehielle David jdavid21@saddleback.edu           -
// Course-Section: CS1B                                                       -
// Creation Date: 2/14/18                                                     -
// Date of Last Modification: 2/15/18                                         -
// ----------------------------------------------------------------------------
// Purpose: Structs Homework                                                  -
// ----------------------------------------------------------------------------
// Algorithm:                                                                 -
// Step 1: Create the code to hold information about inventory.               -
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

using namespace std;

int main()
{
	
	int index;
	int length;
	
	length = 100;
	
	struct partsType
	{
		string partName;
		int    partNum;
		double price;
		int    quantitiesInStock;
	};
	
	//ARRAY - inventory
	partsType inventory[100];
	
	for(index = 0; index < length; index++)
	{
		inventory[index].partName          = " ";
		inventory[index].partNum           = -1;
		inventory[index].price             = 0.0;
		inventory[index].quantitiesInStock = 0;
	}
	
	for(index = 0; index < length; index++)
	{
		cout << inventory[index].partName          << endl;
		cout << inventory[index].partNum           << endl;
		cout << inventory[index].price             << endl;
		cout << inventory[index].quantitiesInStock << endl;
	}
	
	
	return 0;
}