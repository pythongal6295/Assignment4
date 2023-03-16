// ---------------------------------------------- comedy.cpp ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 3/10/23
// Date of Last Modification: 3/16/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Implementation file for derived class Comedy
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Movie is the base class for Comedy
//  -Sorted by title, then year it was released
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include "comedy.h"

// -----------------------------------Comedy()-----------------------------------
// Default constructor for Comedy
Comedy::Comedy()
{
	year = 0;
	title = "";
	director = "";
}

Comedy::Comedy(string sortInput) :Comedy()
{
	sort = sortInput;
}

// -----------------------------------Comedy-----------------------------------
// Paramaterized constructor for Comedy, ifstream parameter type
Comedy::Comedy(ifstream& infile)
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

	sort = title + ' ' + to_string(year);
	//setSort(title + ' ' + to_string(year));	// Used to sort in BST
	// Sets movie information to be displayed
	setDisplay(title + ',' + to_string(year) + ',' + director + ',');
}

// -----------------------------------~Comedy()-----------------------------------
// Destructor for class Comedy 
Comedy::~Comedy() {}

//-----------------------------OVERLOADED OPERATORS------------------------------

// -----------------------------------Operator==---------------------------------
// Overloading == operator

bool Comedy::operator==(const Movie& rhs) const
{
	const Comedy& movCom = static_cast<const Comedy&> (rhs);
	return sort == movCom.sort;
}

// -----------------------------------Operator!=---------------------------------
// Overloading != operator
bool Comedy::operator!=(const Movie& rhs) const
{
	return !(*this == rhs);
}

// -----------------------------------Operator>----------------------------------
// Overloading > operator
bool Comedy::operator>(const Movie& rhs) const
{
	const Comedy& movCom = static_cast<const Comedy&> (rhs);
	return (sort > movCom.sort);
}


bool Comedy::operator<(const Movie& rhs) const
{
	const Comedy& movCom = static_cast<const Comedy&> (rhs);
	return (sort < movCom.sort);
}
