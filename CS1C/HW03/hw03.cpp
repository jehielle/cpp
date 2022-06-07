/*****************************************
 * AUTHOR: JEHIELLE DAVID
 * -------------------------------------
 * CS1C
 ****************************************/

#include "hw03.h"

int main()
{
	Employee          defConstE;
	Programmer        defConstP;
	SoftwareArchitect defConstSA;

	//*************************************************************************************************************
	cout << "Create at least one employee object with the default constructor: "               << endl << endl;
	Employee();
	defConstE.Employee::printEmployee(defConstE); //print
	cout << endl << endl << endl;
	//*************************************************************************************************************

	//*************************************************************************************************************
	cout << "Create at least one employee object with the non-default constructor: "           << endl << endl;
	Employee jimmy("Jimmy Fallon", 12345, "949-555-1234", 40, 'M', "Comedian", "$100,000", "8", "31", "2014");
	jimmy.Employee::printEmployee(jimmy); //print
	cout << endl << endl << endl;
	//*************************************************************************************************************

	//*************************************************************************************************************
	cout << "Create at least one programmer object with the default constructor: "             << endl << endl;
	Programmer();
	defConstP.Programmer::printProgrammer(defConstP); //print
	cout << endl << endl << endl;
	//*************************************************************************************************************

	//*************************************************************************************************************
	cout << "Create at least one programmer object with the non-default constructor: "         << endl << endl;
	Employee samS("Sam Software", 54321, "819-123-4567", 21, 'M', "Programmer", "$223,000", "12", "24", "2011");
	Programmer sam(5432122, "Joe Boss", 4, true, false);
	samS.Employee::printEmployee(samS);   //print
	sam.Programmer::printProgrammer(sam); //print
	cout << endl << endl << endl;
	//*************************************************************************************************************

	//*************************************************************************************************************
	cout << "Create at least one software architect object with the default constructor: "     << endl << endl;
	SoftwareArchitect();
	defConstSA.SoftwareArchitect::printSoftArch(defConstSA); //print
	cout << endl << endl << endl;
	//*************************************************************************************************************

	//*************************************************************************************************************
	cout << "Create at least one software architect object with the non-default constructor: " << endl << endl;
	Employee alexA("Alex Arch", 88888, "819-123-4444", 31, 'M', "Architect", "$323,000", "12", "24", "2009");
	SoftwareArchitect alex(5434222, "Big Boss", 5, 4);
	alexA.Employee::printEmployee(alexA);        //print
	alex.SoftwareArchitect::printSoftArch(alex); //print
	cout << endl << endl << endl;
	//*************************************************************************************************************

	//*************************************************************************************************************
	cout << "Write code to test changing the data members of a CS1C employee: "                 << endl << endl;
	jimmy.Employee::setEmpName("Not Jimmy");
	jimmy.Employee::setEmpId(65);
	jimmy.Employee::setPhoneNum("867-530-NIIIIIIINE");
	jimmy.Employee::setAge(130);
	jimmy.Employee::setGender('F');
	jimmy.Employee::setJob("Haha Man");
	jimmy.Employee::setSalary("$1.00");
	jimmy.Employee::setHireDate("1", "1", "2001");

	jimmy.Employee::printEmployee(jimmy); //print
	cout << endl << endl << endl;
	//*************************************************************************************************************

	//*************************************************************************************************************
	cout << "Write code to test changing the data members of a Programmer class: "             << endl << endl;
	sam.Programmer::setDeptNum(2);
	sam.Programmer::setSupervisorName("Nunya Biznis");
	sam.Programmer::setRaise(0);
	sam.Programmer::setCpp(false);
	sam.Programmer::setJava(true);

	sam.Programmer::printProgrammer(sam); //print
	cout << endl << endl << endl;
	//*************************************************************************************************************

	//*************************************************************************************************************
	cout << "Write code to test changing the data members of a Software Architect class: "     << endl << endl;
	alex.SoftwareArchitect::setDeptNum(24);
	alex.SoftwareArchitect::setSupervisorName("Big Mac");
	alex.SoftwareArchitect::setRaise(2);
	alex.SoftwareArchitect::setYrsExp(1000);

	alex.SoftwareArchitect::printSoftArch(alex); //print
	cout << endl << endl << endl;
	//*************************************************************************************************************




	return 0;
}
