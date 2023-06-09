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

// -----------------------------------Drama()-----------------------------------
// Default constructor for drama 
Drama::Drama()
{
	month = 0;
	year = 0;
	title = "";
	director = "";
}

Drama::Drama(string sortInput) :Drama()
{
	sort = sortInput;
}

// -----------------------------------Drama()-----------------------------------
// Paramaterized constructor for Drama. Sets information from file into private
// data members
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
	sort = director + ' ' + title;
	//setSort(director + ' ' + title);	// Used to sort in BST
	// Sets movie information to be displayed
	setDisplay(director + ',' + title + ',' + to_string(year) + ',');
}

Drama::~Drama() {}

//-----------------------------OVERLOADED OPERATORS------------------------------

// -----------------------------------Operator==---------------------------------
// Overloading == operator

bool Drama::operator==(const Movie& rhs) const
{
	const Drama& movCom = static_cast<const Drama&> (rhs);
	return sort == movCom.sort;
}

// -----------------------------------Operator!=---------------------------------
// Overloading != operator
bool Drama::operator!=(const Movie& rhs) const
{
	return !(*this == rhs);
}

// -----------------------------------Operator>----------------------------------
// Overloading > operator
bool Drama::operator>(const Movie& rhs) const
{
	const Drama& movCom = static_cast<const Drama&> (rhs);
	return (sort > movCom.sort);
}

bool Drama::operator<(const Movie& rhs) const
{
	const Drama& movCom = static_cast<const Drama&> (rhs);
	return (sort < movCom.sort);
}

// -----------------------------------getSort()-----------------------------------
// Gets variable sort. Sort is used to sort movies in BST
string Drama::getSort()
{
	return sort;
}
