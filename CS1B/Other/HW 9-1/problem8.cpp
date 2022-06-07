// ----------------------------------------------------------------------------
// File name: problem 8.cpp                                                   -
// ----------------------------------------------------------------------------
// Creator's name and email: Jehielle David jdavid21@saddleback.edu           -
// Course-Section: CS1B                                                       -
// Creation Date: 2/14/18                                                     -
// Date of Last Modification: 2/15/18                                         -
// ----------------------------------------------------------------------------
// Purpose: Structs Homework, Problem 8a and 8b                               -
// ----------------------------------------------------------------------------
// Algorithm:                                                                 -
// Step 1: Create the code to hold information about a house.                 -
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
// - style             houseType    nothing                                   -
// - numOfBedrooms     houseType    0                                         -
// - numOfBathrooms    houseType    0                                         -
// - yearBuilt         houseType    0                                         -
// - price             houseType    0.0                                       -
// - tax               houseType    0.0                                       -
// ----------------------------------------------------------------------------

#include <iostream>
#include <string>

using namespace std;

//FUNCTION PROTOTYPES
void getHouseInput(struct houseType);
void printHouseInfo(struct houseType);

int main()
{
	struct houseType
	{
		string style;
		int    numOfBedrooms;
		int    numOfBathrooms;
		int    yearBuilt;
		double price;
		double tax;
	};
	
	//FUNCTION - getHouseInput  - reads and stores data into houseType variables
	getHouseInput(houseType&);
	
	//FUNCTION - printHouseInfo - outputs data stored into variables of houseType
	printHouseInfo(houseType);
	
	return 0;

}

/***************************************************************************
* FUNCTION - getHouseInput - reads and stores data into houseType variables
***************************************************************************/
void getHouseInput(struct houseType&)
{
	cout    << "Please enter the style of the exterior of the house."
	getline(cin, houseType.style);
	cout << endl << endl;
	
	cout << "Please enter the number of bedrooms the house has.";
	cin  >> houseType.numOfBedrooms;
	cin.ignore(1000, '\n');
	cout << endl << endl;
	
	cout << "Please enter the number of bathrooms the house has.";
	cin  >> houseType.numOfBathrooms;
	cin.ignore(1000, '\n');
	cout << endl << endl;
	
	cout << "Please enter the year the house was built.";
	cin  >> houseType.yearBuilt;
	cin.ignore(1000, '\n');
	cout << endl << endl;
	
	cout << "Please enter the price of the house.";
	cin  >> houseType.price;
	cin.ignore(1000, '\n');
	cout << endl << endl;
	
	cout << "Please enter the tax percentage. \(only numbers, no percent sign\)";
	cin  >> houseType.tax;
	cin.ignore(1000, '\n');
	cout << endl << endl;
}

/*****************************************************************************
* FUNCTION - printHouseInfo - outputs data stored into variables of houseType
*****************************************************************************/
void printHouseInfo(struct houseType)
{
	cout << "Number of bedrooms: "  << houseType.numOfBedrooms  << endl;
	cout << "Number of bathrooms: " << houseType.numOfBathrooms << endl;
	cout << "Year built: "          << houseType.yearBuilt      << endl;
	cout << "Price: "               << houseType.price          << endl;
	cout << "Tax: "                 << houseType.tax            << endl;
};