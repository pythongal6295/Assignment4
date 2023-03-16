// ---------------------------------------------- movie.h ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Jessica Lee Chan
// Maria Ixchel Arias Cruz
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
	friend ostream& operator<<(ostream&, const Movie&);
public:

	// -----------------------------------Movie()-----------------------------------
	// Default constructor for Movie class
	Movie();

	// -----------------------------------Movie()-----------------------------------
	// Destructor for Movie class
	virtual ~Movie();

	// ----------------------------------setDisplay---------------------------------
	void setDisplay(string);

	// -----------------------------------getTitle-----------------------------------
	// Returns the title of the movie
	string getTitle();

	// -----------------------------------setStock-----------------------------------
	// Sets a new value for the stock depending on borrow/rent actions
	// Parameter: int - the new stock value
	virtual void setStock(int);

	// -----------------------------------getStock-----------------------------------
	// Returns the stock of the movie
	int getStock();

	// ----------------------------------getDirector---------------------------------
	// Returns the name of the directory of the movie
	string getDirector();


	// ---------------------------------borrowMovie()--------------------------------
	bool borrowMovie();

	// ---------------------------------returnMovie()--------------------------------
	void returnMovie();

	// -----------------------------------setSort-----------------------------------
	// Sets private variable sort
	void setSort(string);

	// ----------------------------------getSort()----------------------------------
	// Gets variable sort
	string getSort();

	// ----------------------------------setMovieInfo()----------------------------------
	// Sets movieInfo
	void setMovieInfo(string, char);

	// ----------------------------------getMovieInfo()----------------------------------
	// Gets movieInfo
	string getMovieInfo();

	// ----------------------------------getGenre()----------------------------------
	// Gets type of movie (C,F or D)
	char getGenre();

	// ----------------------------------setActionCode()----------------------------------
	// Sets action code to borrow and return
	void setActionCode(char);

	// ----------------------------------getActionCode()----------------------------------
	// Gets action code to borrow or return
	char getActionCode();

	// -----------------------------------Operator==---------------------------------
	// Overloading == operator
	virtual bool operator==(const Movie&) const;

	// -----------------------------------Operator!=---------------------------------
	// Overloading != operator
	virtual bool operator!=(const Movie&) const;

	// -----------------------------------Operator>----------------------------------
	// Overloading > operator
	virtual bool operator>(const Movie&) const;

	// -----------------------------------Operator<----------------------------------
	// Overloading < operator
	virtual bool operator<(const Movie&) const;

private:
	// Properties of Movie Class
	int stock;
	string sort; // String that contains director+title, used to sort
	string toDisplay;
	string movieInfo;
	char movieType;
	char actionCode;
};

#endif
