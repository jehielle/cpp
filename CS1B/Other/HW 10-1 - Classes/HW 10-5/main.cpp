// ----------------------------------------------------------------------------
// File name: main.cpp                                                        -
// ----------------------------------------------------------------------------
// Creator's name and email: Jehielle David jdavid21@saddleback.edu           -
// Course-Section: CS1B                                                       -
// Creation Date: 4/10/18                                                     -
// Date of Last Modification: 4/17/18                                         -
// ----------------------------------------------------------------------------
// Purpose: "Classes" HW                                                      -
// ----------------------------------------------------------------------------
// Algorithm:                                                                 -
// Step 1: Hold information for 5 people, including their name, address, etc. -
// Step 2: Print out the information neatly.
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
// - count             integer      0                                         -
// - fName             string       nothing                                   -
// - lName             string       nothing                                   -
// - address           double       0.0                                       -
// - DOB               string       nothing                                   -
// - gender            char         nothing                                   -
// -                                                                          -
// ----------------------------------------------------------------------------

#include "person.h"

//MAIN
int main()
{
	Person  Shrek;
	Person  Donkey;
	Student Puss;
	Student Fiona;
	Student Dragon;
	
	cout << setprecision(2) << fixed;

	Shrek.setFName("Shrek");
	Shrek.setLName("The Ogre");
	Shrek.setAddress("The Swamp");
	Shrek.setHeight(80);
	Shrek.setDOB("05/18/01");
	Shrek.setGender('M');
	Shrek.print(Shrek);
	cout << endl;

	Donkey.setFName("Donkey");
	Donkey.setLName("The Donkey");
	Donkey.setAddress("Donkey and Dragon's House");
	Donkey.setHeight(40);
	Donkey.setDOB("05/18/01");
	Donkey.setGender('M');	
	Donkey.print(Donkey);
	cout << endl;

	Puss.setFName("Puss");
	Puss.setLName("In Boots");
	Puss.setAddress("Donkey and Dragon's House");
	Puss.setHeight(40);
	Puss.setDOB("05/18/01");
	Puss.setGender('M');
	Puss.setGPA(4.0);
	Puss.setID(101010);
	Puss.setClassification("Freshman");
    Puss.Person::print(Puss);
    Puss.print(Puss);

	Fiona.setFName("Fiona");
	Fiona.setLName("The Ogre's Wife");
	Fiona.setAddress("The Swamp");
	Fiona.setHeight(70);
	Fiona.setDOB("05/18/01");
	Fiona.setGender('F');
	Fiona.setGPA(4.2);
    Fiona.setID(101011);
    Fiona.setClassification("Sophomore");
    Fiona.Person::print(Fiona);
    Fiona.print(Fiona);
	
	Dragon.setFName("Dragon");
	Dragon.setLName("The Donkey's wife");
	Dragon.setAddress("The Swamp");
	Dragon.setHeight(120);
	Dragon.setDOB("05/18/01");
	Dragon.setGender('F');
	Dragon.setGPA(3.1);
	Dragon.setID(101012);
	Dragon.setClassification("Senior");
    Dragon.Person::print(Dragon);
    Dragon.print(Dragon);
	
	system("PAUSE");
	
	return 0;
}


