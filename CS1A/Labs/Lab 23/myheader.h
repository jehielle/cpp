/******************************************************************************
 * AUTHOR        : JJ David, Nina Brock
 * STUDENT ID    : 1083135, 378941
 * LAB #23       : Functions - Rock Paper Scissors
 * CLASS	     : CS1A
 * SECTION	     : TTh: 1pm
 * DUE DATE	     : 11/14/17
 *****************************************************************************/

#ifndef MYHEADER_H_
#define MYHEADER_H_

#include <iostream> // for cin, cout
#include <iomanip>  // for setws, fixed, setprecision
#include <stdlib.h> // for srand, rand
#include <time.h>   // for time
#include <string>   // for strings
#include <cstring>  // for strn cpy

using namespace std;

void GetInput(string &name, int &rounds);
char GetAndCheckPlay();
char GetComputerPlay();
void OutputChoices(char uPlay, char cPlay, string name);
bool CheckWin(char uPlay, char cPlay);
void OutputWin(string name, bool userWin);
void OutputMatchWinner(string name, double percentWon, double percentLost);
void PrintHeader(string asName, int asNum, char asType);


#endif /* MYHEADER_H_ */
