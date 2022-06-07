#ifndef PERSON_H_
#define PERSON_H_

#include <stdlib.h>
#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

/*
template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};

template <class Type>
class linkedListIterator
{
	public:
		linkedListIterator();
		//def constructor, postcondition: current = NULL;
		
		linkedListIterator(nodeType<Type> *ptr);
		//post condution - current = ptr;
		
		Type operator*();
		
		linkedListIterator(<Type> operator++();
		//this one is in ch 13 of malik book
		
		bool operator==(const linkedListIterator<Type>& right) const;
*/

//CLASSES
class BookData
{
	private:
		string bookTitle;
		string isbn;
		string author;
		string publisher;
		string dateAdded;
		int	   qtyOnHand;
		double wholesale;
		double retail;

	public:
		//setters
		void setBookTitle(string);
		void setIsbn(string);
		void setAuthor(string);
		void setPublisher(string);
		void setDateAdded(string);
		void setQtyOnHand(int);
		void setWholesale(double);
		void setRetail(double);

		//getters
		string getBookTitle();
		string getIsbn();
		string getAuthor();
		string getPublisher();
		string getDateAdded();
		int    getQtyOnHand();
		double getWholesale();
		double getRetail();

		//CONSTRUCTORS
		/*********************
		 * FUNCTION: BookData
		 * ------------------
		 * - initializes all of the variables to nothing
		 * - receives nothing
		 * RETURNS: nothing
		 ********************/
		BookData()
		{
			setBookTitle("not set");
			setIsbn("not set");
			setAuthor("not set");
			setPublisher("not set");
			setDateAdded("not set");
			setQtyOnHand(0);
			setWholesale(0);
			setRetail(0);
		}

		/*********************
		 * FUNCTION: BookData
		 * ------------------
		 * - initializes 2 variables, but the rest to nothing
		 * - receives nothing
		 * RETURNS: nothing
		 ********************/
		BookData(string bookTitle, string isbn)
		{
			setBookTitle(bookTitle);
			setIsbn(isbn);
			setAuthor("not set");
			setPublisher("not set");
			setDateAdded("not set");
			setQtyOnHand(0);
			setWholesale(0);
			setRetail(0);
		}

		/*********************
		 * FUNCTION: BookData
		 * ------------------
		 * - initializes all variables
		 * - receives nothing
		 * RETURNS: nothing
		 ********************/
		BookData(string bookTitle, string isbn, string author, string publisher, 
				 string dateAdded, int qtyOnHand, double wholesale, double retail)
		{
			setBookTitle(bookTitle);
			setIsbn(isbn);
			setAuthor(author);
			setPublisher(publisher);
			setDateAdded(dateAdded);
			setQtyOnHand(qtyOnHand);
			setWholesale(wholesale);
			setRetail(retail);
		}

		//PRINT FUNCTION
		virtual void print(BookData book, const int SIZE, int index);

		//DECONSTRUCTOR
		virtual ~BookData(void)
	   {
		   cout << "OBJECT IS PRINTING." << endl;
	   }

};


#endif /* PERSON_H_ */
