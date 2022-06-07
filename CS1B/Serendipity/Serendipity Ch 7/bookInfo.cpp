#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	const int CENTER_TITLE    = 25;

	string isbn;
	string title;
	string author;
	string publisher;
	string date;
	int    qty;
	double wholesale;
	double retail;
	
	cout << "Please enter isbn: ";
	getline(cin, isbn);
	
	cout << "\nPlease enter title: ";
	getline(cin, title);
	
	cout << "\nPlease enter author: ";
	getline(cin, author);
	
	cout << "\nPlease enter publisher: ";
	getline(cin, publisher);
	
	cout << "\nPlease enter date: ";
	getline(cin, date);
	
	cout << "\nPlease enter quantity: ";
	cin  >> qty;
	cin.ignore(1000, '\n');
	
	cout << "\nPlease enter wholesale: ";
	cin  >> wholesale;
	cin.ignore(1000, '\n');
	
	cout << "\nPlease enter retail: ";
	cin  >> retail;
	cin.ignore(1000, '\n');

	cout << endl;
	cout << setw(CENTER_TITLE) << "Serendipity "
		 << left
		 << setw(CENTER_TITLE) << "Booksellers"
		 << endl;

	cout << right << setw(21)  << "Book "
		 << left  << setw(29)  << "Information"
		 << right
		 << endl  << endl;
		 
	cout << setw(8)  << "ISBN: "             << isbn      << endl;

	cout << setw(9)  << "Title: "            << title     << endl;

	cout << setw(10) << "Author: "           << author    << endl;

	cout << setw(13) << "Publisher: "        << publisher << endl;

	cout << setw(14) << "Date Added: "       << date      << endl;

	cout << setw(20) << "Quantity-On-Hand: " << qty       << endl;

	cout << setw(18) << "Wholesale Cost: "   << wholesale << endl;

	cout << setw(16) << "Retail Price: "     << retail    << endl << endl;

	return 0;
}