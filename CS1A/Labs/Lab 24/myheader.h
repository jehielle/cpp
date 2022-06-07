#ifndef MYHEADER_H_
#define MYHEADER_H_

#include <iostream>
#include <string>
using namespace std;

//PROTOTYPES
/******************************************************************************
 * FUNCTION PrintHeader
 * ____________________________________________________________________________
 * This function receives an assignment name, type, and number,
 * then outputs the appropriate header. It returns nothing.
 *****************************************************************************/
void PrintHeader(string asName,      // IN & OUT - name of the lab/assignment
				 int    asNum,       // IN & OUT - number of the lab/assignment
				 char   asType);	 // IN       - whether lab or assignment)
									 // 		   ('L' = Lab,
									 // 		    'A' = Assignment)

#endif	/* MYHEADER_H_*/
