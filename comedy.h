// ---------------------------------------------- comedy.h ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 2/25/23
// Date of Last Modification: 2/25/23
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

	//Paramaterized constructor for Comedy, multiple data parameter
	//Comedy(string title, string director, int year, int currStock);

	// -----------------------------------Comedy-----------------------------------
	// Paramaterized constructor for Comedy, ifstream parameter type
	Comedy(ifstream&);

	// -----------------------------------~Comedy()-----------------------------------
	// Destructor for class Comedy 
	virtual ~Comedy();

	// -----------------------------------display-----------------------------------
	// Outputs to the screen all of the details of the movie (Year, Title, Director, Stock)
	void display();

	// -----------------------------------getYear-----------------------------------
	// Returns the year of the movie
	int getYear();

	// -----------------------------------getTitle-----------------------------------
	// Accessor - get the movieTitle of an object Comedy.
	string getTitle();

	// -----------------------------------getStock-----------------------------------
	// Accessor - Get the number of copies available of a Comedy Movie.
	int getStock();

	// -----------------------------------getDirector-----------------------------------
	// Accessor - get the movieDirector of a Comedy movie.
	string getDirector();

	// -----------------------------------setStock-----------------------------------
	// Mutator -  Modify data member stock after a command.
	void setStock(int);

	// -----------------------------------insert-----------------------------------
	// Insert a new object of type Comedy in a BST.
	// Precondition: String - current command line from data4movies.txt.
	//void insert(ifstream&);


	//bool operator==(const Comedy&) const;

	//bool operator>(const Comedy&) const;


private:
	//string sortF; //title+year released

	// NOTE: I gave the same format of Clasics to Comedy and Drama

	int year;  //year of specific comedy movie
	int stock;  //stock of specific comedy movie
	string title;  //title of specific comedy movie
	string director;  //director of specific comedy movie


};

#endif
