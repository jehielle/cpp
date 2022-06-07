#include "vehicle.h"

/********************************************************************************
* FUNCTIONS (minus constructors)
********************************************************************************/
/********************************************************************************
* SETTERS
********************************************************************************/
/*********************
 * FUNCTION: setMake
 * ------------------
 * - sets make
 * - receives string x
 * RETURNS: nothing
 ********************/
void Vehicle::setMake(string x)
{
	make = x;
}

/*********************
 * FUNCTION: setModel
 * ------------------
 * - sets model
 * - receives string x
 * RETURNS: nothing
 ********************/
void Vehicle::setModel(string x)
{
	model = x;
}

/*********************
 * FUNCTION: setYear
 * ------------------
 * - sets year
 * - receives int x
 * RETURNS: nothing
 ********************/
void Vehicle::setYear(int x)
{
	year = x;
}

/*********************
 * FUNCTION: setColor
 * ------------------
 * - sets color
 * - receives string x
 * RETURNS: nothing
 ********************/
void Vehicle::setColor(string x)
{
	color = x;
}

/*********************
 * FUNCTION: setDOB
 * ------------------
 * - sets date of birth
 * - receives string x
 * RETURNS: nothing
 ********************/
void Vehicle::setNumDoors(int x)
{
	numDoors = x;
}

/********************************************************************************
* GETTERS
********************************************************************************/
/*********************
 * FUNCTION: getMake
 * ------------------
 * - gets make
 * - receives nothing
 * RETURNS: make
 ********************/
string Vehicle::getMake()
{
	return make;
}

/*********************
 * FUNCTION: getModel
 * ------------------
 * - gets model
 * - receives nothing
 * RETURNS: model
 ********************/
string Vehicle::getModel()
{
	return model;
}

/*********************
 * FUNCTION: getYear
 * ------------------
 * - gets year
 * - receives nothing
 * RETURNS: year
 ********************/
int Vehicle::getYear()
{
	return year;
}

/*********************
 * FUNCTION: getColor
 * ------------------
 * - gets color
 * - receives nothing
 * RETURNS: color
 ********************/
string Vehicle::getColor()
{
	return color;
}

/*********************
 * FUNCTION: getNumDoors
 * ------------------
 * - gets numDoors
 * - receives nothing
 * RETURNS: numDoors
 ********************/
int Vehicle::getNumDoors()
{
	return numDoors;
}

/********************************************************************************
* FUNCTIONS - PRINT PERSON
********************************************************************************/
/*********************
 * FUNCTION: print
 * ------------------
 * - prints all the info
 * - receives int count, Person people[]
 * RETURNS: nothing
 ********************/
void Vehicle::print(int count, Vehicle vehicles[])
{
	cout << "Make: "       << vehicles[count].getMake();
	cout << endl;
	cout << "Model: "      << vehicles[count].getModel();
	cout << endl;
	cout << "Year: "       << vehicles[count].getYear();
	cout << endl;
	cout << "Color: "      << vehicles[count].getColor();
	cout << endl;
	cout << "# of Doors: " << vehicles[count].getNumDoors();
	cout << endl << endl;
}
