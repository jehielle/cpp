#include "person.h"

/********************************************************************************
* FUNCTIONS (minus constructors)
* ------------------------------
* PERSON
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
* FUNCTIONS (minus constructors)
* ------------------------------
* STUDENT
********************************************************************************/
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
* FUNCTIONS (minus constructors)
* ------------------------------
* PROFESSOR
********************************************************************************/
/********************************************************************************
* SETTERS
********************************************************************************/
/*********************
 * FUNCTION: setEmployeeID
 * ------------------
 * - sets employee ID
 * - receives int x
 * RETURNS: nothing
 ********************/
void Professor::setEmployeeID(int x)
{
	employeeID = x;
}

/*********************
 * FUNCTION: setDepartment
 * ------------------
 * - sets department
 * - receives string x
 * RETURNS: nothing
 ********************/
void Professor::setDepartment(string x)
{
	department = x;
}

/*********************
 * FUNCTION: setDegree
 * ------------------
 * - sets degree
 * - receives string x
 * RETURNS: nothing
 ********************/
void Professor::setDegree(string x)
{
	degree = x;
}

/********************************************************************************
* GETTERS
********************************************************************************/
/*********************
 * FUNCTION: getEmployeeID
 * ------------------
 * - gets employee ID
 * - receives nothing
 * RETURNS: employeeID
 ********************/
int    Professor::getEmployeeID()
{
	return employeeID;
}

/*********************
 * FUNCTION: getDepartment
 * ------------------
 * - gets department
 * - receives nothing
 * RETURNS: department
 ********************/
string Professor::getDepartment()
{
	return department;
}

/*********************
 * FUNCTION: getDegree
 * ------------------
 * - gets degree
 * - receives nothing
 * RETURNS: degree
 ********************/
string Professor::getDegree()
{
	return degree;
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
void Person::print(Person people, const int SIZE, int index)
{
	cout << "First Name: "    << people[index].getFName();
	cout << endl;
	cout << "Last Name: "     << people[index].getLName();
	cout << endl;
	cout << "Address: "       << people[index].getAddress();
	cout << endl;
	cout << "Height: "        << people[index].getHeight() << " inches";
	cout << endl;
	cout << "Date of Birth: " << people[index].getDOB();
	cout << endl;
	cout << "Gender: "        << people[index].getGender();
	cout << endl;
}

/********************************************************************************
* FUNCTIONS - PRINT STUDENT
********************************************************************************/
/*********************
 * FUNCTION: print
 * ------------------
 * - prints all the info
 * - receives Student students
 * RETURNS: nothing
 ********************/
void Student::print(Student students)
{
	cout << "GPA: "    << students.getGPA();
	cout << endl;
	cout << "ID: "     << students.getID();
	cout << endl;
	cout << "Class: "  << students.getClassification();
	cout << endl;
}

/********************************************************************************
* FUNCTIONS - PRINT PROFESSOR
********************************************************************************/
/*********************
 * FUNCTION: print
 * ------------------
 * - prints all the info
 * - receives Professor professors
 * RETURNS: nothing
 ********************/
 void Professor::print(Professor professors)
 {
	cout << "Employee ID: " << professors.getEmployeeID();
	cout << endl;
	cout << "Department: "  << professors.getDepartment();
	cout << endl;
	cout << "Degree: "      << professors.getDegree();
	cout << endl;
 }
