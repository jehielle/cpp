/*****************************************
 * AUTHOR: JEHIELLE DAVID
 * -------------------------------------
 * CS1C
 ****************************************/

#ifndef HW03_H_
#define HW03_H_

#include <string>
#include <iostream>
using namespace std;

/*********************************************************
 * BASE CLASS - DATE
 ********************************************************/
class Date
{
private:
	string month;
	string day;
	string year;

public:
/**********************
 * SETTERS
 **********************/
	void setMonth(string x)
	{
		month = x;
	}

	void setDay(string x)
	{
		day = x;
	}

	void setYear(string x)
	{
		year = x;
	}

/**********************
 * GETTERS
 **********************/
	string getMonth()
	{
		return month;
	}

	string getDay()
	{
		return day;
	}

	string getYear()
	{
		return year;
	}

	//DEFAULT CONSTRUCTOR
	Date()
	{
		setMonth("not set");
		setDay("not set");
		setYear("not set");
	}

	//NON-DEFAULT CONSTRUCTOR
	Date(string month, string day, string year)
	{
		setMonth(month);
		setDay(day);
		setYear(year);
	}

	~Date(void)
	{

	}

	void printDate(string m, string d, string y) const
	{
		cout << m + "/" + d + "/" + y;
	}

};

/*********************************************************
 * DERIVED CLASS - EMPLOYEE
 ********************************************************/
class Employee : public Date
{
private:
	string employeeName;
	int    employeeId;
	string phoneNum;
	int    age;
	char   gender;
	string jobTitle;
	string salary;
	string hireDate;

public:

/**********************
 * SETTERS
 **********************/
	void setEmpName(string x)
	{
		employeeName = x;
	}

	void setEmpId(int x)
	{
		employeeId = x;
	}

	void setPhoneNum(string x)
	{
		phoneNum = x;
	}

	void setAge(int x)
	{
		age = x;
	}

	void setGender(char x)
	{
		gender = x;
	}

	void setJob(string x)
	{
		jobTitle = x;
	}

	void setSalary(string x)
	{
		salary = x;
	}

	void setHireDate(string m, string d, string y)
	{
		hireDate = m + "/" + d + "/" + y;
	}

/**********************
 * GETTERS
 **********************/
	string getEmpName()
	{
		return employeeName;
	}

	int getEmpId()
	{
		return employeeId;
	}

	string getPhoneNum()
	{
		return phoneNum;
	}

	int getAge()
	{
		return age;
	}

	char getGender()
	{
		return gender;
	}

	string getJob()
	{
		return jobTitle;
	}

	string getSalary()
	{
		return salary;
	}

	string getHireDate()
	{
		return hireDate;
	}

	//DEFAULT CONSTRUCTOR
	Employee()
	{
		setEmpName("not set");
		setEmpId(0);
		setPhoneNum("not set");
		setAge(0);
		setGender('\0');
		setJob("not set");
		setSalary("not set");
		setHireDate("not", " ", "set");
	}

	//NON-DEFAULT CONSTRUCTOR
	Employee(string employeeName, int employeeId, string phoneNum, int age, char gender, string jobTitle, string salary,
			string day, string month, string year)
	{
		setEmpName(employeeName);
		setEmpId(employeeId);
		setPhoneNum(phoneNum);
		setAge(age);
		setGender(gender);
		setJob(jobTitle);
		setSalary(salary);
		setHireDate(day, month, year);
	}

	~Employee(void)
	{

	}

	//PRINT FUNCTION
	void printEmployee(Employee Eperson) const
	{
		cout << "Name: "         << Eperson.getEmpName();
		cout << endl;
		cout << "Employee ID: "  << Eperson.getEmpId();
		cout << endl;
		cout << "Phone Number: " << Eperson.getPhoneNum();
		cout << endl;
		cout << "Age: "          << Eperson.getAge();
		cout << endl;
		cout << "Gender: "       << Eperson.getGender();
		cout << endl;
		cout << "Job Title: "    << Eperson.getJob();
		cout << endl;
		cout << "Salary: "       << Eperson.getSalary();
		cout << endl;
		cout << "Hire Date: "    << Eperson.getHireDate();
		cout << endl;
	}

};

