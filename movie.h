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

	// -----------------------------------display-----------------------------------
	// Outputs to the screen all of the details of the movie (Year, Title, Director, Stock)
	//virtual void display()=0;

	// ----------------------------------setDisplay---------------------------------
	void setDisplay(string);

	//// -----------------------------------getYear-----------------------------------
	//// Returns the year of the movie
	//int getYear();

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

	// VERSION 1
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

	// ------------------------------------insert------------------------------------
	  // Sort using the data structure which has all movies, it's being build for the first time. 
	  // Delared as "abstract class". 
	  // Parameters are string (remaining current command line from data4movies.txt)
	//virtual void insert(ifstream&) = 0;

	/*// VERSION 2
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
	*/

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
	int stock;
	string sort; // V2: string that contains director+title
	string toDisplay;
	string movieInfo;
	char movieType;

	//	// Properties of Movie Class
	//	string movieTitle; //title of specific movie
	//	string movieDirector; //director of specific movie
	//	int movieYear; //year of specific movie
	//	int stock; //stock of specific movie



};

#endif
