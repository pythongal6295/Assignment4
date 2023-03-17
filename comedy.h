// ---------------------------------------------- comedy.h ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 2/25/23
// Date of Last Modification: 3/16/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Header file for derived class Comedy
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Movie is the base class for Comedy
//  -Sorted by title, then year it was released
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------
#ifndef COMEDY_H
#define COMEDY_H

#include <iostream>
#include <fstream>
#include "movie.h"

using namespace std;

class Comedy : public Movie
{

public:
	// -----------------------------------Comedy()-----------------------------------
	//Default constructor for Comedy 
	Comedy();

	Comedy(string);

	// -----------------------------------Comedy-----------------------------------
	// Paramaterized constructor for Comedy, ifstream parameter type
	Comedy(ifstream&);

	// -----------------------------------~Comedy()-----------------------------------
	// Destructor for class Comedy 
	virtual ~Comedy();

	// -----------------------------------Operator==---------------------------------
	// Overloading == operator
	bool operator==(const Movie&) const;

	// -----------------------------------Operator!=---------------------------------
	// Overloading != operator
	bool operator!=(const Movie&) const;

	// -----------------------------------Operator>----------------------------------
	// Overloading > operator
	bool operator>(const Movie&) const ;

	// -----------------------------------Operator<----------------------------------
	// Overloading < operator
	bool operator<(const Movie&) const;

	// ----------------------------------getSort()----------------------------------
	// Gets variable sort. Sort is used to sort movies in BST
	string getSort();

private:
	// Information of comedy movie
	int year;			// Year of specific comedy movie
	string title;		// Title of specific comedy movie
	string director;	// Director of specific comedy movie
	//string sort;


};

#endif
