// ---------------------------------------------- movie.h ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 2/25/23
// Date of Last Modification: 3/16/23
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
#include <string>

using namespace std;

class Movie
{
	//-------------------------- operator<< --------------------------------------
	// Overloading << operator to print movie Objects
	friend ostream& operator<<(ostream&, const Movie&);
public:

	// -----------------------------------Movie()-----------------------------------
	// Default constructor for Movie class
	Movie();

	// Constructor movie with parameters
	Movie(string);
	//Movie(string, string);

	// -----------------------------------Movie()-----------------------------------
	// Destructor for Movie class
	virtual ~Movie();

	// ----------------------------------setDisplay---------------------------------
	// Sets movie information in toDisplay variable to display movie information 
	// when printing BSTs 
	void setDisplay(string);

	// -----------------------------------setStock----------------------------------
	// Sets a new value for the stock depending on borrow/rent actions
	// Parameter: int - the new stock value
	void setStock(int);

	// -----------------------------------getStock----------------------------------
	// Returns the stock of the movie
	int getStock();

	// --------------------------------borrowMovie()--------------------------------
	// Sets movie object's stock = stock - 1 when borrowed if stock != 0
	bool borrowMovie();

	// --------------------------------returnMovie()--------------------------------
	// Sets movie object's stock = stock + 1 when borrowed if stock != 0
	void returnMovie();

	// -----------------------------------setSort-----------------------------------
	// Sets private variable sort. Sort is used to sort movies in BST
	//void setSort(string);

	// ----------------------------------getSort()----------------------------------
	// Gets variable sort. Sort is used to sort movies in BST
	virtual string getSort();

	// --------------------------------setMovieInfo()--------------------------------
	// Sets string movieInfo with movie information. Useful when borrowing classic movies
	void setMovieInfo(string, char);

	// --------------------------------getMovieInfo()--------------------------------
	// Gets movieInfo of movie. Used for borrowing classic movies
	string getMovieInfo();

	// ----------------------------------getGenre()----------------------------------
	// Gets type of movie (C,F or D)
	char getGenre();

	// ------------------------------setActionCode()---------------------------------
	// Sets action code to borrow 'B'. Used when borrowing classic movies
	void setActionCode(char);

	// -------------------------------getActionCode()--------------------------------
	// Gets action code to borrow. Used when borrowing classic movies
	char getActionCode();

	//-----------------------------OVERLOADED OPERATORS------------------------------

	// -----------------------------------Operator==---------------------------------
	// Overloading == operator
	virtual bool operator==(const Movie&) const = 0;

	// -----------------------------------Operator!=---------------------------------
	// Overloading != operator
	virtual bool operator!=(const Movie&) const = 0;

	// -----------------------------------Operator>----------------------------------
	// Overloading > operator
	virtual bool operator>(const Movie&) const = 0;

	// -----------------------------------Operator<----------------------------------
	// Overloading < operator
	virtual bool operator<(const Movie&) const = 0;

protected:
	string sort;
private:
	// Properties of Movie Class
	int stock;			// Stock of a specific movie
	//string sort;		// String that contains data from specific movie type, used to sort in BST
	string toDisplay;	// Used for printing Movie information in <<	
	string movieInfo;	// String that containg data from movie (release date + title + director)
	char movieType;		// Movie genre (D,C or F)
	char actionCode;	// Set to 'B' when transaction is borrow movie
};

#endif
