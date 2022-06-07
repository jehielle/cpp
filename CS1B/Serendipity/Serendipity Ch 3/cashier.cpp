// ----------------------------------------------------------------------------
// File name: cashier.cpp                                                     -
// Project name: Serendipity                                                  -
// ----------------------------------------------------------------------------
// Creator's name and email: Jehielle David jdavid21@saddleback.edu           -
// Course-Section: CS1B                                                       -
// Creation Date: 1/17/18                                                     -
// Date of Last Modification: 1/17/18                                         -
// ----------------------------------------------------------------------------
// Purpose: Serendipity                                                       -
// ----------------------------------------------------------------------------
// Algorithm:                                                                 -
// Step 1: Let the user enter values (date, quantity, ISBN, title, price).    -
// Step 2: Calculate merchandise total and 6% sales tax.                      -
// Step 3: Show a sales slip that includes subtotal, tax, and total.          -
// ----------------------------------------------------------------------------
// -                          DATA DICTIONARY                                 -
// - CONSTANTS                                                                -
// -                                                                          -
// - NAME              DATA TYPE    VALUE                                     -
// - ---------------   ----------   --------                                  -
// - HORIZONTAL_LINE   integer      51                                        -
// -                                                                          -
// - VARIABLES                                                                -
// -                                                                          -
// - NAME              DATA TYPE    INITIAL VALUE                             -
// - ---------------   ----------   -------------                             -
// - date              string       nothing                                   -
// - isbn              string       nothing                                   -
// - price             float        0.0                                       -
// - subtotal          float        0.0                                       -
// - tax               float        0.0                                       -
// - title             string       nothing                                   -
// - total             float        0.0                                       -
// - quantity          integer      0                                         -
// ----------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	const int HORIZONTAL_LINE = 78;

	string date;
	string isbn;
	float price;
	float subtotal;
	float tax;
	string title;
	float total;
	int quantity;

	// INPUT FROM USER
	cout << left
		 << "Serendipity Booksellers\n"
		 << "Cashier Module\n\n";

	cout << "Date: ";
	getline(cin, date);

	cout << "Quantity of Book: ";
	cin  >> quantity;
	cin.ignore(1000, '\n');

	cout << "ISBN: ";
	getline(cin, isbn);

	cout << "Title: ";
	getline(cin, title);

	cout << "Price: ";
	cin  >> price;

	cout << endl << endl << endl;

	// CALCULATION FOR SALES SLIP
	subtotal = quantity * price;
	tax      = subtotal * 0.06;
	total    = subtotal + tax;

	// SALES SLIP
	cout << "Serendipity Booksellers\n\n";

	cout << "Date: " << date
		 << endl << endl;


    cout << setw(5)  << "Qty"
		 << setw(15) << "ISBN"
		 << setw(22) << "Title"
		 <<	setw(12) << "Price"
		 <<	            "Total"
		 << endl;

    // LINE
	cout << right
		 << setfill('_')
		 << setw(HORIZONTAL_LINE) << " "
		 << endl;
	cout << setfill(' ')
		 << endl;

	cout << fixed << showpoint << setprecision(2);

	// VALUES OF QTY, ISBN, TITLE, PRICE, AND TOTAL
	cout << left
		 << setw(5)  << quantity
		 << setw(15) << isbn
		 << setw(21) << title
		 << "$ "
		 << setw(10) << price
		 << "$ "
		 << 			subtotal;

	cout << endl << endl;

	// SUBTOTAL, TAX, AND TOTAL
	cout << right
		 << setw(20) << "Subtotal"
		 << setw(35) << "$ "<<  subtotal
		 << endl

		 << setw(15) << "Tax"
		 << setw(40) << "$ " << tax
		 << endl

		 << setw(17) << "Total"
		 << setw(38) << "$ " << total
		 << endl << endl;

	cout << setw(40)
		 << "Thank You for Shopping at Serendipity!\n";


	return 0;
}




