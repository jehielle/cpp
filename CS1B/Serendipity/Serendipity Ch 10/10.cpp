#include "10.h"

/********************************************************************************
* FUNCTIONS (minus constructors)
* ------------------------------
* BOOKDATA
********************************************************************************/
/********************************************************************************
* SETTERS
********************************************************************************/
/*********************
 * FUNCTION: setBookTitle
 * ------------------
 * - sets bookTitle
 * - receives string x
 * RETURNS: nothing
 ********************/
void BookData::setBookTitle(string x)
{
	bookTitle = x;
}

/*********************
 * FUNCTION: setIsbn
 * ------------------
 * - sets isbn
 * - receives string x
 * RETURNS: nothing
 ********************/
void BookData::setIsbn(string x)
{
	isbn = x;
}

/*********************
 * FUNCTION: setAuthor
 * ------------------
 * - sets author
 * - receives string x
 * RETURNS: nothing
 ********************/
void BookData::setAuthor(string x)
{
	author = x;
}

/*********************
 * FUNCTION: setPublisher
 * ------------------
 * - sets publisher
 * - receives string x
 * RETURNS: nothing
 ********************/
void BookData::setPublisher(string x)
{
	publisher = x;
}

/*********************
 * FUNCTION: setDateAdded
 * ------------------
 * - sets dateAdded
 * - receives string x
 * RETURNS: nothing
 ********************/
void BookData::setDateAdded(string x)
{
	dateAdded = x;
}

/*********************
 * FUNCTION: setQtyOnHand
 * ------------------
 * - sets qtyOnHand
 * - receives int x
 * RETURNS: nothing
 ********************/
void BookData::setQtyOnHand(int x)
{
	qtyOnHand = x;
}

/*********************
 * FUNCTION: setWholesale
 * ------------------
 * - sets wholesale
 * - receives double x
 * RETURNS: nothing
 ********************/
void BookData::setWholesale(double x)
{
	wholesale = x;
}

/*********************
 * FUNCTION: setRetail
 * ------------------
 * - sets retail
 * - receives double x
 * RETURNS: nothing
 ********************/
void BookData::setRetail(double x)
{
	retail = x;
}



/********************************************************************************
* GETTERS
********************************************************************************/
/*********************
 * FUNCTION: getBookTitle
 * ------------------
 * - gets BookTitle
 * - receives nothing
 * RETURNS: bookTitle
 ********************/
string BookData::getBookTitle()
{
	return bookTitle;
}

/*********************
 * FUNCTION: getIsbn
 * ------------------
 * - gets isbn
 * - receives nothing
 * RETURNS: isbn
 ********************/
void BookData::getIsbn()
{
	return isbn;
}

/*********************
 * FUNCTION: getAuthor
 * ------------------
 * - gets author
 * - receives nothing
 * RETURNS: author
 ********************/
void BookData::getAuthor()
{
	return author;
}

/*********************
 * FUNCTION: getPublisher
 * ------------------
 * - gets publisher
 * - receives nothing
 * RETURNS: nothing
 ********************/
void BookData::getPublisher()
{
	return publisher;
}

/*********************
 * FUNCTION: getDateAdded
 * ------------------
 * - gets dateAdded
 * - receives nothing
 * RETURNS: nothing
 ********************/
void BookData::getDateAdded()
{
	return dateAdded;
}

/*********************
 * FUNCTION: getQtyOnHand
 * ------------------
 * - gets qtyOnHand
 * - receives nothing
 * RETURNS: nothing
 ********************/
void BookData::getQtyOnHand()
{
	return qtyOnHand;
}

/*********************
 * FUNCTION: getWholesale
 * ------------------
 * - gets wholesale
 * - receives nothing
 * RETURNS: nothing
 ********************/
void BookData::getWholesale()
{
	return wholesale;
}

/*********************
 * FUNCTION: getRetail
 * ------------------
 * - gets retail
 * - receives nothing
 * RETURNS: nothing
 ********************/
void BookData::getRetail()
{
	return retail;
}






/********************************************************************************
* FUNCTIONS - PRINT BOOKDATA
********************************************************************************/
/*********************
 * FUNCTION: print
 * ------------------
 * - prints all the info
 * - receives BookData book
 * RETURNS: nothing
 ********************/
void BookData::print(BookData book, const int SIZE, int index)
{
	cout << "print";
}
