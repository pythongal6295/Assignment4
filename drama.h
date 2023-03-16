// ---------------------------------------------- drama.h ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 2/25/23
// Date of Last Modification: 3/16/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Header file for derived class Drama
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Movie is the base class for Drama
//  -Sorted by director, then title
// Assumptions:
//	
// ---------------------------------------------------------------------------------------------------------------
#ifndef DRAMA_H
#define DRAMA_H

#include <iostream>
#include <fstream>
#include "movie.h"

using namespace std;

class Drama : public Movie
{
public:
	// -----------------------------------Drama()-----------------------------------
	// Default constructor for drama 
	Drama();

	Drama(string);

	// -----------------------------------Drama()-----------------------------------
	// Constructor with parameter for Drama class
	Drama(ifstream&);

	// -----------------------------------~Drama()-----------------------------------
	// Destructor for class Drama 
	virtual ~Drama();

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
	// Information of drama movie
	int month;			// Month of specific movie
	int year;			// Year of specific drama movie
	string title;		// Title of specific drama movie
	string director;	// Director of specific drama movie
	string sort;

};
#endif
