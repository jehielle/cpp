#include "vehicle.h"

/********************************************************************************
* FUNCTIONS (minus constructors) - VEHICLE
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
* FUNCTIONS (minus constructors) - TRUCK
********************************************************************************/
/********************************************************************************
* SETTERS
********************************************************************************/
/*********************
 * FUNCTION: setBedSize
 * ------------------
 * - sets bedSize
 * - receives string x
 * RETURNS: nothing
 ********************/
void Truck::setBedSize(string x)
{
	bedSize = x;
}

/*********************
 * FUNCTION: setTowingCapacity
 * ------------------
 * - sets towingCapacity
 * - receives double x
 * RETURNS: nothing
 ********************/
void Truck::setTowingCapacity(double x)
{
	towingCapacity = x;
}

/*********************
 * FUNCTION: setNumberOfWheels
 * ------------------
 * - sets numberOfWheels
 * - receives int x
 * RETURNS: nothing
 ********************/
void Truck::setNumberOfWheels(int x)
{
	numberOfWheels = x;
}

/********************************************************************************
* GETTERS
********************************************************************************/
/*********************
 * FUNCTION: getBedSize
 * ------------------
 * - gets bedSize
 * - receives nothing
 * RETURNS: bedSize
 ********************/
string Truck::getBedSize()
{
	return bedSize;
}

/*********************
 * FUNCTION: getTowingCapacity
 * ------------------
 * - gets towingCapacity
 * - receives nothing
 * RETURNS: towingCapacity
 ********************/
double Truck::getTowingCapacity()
{
	return towingCapacity;
}

/*********************
 * FUNCTION: getNumberOfWheels
 * ------------------
 * - gets numberOfWheels
 * - receives nothing
 * RETURNS: numberOfWheels
 ********************/
int Truck::getNumberOfWheels()
{
	return numberOfWheels;
}


/********************************************************************************
* FUNCTIONS (minus constructors) - CAR
********************************************************************************/
/********************************************************************************
* SETTERS
********************************************************************************/
/*********************
 * FUNCTION: setTrunkSize
 * ------------------
 * - sets trunk size
 * - receives double x
 * RETURNS: nothing
 ********************/
void Car::setTrunkSize(double x)
{
	trunkSize = x;
}

/********************************************************************************
* GETTERS
********************************************************************************/
/*********************
 * FUNCTION: getTrunkSize
 * ------------------
 * - gets trunkSize
 * - receives nothing
 * RETURNS: trunkSize
 ********************/
double Car::getTrunkSize()
{
	return trunkSize;
}


/********************************************************************************
* FUNCTIONS - PRINT VEHICLE
********************************************************************************/
/*********************
 * FUNCTION: print
 * ------------------
 * - prints all the info
 * - receives
 * RETURNS: nothing
 ********************/
void Vehicle::print(Vehicle vehicle[], const int SIZE, int count)
{
	cout << "Make: "       << vehicle[count].getMake();
	cout << endl;
	cout << "Model: "      << vehicle[count].getModel();
	cout << endl;
	cout << "Year: "       << vehicle[count].getYear();
	cout << endl;
	cout << "Color: "      << vehicle[count].getColor();
	cout << endl;
	cout << "# of Doors: " << vehicle[count].getNumDoors();
	cout << endl << endl;
}
