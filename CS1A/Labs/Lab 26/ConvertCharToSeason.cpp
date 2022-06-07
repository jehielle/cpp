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
 * FUNCTION ConvertCharToSeason
 *--------------------------------------------------------------------------
 * 	 This function converts a character to the enumerated type (Seasons)
 *   ==> returns a variable of type Seasons
 *--------------------------------------------------------------------------
 * PRE-CONDITIONS
 *	  seasonChar : the character for the season
 *
 * POST-CONDITIONS
 *	  ==> returns a variable of type Seasons
 ***************************************************************************/

Seasons ConvertCharToSeason(char seasonChar)
{
	Seasons seasonEnum;

	switch(seasonChar)
	{
	case 'W': seasonEnum = WINTER;
	break;

	case 'S': seasonEnum = SPRING;
	break;

	case 'U': seasonEnum = SUMMER;
	break;

	case 'F': seasonEnum = FALL;
	break;
	}

	return seasonEnum;
}
