/***************************************************************************
 * AUTHER     : JJ David & Nikki Navid
 * STUDENT ID : 1083135 & 1074622
 * LAB #26    : Enumerated Types
 * CLASS      : CS1A
 * SECTION    : TTH: 1pm - 4:20pm
 * DUE DATE   : 11/28/17
 ***************************************************************************/

#ifndef MYHEADER_H_
#define MYHEADER_H_

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>

using namespace std;

//enumerated type Seasons for winter/spring/summer/fall
enum Seasons
{
	WINTER,
	SPRING,
	SUMMER,
	FALL
};


/***************************************************************************
 * PrintHeader
 * 	 This function receives an assignment name, type
 *   and number then outputs the appropriate header
 *   ==> returns nothing - This will output the class heading.
 **************************************************************************/
void PrintHeader(string asName,   // IN - assignment Name      – used for output
				 string userName, // IN - the programmers name - used for output
				 string userID,   // IN - the programmers Id   - used for output
		         string asNum,    // IN – assign. number       – used for output
				 char   asType);  // IN - assignment type
								  //    - (LAB or ASSIGN)      – used for output

/***************************************************************************
 * GetSeason
 * 	 This function displays the menu and validates the input of the user.
 *   ==> returns a character representing the season
 **************************************************************************/
char GetSeason();

/***************************************************************************
 * ConvertCharToSeason
 * 	 This function converts a character to the enumerated type (Seasons)
 *   ==> returns a variable of type Seasons
 **************************************************************************/
Seasons ConvertCharToSeason(char seasonChar); //IN - the char for the season

/***************************************************************************
 * ConvertSeasonToString
 * 	 This function converts the enumerated type (Seasons) to a string
 * 	 representing the seasons.
 *   ==> returns a variable of type string
 **************************************************************************/
string ConvertSeasonToString(Seasons seasonEnum); //IN - the enumerated type
												  //     representing the season

/***************************************************************************
 * ConvertSeasonToFruit
 * 	 This function converts the enumerated type (Seasons) to a string.
 *   ==> returns a string (the fruit type)
 **************************************************************************/
string ConvertSeasonToFruit(Seasons seasonEnum); //IN - the enumerated type
												 //     representing the season


#endif
