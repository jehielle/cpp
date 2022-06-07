/**************************************************************************
 *  AUTHOR     : Jehielle David
 *  HW #4      : recursion
 *  CLASS      : CS 1C
 *  SECTION    : Tu,Th 12:30-2:50pm
 *  DUE DATE   : 9-20-18
 **************************************************************************/
#ifndef HW06_H_
#define HW06_H_

#include<iostream>
#include<limits>
#include<algorithm>
#include <vector>

using namespace std;

//FUNCTION PROTOTYPES
void reverseIt(char charArray[], int start, int end);

/****************************************************
 * FUNCTIONS
 ***************************************************/
void reverseIt(char charArray[], int start, int end)
{
    if(start == end)
    {
       cout << charArray[start];
       cout << endl;
    }
    else
    {
		cout << charArray[end]; //starts from back, goes to front
		reverseIt(charArray, start, end-1);
    }

}

#endif /* HW06_H_ */