/*********************************************************
 * DERIVED CLASS - PROGRAMMER
 ********************************************************/
class Programmer : public Employee
{
private:
	int    deptNum;
	string supervisorName;
	int    raise;
	bool   cpp;
	bool   java;

public:
/**************
 * SETTERS
 **************/
	void setDeptNum(int x)
	{
		deptNum = x;
	}

	void setSupervisorName(string x)
	{
		supervisorName = x;
	}

	void setRaise(int x)
	{
		raise = x;
	}

	void setCpp(bool x)
	{
		cpp = x;
	}

	void setJava(bool x)
	{
		java = x;
	}

/**************
 * GETTERS
 **************/
	int    getDeptNum()
	{
		return deptNum;
	}

	string getSupervisorName()
	{
		return supervisorName;
	}

	int    getRaise()
	{
		return raise;
	}

	bool   getCpp()
	{
		return cpp;
	}

	bool   getJava()
	{
		return java;
	}

	//DEFAULT CONSTRUCTOR
	Programmer()
	{
		setDeptNum(0);
		setSupervisorName("not set");
		setRaise(0);
		setCpp(false);
		setJava(false);
	}

	//NON-DEFAULT CONSTRUCTOR
	Programmer(int deptNum, string supervisorName, int raise, bool cpp, bool java)
	{
		setDeptNum(deptNum);
		setSupervisorName(supervisorName);
		setRaise(raise);
		setCpp(cpp);
		setJava(java);
	}

	//DESTRUCTOR
	~Programmer(void)
	{

	}

	void printProgrammer(Programmer Pperson) const
	{
		cout << "Department: "      << Pperson.getDeptNum();
		cout << endl;
		cout << "Supervisor Name: " << Pperson.getSupervisorName();
		cout << endl;
		cout << "Raise %: "         << Pperson.getRaise();
		cout << endl;

		cout << "C++ Knowledge: ";
		if(Pperson.getCpp() == true)
		{
			cout << "Yes";
		}
		else
		{
			cout << "No";
		}
		cout << endl;

		cout << "Java Knowledge: ";
		if(Pperson.getJava() == true)
		{
			cout << "Yes";
		}
		else
		{
			cout << "No";
		}
		cout << endl;
	}
};

/*********************************************************
 * DERIVED CLASS - SOFTWAREARCHITECT
 ********************************************************/
class SoftwareArchitect : public Employee
{
private:
	int    deptNum;
	string supervisorName;
	int    raise;
	int    yrsExp;

public:
	/********************
	 * SETTERS
	 ********************/
	void setDeptNum(int x)
	{
		deptNum = x;
	}

	void setSupervisorName(string x)
	{
		supervisorName = x;
	}

	void setRaise(int x)
	{
		raise = x;
	}

	void setYrsExp(int x)
	{
		yrsExp = x;
	}

	/********************
	 * GETTERS
	 ********************/
	int getDeptNum()
	{
		return deptNum;
	}

	string getSupervisorName()
	{
		return supervisorName;
	}

	int getRaise()
	{
		return raise;
	}

	int getYrsExp()
	{
		return yrsExp;
	}

	//DEFAULT CONSTRUCTOR
	SoftwareArchitect()
	{
		setDeptNum(0);
		setSupervisorName("not set");
		setRaise(0);
		setYrsExp(0);
	}

	//NON-DEFAULT CONSTRUCTOR
	SoftwareArchitect(int deptNum, string supervisorName, int raise, int yrsExp)
	{
		setDeptNum(deptNum);
		setSupervisorName(supervisorName);
		setRaise(raise);
		setYrsExp(yrsExp);
	}

	//DESTRUCTOR
	~SoftwareArchitect(void)
	{

	}

	void printSoftArch(SoftwareArchitect SAperson) const
	{
		cout << "Department: "          << SAperson.getDeptNum();
		cout << endl;
		cout << "Supervisor Name: "     << SAperson.getSupervisorName();
		cout << endl;
		cout << "Raise %: "             << SAperson.getRaise();
		cout << endl;
		cout << "Years of Experience: " << SAperson.getYrsExp();
		cout << endl;
	}

};




#endif /* HW03_H_ */
