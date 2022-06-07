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
		int    index;

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
		virtual void print(Person people, const int SIZE, int index);

		//DECONSTRUCTOR
		virtual ~Person(void)
	   {
		   cout << "OBJECT IS PRINTING." << endl;
	   }

};



class Student: public Person
{
	public:
       //setters
       void setGPA(double);
       void setID(int);
       void setClassification(string);
        
       //getters
       double getGPA();
       int    getID();
       string getClassification();
        
    private:
        int    id; //added every id 'should' be unique
        double gpa;
        string classification;

    public:
        //CONSTRUCTORS
     /*********************
 	 * FUNCTION: Student
 	 * ------------------
 	 * - initializes 3 of the variables to nothing
 	 * - receives nothing
 	 * RETURNS: nothing
 	 ********************/
        Student()
 	   {
 		   setGPA(0.0);
 		   setID(0);
 		   setClassification("not set");
 	   }

     /*********************
 	 * FUNCTION: Student
 	 * ------------------
 	 * - initializes 2 variables, but the rest to nothing
 	 * - receives nothing
 	 * RETURNS: nothing
 	 ********************/
        Student(string fName, string lName)
 	   {
 		   setFName(fName);
 		   setLName(lName);
 		   setGPA(0.0);
 		   setID(0);
 		   setClassification("not set");
 	   }

        /*********************
		 * FUNCTION: Student
		 * ------------------
		 * - initializes 5 variables to nothing
		 * - receives nothing
		 * RETURNS: nothing
		 ********************/
        // fName, lName, GPA, classification, id
        Student(string, string, double, string, int)
        {
        	setFName("not set");
        	setLName("not set");
        	setGPA(0.0);
        	setClassification("not set");
        	setID(0);
        }

        /*********************
		 * FUNCTION: Student
		 * ------------------
		 * - initializes 9 variables to nothing
		 * - receives nothing
		 * RETURNS: nothing
		 ********************/
        //Student(firstName, lastName, addr, ht, dob, sex, gpa, classification, id);
        Student(string, string, string, double, string, char,
                double, string, int)
        {
        	setFName("not set");
        	setLName("not set");
        	setAddress("not set");
        	setHeight(0.0);
        	setDOB("not set");
        	setGender('\0');
        	setGPA(0.0);
        	setClassification("not set");
        	setID(0);
        }

        virtual void print(Student students); //override the parents' print method

        //DECONSTRUCTOR
	   virtual ~Student(void)
	   {
		   cout << "OBJECT IS PRINTING." << endl;
	   }
};


class Professor: public Person
{
	private:
		int    employeeID;
		string department;
		string degree;
		
	public:
		//setters
		void setEmployeeID(int);
		void setDepartment(string);
		void setDegree(string);
		
		//getters
		int    getEmployeeID();
		string getDepartment();
		string getDegree();
	
		//CONSTRUCTORS
		/*********************
		 * FUNCTION: Professor
		 * ------------------
		 * - initializes 3 of the variables to nothing
		 * - receives nothing
		 * RETURNS: nothing
		 ********************/
		Professor()
		{
			setEmployeeID(0);
			setDepartment("not set");
			setDegree("not set");
		}
		
		/*********************
		 * FUNCTION: Professor
		 * ------------------
		 * - initializes 2 variables, but the rest to nothing
		 * - receives nothing
		 * RETURNS: nothing
		 ********************/
		Professor(string fName, string lName)
		{
			setFName(fName);
			setLName(lName);
			setEmployeeID(0);
			setDepartment("not set");
			setDegree("not set");
		}
		
		 /*********************
		 * FUNCTION: Professor
		 * ------------------
		 * - initializes 9 variables to nothing
		 * - receives nothing
		 * RETURNS: nothing
		 ********************/
		 //first name, last name, address, height, dob, gender, employeeID, department, degree
		Professor(string, string, string, double, string, char, int, string, string)
		{
			setFName("not set");
        	setLName("not set");
        	setAddress("not set");
        	setHeight(0.0);
        	setDOB("not set");
        	setGender('\0');
			setEmployeeID(0);
			setDepartment("not set");
			setDegree("not set");
		}
	
	virtual void print(Professor professors);

	//DECONSTRUCTOR
	virtual ~Professor(void)
   {
	   cout << "OBJECT IS PRINTING." << endl;
   }
};


#endif /* PERSON_H_ */
