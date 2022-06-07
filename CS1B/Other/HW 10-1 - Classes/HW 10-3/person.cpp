#include "person.h"

/********************************************************************************
* FUNCTIONS (minus constructors)
********************************************************************************/
/********************************************************************************
* SETTERS
********************************************************************************/
/*********************
 * FUNCTION: setFName
 * ------------------
 * - sets first name
 * - receives string x
 * RETURNS: nothing
 ********************/
void Person::setFName(string x)
{
	fName = x;
}

/*********************
 * FUNCTION: setLName
 * ------------------
 * - sets last name
 * - receives string x
 * RETURNS: nothing
 ********************/
void Person::setLName(string x)
{
	lName = x;
}

/*********************
 * FUNCTION: setAddress
 * ------------------
 * - sets address
 * - receives string x
 * RETURNS: nothing
 ********************/
void Person::setAddress(string x)
{
	address = x;
}

/*********************
 * FUNCTION: setHeight
 * ------------------
 * - sets height
 * - receives double x
 * RETURNS: nothing
 ********************/
void Person::setHeight(double x)
{
	height = x;
}

/*********************
 * FUNCTION: setDOB
 * ------------------
 * - sets date of birth
 * - receives string x
 * RETURNS: nothing
 ********************/
void Person::setDOB(string x)
{
	DOB = x;
}

/*********************
 * FUNCTION: setGender
 * ------------------
 * - sets gender
 * - receives char x
 * RETURNS: nothing
 ********************/
void Person::setGender(char x)
{
	gender = x;
}

/********************************************************************************
* GETTERS
********************************************************************************/
/*********************
 * FUNCTION: getFName
 * ------------------
 * - gets first name
 * - receives nothing
 * RETURNS: fName
 ********************/
string Person::getFName()
{
	return fName;
}

/*********************
 * FUNCTION: getFName
 * ------------------
 * - sets last name
 * - receives nothing
 * RETURNS: lName
 ********************/
string Person::getLName()
{
	return lName;
}

/*********************
 * FUNCTION: getAddress
 * ------------------
 * - sets address
 * - receives nothing
 * RETURNS: address
 ********************/
string Person::getAddress()
{
	return address;
}

/*********************
 * FUNCTION: getHeight
 * ------------------
 * - sets height
 * - receives nothing
 * RETURNS: height
 ********************/
double Person::getHeight()
{
	return height;
}

/*********************
 * FUNCTION: setFName
 * ------------------
 * - sets DOB
 * - receives nothing
 * RETURNS: DOB
 ********************/
string Person::getDOB()
{
	return DOB;
}

/*********************
 * FUNCTION: getGender
 * ------------------
 * - sets first name
 * - receives nothing
 * RETURNS: gender
 ********************/
char Person::getGender()
{
	return gender;
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
void Person::print(int count, Person people[])
{
	cout << "First Name: "    << people[count].getFName();
	cout << endl;
	cout << "Last Name: "     << people[count].getLName();
	cout << endl;
	cout << "Address: "       << people[count].getAddress();
	cout << endl;
	cout << "Height: "        << people[count].getHeight() << " inches";
	cout << endl;
	cout << "Date of Birth: " << people[count].getDOB();
	cout << endl;
	cout << "Gender: "        << people[count].getGender();
	cout << endl << endl;
}
