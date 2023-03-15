// ---------------------------------------------- movieFactory.h ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 2/25/23
// Date of Last Modification: 3/16/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Header file for MovieFactory class
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------
#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include <iostream>
#include <fstream>
#include "comedy.h"
#include "drama.h"
#include "classics.h"

using namespace std;

class MovieFactory
{
public:

	// -----------------------------------MovieFactory()-----------------------------------
	// Default constructor for MovieFactory class
	MovieFactory();

	// -----------------------------------~MovieFactory()-----------------------------------
	// Destructor for MovieFactory class
	~MovieFactory();

	// ----------------------------------createMovieObject----------------------------------
	// Creates new movie genre object with switch, using first letter from current 
	// string line in data4movies.txt (BusinessLogic::loadMovies())
	static Movie* createMovieObject(char, ifstream&);
};

#endif
