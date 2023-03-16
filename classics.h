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
//
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

	// -----------------------------------Classics-----------------------------------
	// Paramaterized constructor for Classics, multiple data parameter
	//Classics(string title, string director, int month, int year, int currStock, string majorActor);

	// -----------------------------------Classics-----------------------------------
	// Parametrized constructor for Classics, ifstream parameter type
	Classics(ifstream&);

	// -----------------------------------~Classics()-----------------------------------
	// Destructor for Classics
	virtual ~Classics();

	// -----------------------------------display-----------------------------------
	// Outputs to the screen all of the details of the movie (Release Date, Title, Director, Stock, Major Actor)
	void display();


private:

	//Since we have a node structure in NodeData, we may not need another node structure for each movie type
	//Also I couldn't figure out how to do a getter with the structure
	//int stock; //stock of specific classics movie
	int year;  //release year of specific classics movie
	int month; //release month of specific classics movie
	string title;  //title of specific classics movie
	string director;  //director of specific classics movie
	string firstName; //Major actor's first name
	string lastName; //Major actor's last name
	string releaseDate; // Year and month when the movie was released
	string majorActor; //major actor of specific classics movie

};
#endif