// ----------------------------------------------------------------------------
// File name: exam1.cpp                                                       -
// ----------------------------------------------------------------------------
// Creator's name and email: Jehielle David jdavid21@saddleback.edu           -
// Course-Section: CS1B                                                       -
// Creation Date: 3/1/18                                                      -
// Date of Last Modification: 3/1/18                                          -
// ----------------------------------------------------------------------------
// Purpose: Exam 1                                                            -
// ----------------------------------------------------------------------------
// Algorithm:                                                                 -
// Step 1: Read information from the files.                                   -
// Step 2: Prompt the user for a student ID to enter in.                      -
// Step 3: Find the data for the student that was searched for.               -
// Step 4: If some data was missing or student ID not found, display error.   -
// ----------------------------------------------------------------------------
// -                          DATA DICTIONARY                                 -
// - CONSTANTS                                                                -
// -                                                                          -
// - NAME              DATA TYPE    VALUE                                     -
// - ---------------   ----------   --------                                  -
// - STUDENT_COUNT     const int    20                                        -
// - CITY_COUNT        const int    88                                        -
// -                                                                          -
// - VARIABLES                                                                -
// -                                                                          -
// - NAME              DATA TYPE    INITIAL VALUE                             -
// - ---------------   ----------   -------------                             -
// - id                int          input from user                           -
// - studentFound      int          value from a function                     -
// - cityDemoFound     int          value from a function                     -
// - isCityDemoFound   bool         value from a function                     -
// - zipcode[]         int          value from file                           -
// - population[]      int          value from file                           -
// - city[]            string       value from file                           -
// - studentId[]       int          value from file                           -
// - studentName[]     string       value from file                           -
// - studentClass[]    int          value from file                           -
// - studentZipcode[]  int          value from file                           -
// -                                                                          -
// ----------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <limits>

using namespace std;

enum classification
{
	FRESHMAN,
	SOPHOMORE,
	JUNIOR,
	SENIOR
};

namespace classArray
{
	string myClass[4] = {"Freshman", "Sophomore", "Junior", "Senior"};
}

using namespace classArray;

//CONSTANTS
const int STUDENT_COUNT = 20;
const int CITY_COUNT    = 88;

//FUNCTION PROTOTYPES
void ReadFileIntoArrays(int zipcode[CITY_COUNT],				   // zipcode array
						int population[CITY_COUNT],			   	   // population array
						string city[CITY_COUNT],			  	   // city array
						int studentId[STUDENT_COUNT], 			   // student id array
						string studentName[STUDENT_COUNT],		   // student name array
						int studentClass[STUDENT_COUNT],		   // student classification array
						int studentZipcode[STUDENT_COUNT]);		   // student zipcode array
int SearchArrayID(int searchName,
				  int studentId[STUDENT_COUNT]);
int SearchArrayCityDemo(int indexOfStudent,
						int zipcode[CITY_COUNT],
						int studentZipcode[STUDENT_COUNT]);
void OutputData(int index,								   // index of student found
				int zipcode[CITY_COUNT],				   // zipcode array
				int population[CITY_COUNT],			   	   // population array
				string city[CITY_COUNT],			  	   // city array
				int studentId[STUDENT_COUNT], 			   // student id array
				string studentName[STUDENT_COUNT],		   // student name array
				int studentClass[STUDENT_COUNT],		   // student classification array
				int studentZipcode[STUDENT_COUNT], 		   // student zipcode array
				int cityDemoFound,
				bool isCityDemoFound);


//MAIN
int main()
{
	int id;  		  // student ID input from user
	int studentFound; //index of student found
	int cityDemoFound;// index of student's city demographics found
	bool isCityDemoFound;

	//ARRAYS FROM CITY.DAT
	int zipcode[CITY_COUNT];	 // zipcode array
	int population[CITY_COUNT];	 // population array
	string city[CITY_COUNT];     // city array

	//ARRAYS FROM STUDENT.DAT
	int studentId[STUDENT_COUNT]; 			   // student id array
	string studentName[STUDENT_COUNT];		   // student name array
	int studentClass[STUDENT_COUNT];		   // student classification array
	int studentZipcode[STUDENT_COUNT]; 		   // student zipcode array


	//CLEAR THE SCREEN
	system("CLS");

 	//FUNCTION - ReadFileIntoArrays
	ReadFileIntoArrays(zipcode, population, city, studentId, studentName, studentClass, studentZipcode);

	cout << "SADDLEBACK STUDENT DEMOGRAPHIC LOOK UP\n"
			"ENTER STUDENT ID (-1 to Quit program)\n";
	cin  >> id;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl;

	while(id != -1)
	{
		//FUNCTION - SearchArrayID
		studentFound = SearchArrayID(id, studentId);

		if(studentFound == STUDENT_COUNT)
		{
			cout << "STUDENT DOES NOT EXIST IN OUR DATABASE.\n\n";
		}
		else
		{
			cout << "STUDENT FOUND\n\n";

			//FUNCTION - SearchArrayCityDemo
			cityDemoFound = SearchArrayCityDemo(studentFound, zipcode, studentZipcode);

			if(cityDemoFound == CITY_COUNT)
			{
				isCityDemoFound = false;
			}
			else
			{
				isCityDemoFound = true;
			}
			
		//FUNCTION - OutputData
		OutputData(studentFound, zipcode, population, city,	studentId, studentName, studentClass, studentZipcode, cityDemoFound, isCityDemoFound);
		cout << endl << endl;
		}
		
		//PAUSE AND CLS
		system("PAUSE");
		system("CLS");
		
		cout << "SADDLEBACK STUDENT DEMOGRAPHIC LOOK UP\n"
				"ENTER STUDENT ID (-1 to Quit program)\n";
		cin  >> id;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl;

	}



	return 0;
}

