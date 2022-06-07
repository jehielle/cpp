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
* SETTERS
********************************************************************************/

/*********************
 * FUNCTION: setGPA
 * ------------------
 * - sets GPA
 * - receives double x
 * RETURNS: nothing
 ********************/
void Student::setGPA(double x)
{
	gpa = x;
}

/*********************
 * FUNCTION: setID
 * ------------------
 * - sets ID
 * - receives int x
 * RETURNS: nothing
 ********************/
void Student::setID(int x)
{
	id = x;
}

/*********************
 * FUNCTION: setClassification
 * ------------------
 * - sets classification
 * - receives string x
 * RETURNS: nothing
 ********************/
void Student::setClassification(string x)
{
	classification = x;
}

/********************************************************************************
* GETTERS
********************************************************************************/

/*********************
 * FUNCTION: getGPA
 * ------------------
 * - gets GPA
 * - receives nothing
 * RETURNS: gpa
 ********************/
double Student::getGPA()
{
	return gpa;
}

/*********************
 * FUNCTION: getID
 * ------------------
 * - gets ID
 * - receives nothing
 * RETURNS: ID
 ********************/
int    Student::getID()
{
	return id;
}

/*********************
 * FUNCTION: getClassification
 * ------------------
 * - gets classification
 * - receives nothing
 * RETURNS: classification
 ********************/
string Student::getClassification()
{
	return classification;
}

/********************************************************************************
* FUNCTIONS - PRINT PERSON
********************************************************************************/
/*********************
 * FUNCTION: print
 * ------------------
 * - prints all the info
 * - receives Person people
 * RETURNS: nothing
 ********************/
void Person::print(Person people)
{
	cout << "First Name: "    << people.getFName();
	cout << endl;
	cout << "Last Name: "     << people.getLName();
	cout << endl;
	cout << "Address: "       << people.getAddress();
	cout << endl;
	cout << "Height: "        << people.getHeight() << " inches";
	cout << endl;
	cout << "Date of Birth: " << people.getDOB();
	cout << endl;
	cout << "Gender: "        << people.getGender();
	cout << endl;
}

/********************************************************************************
* FUNCTIONS - PRINT STUDENT
********************************************************************************/
/*********************
 * FUNCTION: print
 * ------------------
 * - prints all the info
 * - receives student
 * RETURNS: nothing
 ********************/
void Student::print(Student students)
{
	cout << "GPA: "    << students.getGPA();
	cout << endl;
	cout << "ID: "     << students.getID();
	cout << endl;
	cout << "Class: "  << students.getClassification();
	cout << endl << endl;
}
