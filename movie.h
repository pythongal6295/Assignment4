// ---------------------------------------------- movie.h ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Jessica Lee Chan
// Maria Ixchel Arias Cruz
// Brenda S. Vega Contreras 
// Creation Date : 2/25/23
// Date of Last Modification: 2/25/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Header file for base class Movie
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Movie is the base class for Drama, Comedy and Classics classes
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------
#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <fstream>
using namespace std;

class Movie
{
public:

  // -----------------------------------Movie()-----------------------------------
  // Default constructor for Movie class
  Movie();

// -----------------------------------display-----------------------------------
	// Outputs to the screen all of the details of the movie (Year, Title, Director, Stock)
	void display();

	// -----------------------------------getYear-----------------------------------
	// Returns the year of the movie
	int getYear();

	// -----------------------------------getTitle-----------------------------------
	// Returns the title of the movie
	string getTitle();

	// -----------------------------------getStock-----------------------------------
	// Returns the stock of the movie
	int getStock();

	// -----------------------------------getDirector-----------------------------------
	// Returns the name of the directory of the movie
	string getDirector();

	// -----------------------------------setStock-----------------------------------
	// Sets a new value for the stock depending on borrow/rent actions
	// Parameter: int - the new stock value
	void setStock(int);

  // -----------------------------------insert-----------------------------------
	// Sort using the data structure which has all movies, it's being build for the first time. 
	// Delared as "abstract class". 
	// Parameters are string (remaining current command line from data4movies.txt)
	virtual void insert(ifstream&) = 0;	

private:
  // Properties of Movie Class
	string movieTitle; //title of specific movie
	string movieDirector; //director of specific movie
	int movieYear; //year of specific movie
	int stock; //stock of specific movie

};

#endif
