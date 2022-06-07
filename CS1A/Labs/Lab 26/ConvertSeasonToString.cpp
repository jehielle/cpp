/***************************************************************************
 * AUTHER     : JJ David & Nikki Navid
 * STUDENT ID : 1083135 & 1074622
 * LAB #26    : Enumerated Types
 * CLASS      : CS1A
 * SECTION    : TTH: 1pm - 4:20pm
 * DUE DATE   : 11/28/17
 ***************************************************************************/

#include "MyHeader.h"

/***************************************************************************
 * FUNCTION ConvertSeasonToString
 *--------------------------------------------------------------------------
 * 	 This function converts the enumerated type (Seasons) to a string
 * 	 representing the seasons.
 *   ==> returns a variable of type string
 *--------------------------------------------------------------------------
 * PRE-CONDITIONS
 *	  seasonEnum : the enumerated type representing the season
 *
 * POST-CONDITIONS
 *	  ==> returns a variable of type string
 ***************************************************************************/

string ConvertSeasonToString(Seasons seasonEnum)
{
	string seasonString;

	switch(seasonEnum)
	{
	case WINTER: seasonString = "winter";
	break;

	case SPRING: seasonString = "spring";
	break;

	case SUMMER: seasonString = "summer";
	break;

	case FALL: seasonString = "fall";
	break;
	}

	return seasonString;
}
