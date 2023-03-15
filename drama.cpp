// ---------------------------------------------- drama.cpp ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 3/10/23
// Date of Last Modification: 3/16/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Implementation file for derived class Drama
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Movie is the base class for Drama
//  -Sorted by director, then title
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include "drama.h"

//Default constructor for Drama 
Drama::Drama()
{
	month = 0;
	year = 0;
	title = "";
	director = "";
}

// -----------------------------------Drama()-----------------------------------
// Paramaterized constructor for Drama 
Drama::Drama(ifstream& infile) :Drama()
{
	string temp;

	getline(infile, temp, ',');
	setStock(stoi(temp));
	getline(infile, director, ',');
	director.erase(0, 1);//Removing front blank space
	getline(infile, title, ',');
	title.erase(0, 1);//Removing front blank space
	infile >> year;
	getline(infile, temp);

	setSort(director + ' ' + title);
	setDisplay(director + ',' + title + ',' + to_string(year) + ',');
}

Drama::~Drama() {}

//// -----------------------------------getYear-----------------------------------
//// Returns the year of the movie
//int Drama::getYear()
//{
//	return year;
//}
//
//// -----------------------------------getTitle-----------------------------------
//// Returns the title of the movie
//string Drama::getTitle()
//{
//	return title;
//}
//
//// -----------------------------------getStock-----------------------------------
//// Returns the stock of the movie
//int Drama::getStock()
//{
//	return stock;
//}
//
//// -----------------------------------getDirector-----------------------------------
//// Returns the name of the directory of the movie
//string Drama::getDirector()
//{
//	return director;
//}
//
//// -----------------------------------setStock-----------------------------------
//// Sets a new value for the stock depending on borrow/rent actions
//// Parameter: int - the new stock value
//bool Drama::setStock()
//{
//	if (stock != 0) {
//		stock--;
//		return true;
//	}
//	return false;
//}

//void Drama::setStock(int newStock)
//{
//	stock = newStock;
//	//stock += newStock;	// Add newStock to current stock
//}
//
//// VERSION 2
//// -----------------------------------getSort-----------------------------------
//// Returns the string to be sorted
//string Drama::getSort()
//{
//	return sort;
//}

/*
// VERSION 1

// -----------------------------------Operator==---------------------------------
// Overloading == operator
bool Drama::operator==(const Drama& rhs) const
{
	//if ((director == rhs.director) && (title == rhs.title)) { return true; }
	// If same director and title, lhs Drama is same than rhs Drama
	return (director == rhs.director) && (title == rhs.title);
}

// -----------------------------------Operator!=---------------------------------
// Overloading != operator
bool Drama::operator!=(const Drama& rhs) const
{
	return !(*this == rhs);
}

// -----------------------------------Operator>----------------------------------
// Overloading > operator
bool Drama::operator>(const Drama& rhs) const
{
	// If alphabetical order of lhs Director > rhs Director, no matter the year lhs is bigger
	if (director > rhs.director) {
		return true;
	} else if ((director == rhs.director) && (year > rhs.year)) {	// If same director and lhs year > rhs year
		return true;
	}
	// Return false in any other case
	return false;
}

// -----------------------------------Operator<----------------------------------
// Overloading < operator
bool Drama::operator<(const Drama& rhs) const
{
	// Return true if lhs not == nor > than rhs
	if (*this != rhs) {
		return !(*this > rhs);
	};
	// Return false if lhs == rhs
	return false;
}
*/

