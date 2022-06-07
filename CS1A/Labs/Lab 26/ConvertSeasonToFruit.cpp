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
 * FUNCTION ConvertSeasonToFruit
 *--------------------------------------------------------------------------
 * 	 This function converts the enumerated type (Seasons) to a string.
 *   ==> returns a string (the fruit type)
 *--------------------------------------------------------------------------
 * PRE-CONDITIONS
 *	  seasonEnum : the enumerated type representing the season
 *
 * POST-CONDITIONS
 *	  ==> returns a string (the fruit type)
 ***************************************************************************/

string ConvertSeasonToFruit(Seasons seasonEnum)
{

	string fruit;

	switch(seasonEnum)
	{
	case WINTER: fruit = "Kishu Mini Mandarin";
	break;

	case SPRING: fruit = "Blood Orange";
	break;

	case SUMMER: fruit = "Lane Navel Orange";
	break;

	case FALL: fruit = "Star Ruby Red Grapefruit";
	break;
	}

	return fruit;
}
