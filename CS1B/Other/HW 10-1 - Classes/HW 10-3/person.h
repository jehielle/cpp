#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <windows.h>

using namespace std;

//CLASSES
class Person
{
	private:
		string fName;
		string lName;
		string address;
		double height; //in inches
		string DOB;
		char   gender;

	public:
		//setters
		void setFName(string);
		void setLName(string);
		void setAddress(string);
		void setHeight(double);
		void setDOB(string);
		void setGender(char);

		//getters
		string getFName();
		string getLName();
		string getAddress();
		double getHeight();
		string getDOB();
		char   getGender();

		//CONSTRUCTORS
		/*********************
		 * FUNCTION: Person
		 * ------------------
		 * - initializes all of the variables to nothing
		 * - receives nothing
		 * RETURNS: nothing
		 ********************/
		Person()
		{
			setFName("not set");
			setLName("not set");
			setAddress("not set");
			setHeight(0);
			setDOB("not set");
			setGender('\0');
		}

		/*********************
		 * FUNCTION: Person
		 * ------------------
		 * - initializes 2 variables, but the rest to nothing
		 * - receives nothing
		 * RETURNS: nothing
		 ********************/
		Person(string fName, string lName)
		{
			setFName(fName);
			setLName(lName);
			setAddress("not set");
			setHeight(0);
			setDOB("not set");
			setGender('\0');
		}

		/*********************
		 * FUNCTION: Person
		 * ------------------
		 * - initializes all variables
		 * - receives nothing
		 * RETURNS: nothing
		 ********************/
		Person(string fName, string lName, string address, double height, string DOB, char gender)
		{
			setFName(fName);
			setLName(lName);
			setAddress(address);
			setHeight(height);
			setDOB(DOB);
			setGender(gender);
		}

		//PRINT FUNCTION
		void print(int count, Person people[]);


};


#endif /* PERSON_H_ */
