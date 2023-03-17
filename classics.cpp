// ---------------------------------------------- classics.cpp ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 3/10/23
// Date of Last Modification: 3/16/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Implementation file for derived class Classics
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Movie is the base class for Classics
//  -Sorted by release date, then Major actor
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include "classics.h"

// -----------------------------------Classics()-----------------------------------
// Default constructor for Classics class
Classics::Classics()
{
	month = 0;
	year = 0;
	title = "";
	director = "";
	firstName = "";
	lastName = "";
}

Classics::Classics(string sortInput) :Classics()
{
	sort = sortInput;
}

// -----------------------------------Classics-----------------------------------
// Parametrized constructor for Classics, ifstream parameter type.
// Sets information from file into private data members
Classics::Classics(ifstream& infile)
{
	string temp;

	getline(infile, temp, ',');
	setStock(stoi(temp));
	getline(infile, director, ',');
	director.erase(0, 1);	// Removing front blank space
	getline(infile, title, ',');
	title.erase(0, 1);	// Removing front blank space
	infile >> firstName >> lastName >> month >> year;
	getline(infile, temp);
	releaseDate = to_string(year) + ' ' + to_string(month);
	majorActor = firstName + ' ' + lastName;
	sort = releaseDate + ' ' + majorActor;
	//setSort(releaseDate + ' ' + majorActor);	// Used for sorting in BST
	// setMovieInfo sets variable used for classic movies in parent class Movie
	setMovieInfo(to_string(year) + ' ' + to_string(month) + ' ' + title + ' ' + director, 'C');
	// Sets movie information to be displayed
	setDisplay(releaseDate + ',' + majorActor + ',' + title + ',' + director + ',');
}

// -----------------------------------~Classics()-----------------------------------
// Destructor for Classics
Classics::~Classics() {}

//-----------------------------OVERLOADED OPERATORS------------------------------

// -----------------------------------Operator==---------------------------------
// Overloading == operator

bool Classics::operator==(const Movie& rhs) const
{
	const Classics& movCom = static_cast<const Classics&> (rhs);
	return sort == movCom.sort;
}

// -----------------------------------Operator!=---------------------------------
// Overloading != operator
bool Classics::operator!=(const Movie& rhs) const
{
	return !(*this == rhs);
}

// -----------------------------------Operator>----------------------------------
// Overloading > operator
bool Classics::operator>(const Movie& rhs) const
{
	const Classics& movCom = static_cast<const Classics&> (rhs);
	return (sort > movCom.sort);
}

bool Classics::operator<(const Movie& rhs) const
{
	const Classics& movCom = static_cast<const Classics&> (rhs);
	return (sort < movCom.sort);;
}

// -----------------------------------getSort()-----------------------------------
// Gets variable sort. Sort is used to sort movies in BST
string Classics::getSort()
{
	return sort;
}
