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

	//Paramaterized constructor for Drama
	//Drama(string title, string director, int year, int currStock);

	// -----------------------------------Drama()-----------------------------------
	// Constructor with parameter for Drama class
	Drama(ifstream&);

	// -----------------------------------~Drama()-----------------------------------
	// Destructor for class Drama 
	virtual ~Drama();

	// -----------------------------------display-----------------------------------
	// Outputs to the screen all of the details of the movie (Year, Title, Director, Stock)
	void display();


private:
	int month; // month of specific movie
	int year;  // year of specific drama movie
	string title;  // title of specific drama movie
	string director; // director of specific drama movie

};
#endif
