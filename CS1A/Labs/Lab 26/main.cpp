/***************************************************************************
 * AUTHER     : JJ David & Nikki Navid
 * STUDENT ID : 1083135 & 1074622
 * LAB #26    : Enumerated Types
 * CLASS      : CS1A
 * SECTION    : TTH: 1pm - 4:20pm
 * DUE DATE   : 11/28/17
 ***************************************************************************/

#include "MyHeader.h"

int main()
{

    string projectName;    // CALC-OUT - name of the project
    string programmerName; // CALC-OUT - programmers name
    string programmerID;   // CALC-OUT - programmers ID number
    string projectNum;     // CALC-OUT - number of the project
    char   projectType;    // CALC-OUT - type of project

    string fruitM;         // CALC & OUT - the fruit type
    char seasonCharM;      // CALC & OUT - the character representing the season
    Seasons seasonEnumM;   // CALC & OUT - the enumerated values for season
    string seasonStringM;  // CALC & OUT - the string representing each season

	// INTIALIZATIONS
    projectName    = "Enumerated Types";
    projectNum     = "26";
    projectType    = 'L';
    programmerID   = "1083135 & 1074622";
    programmerName = "JJ David & Nikki Navid";

    // OUTPUT - This will output the header
    PrintHeader(projectName,programmerName, programmerID,
    		    projectNum, projectType);

    //INPUT - displays the menu for the user to input a season
    seasonCharM = GetSeason();

    //PROCESSING - converts the character into a season
    seasonEnumM = ConvertCharToSeason(seasonCharM);

    //PROCESSING - converts the season into a string
    seasonStringM = ConvertSeasonToString(seasonEnumM);

    //PROCESSING - converts the season into a fruit
    fruitM = ConvertSeasonToFruit(seasonEnumM);

    //OUTPUT- outputs the season and fruit corresponding to user's input
    cout << endl;

    seasonCharM = toupper(seasonCharM);

    if(seasonCharM != 'X')
    {
		cout << "For " << seasonStringM << ", you might want to try a "
			 << fruitM << ".";
    }


	return 0;
}
