// ---------------------------------------------- movie.cpp ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 2/25/23
// Date of Last Modification: 3/16/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Implementation file for base class Movie
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Movie is the base class for Drama, Comedy and Classics classes
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------

#include "movie.h"

Movie::Movie() :stock(0), movieType('\0') {}

// ----------------------------------- ~Movie()-----------------------------------
// Destructor for Movie class
Movie::~Movie() {}

// -----------------------------------display-----------------------------------
// Outputs to the screen all of the details of the movie (Year, Title, Director, Stock)
void Movie::setDisplay(string input)
{
	toDisplay = input;
}

// ---------------------------------borrowMovie()--------------------------------
bool Movie::borrowMovie()
{
	if (stock != 0) {
		stock--;
		return true;
	}
	return false;
}

// ---------------------------------returnMovie()--------------------------------
void Movie::returnMovie()
{
	stock++;
}

void Movie::setStock(int input)
{
	stock += input;
}

// -----------------------------------getStock-----------------------------------
// Returns the stock of the movie
int Movie::getStock()
{
	return stock;
}

// -----------------------------------setSort-----------------------------------
// Sets private variable sort
void Movie::setSort(string input)
{
	sort = input;
}

// -----------------------------------getSort()-----------------------------------
// Gets variable sort
string Movie::getSort()
{
	return sort;
}

// ----------------------------------setMovieInfo()----------------------------------
// Gets movieInfo
string Movie::getMovieInfo()
{
	return movieInfo;
}

// ----------------------------------getGenre()----------------------------------
// Gets type of movie (C,F or D)
char Movie::getGenre()
{
	return movieType;
}

// ----------------------------------setActionCode()----------------------------------
// Sets action code to borrow and return
void Movie::setActionCode(char code)
{
	actionCode = code;
}

// ----------------------------------getActionCode()----------------------------------
// Gets action code to borrow or return
char Movie::getActionCode()
{
	return actionCode;
}

// ----------------------------------setMovieInfo()----------------------------------
// Sets movieInfo
void Movie::setMovieInfo(string input, char genre)
{
	movieInfo = input;
	movieType = genre;
}



bool Movie::operator==(const Movie& rhs) const
{
	// When movie is being borrowed
	if (actionCode == 'B') {
		// If movie is a classic
		if (movieType == 'C') {
			// If movie in stock return true
			if (movieInfo == rhs.movieInfo && rhs.stock > 0) {
				return true;
			}
			// If movie info same but not in stock, return false. Same for when movie info is not the same
			return false;
		}
		// If movie to borrow is a drama or a comedy
		return sort == rhs.sort;
	}

	// When inserting nodes to the bst of movies
	return sort == rhs.sort;
}

bool Movie::operator!=(const Movie& rhs) const
{
	return !(*this == rhs);
}

bool Movie::operator>(const Movie& rhs) const
{
	return (sort > rhs.sort);
}

bool Movie::operator<(const Movie& rhs) const
{
	return (sort < rhs.sort);
}

//-------------------------- operator<< --------------------------------------
ostream& operator<<(ostream& output, const Movie& nd)
{
	output << nd.toDisplay + to_string(nd.stock);
	return output;
}
