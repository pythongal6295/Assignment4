// ---------------------------------------------- classics.h ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 2/25/23
// Date of Last Modification: 3/16/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Header file for derived class Classics
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Movie is the base class for Classics
//  -Sorted by release date, then Major actor
// Assumptions:
//	If a classics object is already created for the same movie, a new classics object is created with a different
//	major actor information.
//	When want to borrow a classic movie but current object is out of stock, look for same movie with different
//  major actors
// ---------------------------------------------------------------------------------------------------------------
#ifndef CLASSICS_H
#define CLASSICS_H

#include <iostream>
#include <fstream>
#include <string>
#include "movie.h"

using namespace std;

class Classics : public Movie
{
public:
	// -----------------------------------Classics()-----------------------------------
	// Default constructor for Classics class
	Classics();

	Classics(string);

	// -----------------------------------Classics-----------------------------------
	// Parametrized constructor for Classics, ifstream parameter type
	Classics(ifstream&);

	// -----------------------------------~Classics()-----------------------------------
	// Destructor for Classics
	virtual ~Classics();

	// -----------------------------------Operator==---------------------------------
// Overloading == operator
	bool operator==(const Movie&) const;

	// -----------------------------------Operator!=---------------------------------
	// Overloading != operator
	bool operator!=(const Movie&) const;

	// -----------------------------------Operator>----------------------------------
	// Overloading > operator
	bool operator>(const Movie&) const;

	// -----------------------------------Operator<----------------------------------
	// Overloading < operator
	bool operator<(const Movie&) const;


private:
	// Information of classic movie
	int year;			// Release year of specific classics movie
	int month;			// Release month of specific classics movie
	string title;		// Title of specific classics movie
	string director;	// Director of specific classics movie
	string firstName;	// Major actor's first name
	string lastName;	// Major actor's last name
	string releaseDate; // Year and month when the movie was released
	string majorActor;	// Major actor of specific classics movie

	string sort;

};
#endif