/******************************************************************************
 *
 * ------------------------------FUNCTIONS------------------------------------
 *
 *****************************************************************************/

/******************************************************************************
 * FUNCTION - ReadFileIntoArrays
 *****************************************************************************/
void ReadFileIntoArrays(int zipcode[CITY_COUNT],				   // zipcode array
						int population[CITY_COUNT],			   	   // population array
						string city[CITY_COUNT],			  	   // city array
						int studentId[STUDENT_COUNT], 			   // student id array
						string studentName[STUDENT_COUNT],		   // student name array
						int studentClass[STUDENT_COUNT],		   // student classification array
						int studentZipcode[STUDENT_COUNT]) 		   // student zipcode array
{
	ifstream finCity;	 //input file for city
	ifstream finStudent; //input file for student
	int index;

	//OPEN FILES
	finCity.open("city.dat");
	finStudent.open("student.dat");

	//READS IN DATA FROM CITY.DAT INTO ARRAYS
	for(index = 0; index < CITY_COUNT; index++)
	{
		finCity >> zipcode[index];
		finCity >> population[index];
		getline(finCity, city[index]);
	}

	//READS IN DATA FROM STUDENT.DAT INTO ARRAYS
	for(index = 0; index < STUDENT_COUNT; index++)
	{
		finStudent >> studentId[index];
		getline(finStudent, studentName[index]);
		finStudent >> studentClass[index];
		finStudent >> studentZipcode[index];
	}

	//CLOSE FILES
	finCity.close();
	finStudent.close();

}

/******************************************************************************
 * FUNCTION - SearchArrayID
 *****************************************************************************/
int SearchArrayID(int searchName, int studentId[STUDENT_COUNT])
{
	int index;
	bool found;

	index = 0;
	found = false;

	while(index < STUDENT_COUNT && !found)
	{
		if(studentId[index] == searchName)
		{
			found = true;
		}
		else
		{
			index++;
		}//END IF THEN ELSE
	}//END WHILE

	return index;
}

/******************************************************************************
 * FUNCTION - SearchArrayCityDemo
 *****************************************************************************/
int SearchArrayCityDemo(int indexOfStudent, int zipcode[CITY_COUNT], int studentZipcode[STUDENT_COUNT])
{
	int indexOfArray;
	bool found;

	indexOfArray = 0;
	found        = false;

	while(indexOfArray < CITY_COUNT && !found)
	{
		if(studentZipcode[indexOfStudent] == zipcode[indexOfArray])
		{
			found = true;
		}
		else
		{
			indexOfArray++;
		}//END IF THEN ELSE
	}//END WHILE

	return indexOfArray;

}

/******************************************************************************
 * FUNCTION - OutputData
 *****************************************************************************/
void OutputData(int index,								   // index of student found
				int zipcode[CITY_COUNT],				   // zipcode array
				int population[CITY_COUNT],			   	   // population array
				string city[CITY_COUNT],			  	   // city array
				int studentId[STUDENT_COUNT], 			   // student id array
				string studentName[STUDENT_COUNT],		   // student name array
				int studentClass[STUDENT_COUNT],		   // student classification array
				int studentZipcode[STUDENT_COUNT], 		   // student zipcode array
				int cityDemoFound,
				bool isCityDemoFound)
{
	cout << left;
	cout << setw(21) << "NAME";
	cout << setw(17) << "CLASSIFICATION";
	cout << setw(23) << "CITY";
	cout << setw(11) << "ZIPCODE";
	cout << setw(10) << "POPULATION";
	cout << endl;

	cout << setfill('=') << setw(20) << "=";
	cout << setfill(' ');
	cout << " ";

	cout << setfill('=') << setw(16) << "=";
	cout << setfill(' ');
	cout << " ";

	cout << setfill('=') << setw(22) << "=";
	cout << setfill(' ');
	cout << " ";

	cout << setfill('=') << setw(10)  << "=";
	cout << setfill(' ');
	cout << " ";

	cout << setfill('=') << setw(10) << "=";
	cout << setfill(' ');
	cout << endl;

	cout << setw(21) << studentName[index];
	cout << setw(16) << classArray::myClass[studentClass[index]];

	if(isCityDemoFound == true)
	{
		cout << setw(24) << city[cityDemoFound];
		cout << setw(11) << studentZipcode[index];
		cout << setw(10) << population[cityDemoFound];
	}
	else //if false
	{
		cout << setw(24) << " **ERROR**";
		cout << setw(11)  << studentZipcode[index];
		cout << setw(10) << "**ERROR**";
	}

}

