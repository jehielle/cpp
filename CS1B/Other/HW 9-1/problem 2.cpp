// ----------------------------------------------------------------------------
// File name: problem 2.cpp                                                   -
// ----------------------------------------------------------------------------
// Creator's name and email: Jehielle David jdavid21@saddleback.edu           -
// Course-Section: CS1B                                                       -
// Creation Date: 2/14/18                                                     -
// Date of Last Modification: 2/15/18                                         -
// ----------------------------------------------------------------------------
// Purpose: Structs Homework                                                  -
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
// - manufacturer      carType     nothing                                    -
// - modelType         carType     nothing                                    -
// - color             carType     nothing                                    -
// - numOfDoors        carType     0                                          -
// - mpgCity           carType     0                                          -
// - mpgHighway        carType     0                                          -
// - yearBuilt         carType     0                                          -
// - price             carType     0.0                                        -
// -                                                                          -
// ----------------------------------------------------------------------------


#include <string>

using namespace std;

int main()
{
	
	//9-2 : define a struct, carType
	struct carType
	{
		string manufacturer; // manufacturer of car
		string modelType;	 // model type
		string color;		 // color of car
		int    numOfDoors;	 // number of doors on car
		int    mpgCity;		 // miles per gallon in city
		int    mpgHighway;   // miles per gallon on highway
		int    yearBuilt;    // year when car was built
		double price;		 // price of car
	};
	
	
	
	return 0;
}