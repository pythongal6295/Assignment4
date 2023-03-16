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

// ----------------------------------setMovieInfo()----------------------------------
// Sets movieInfo
void Movie::setMovieInfo(string input, char genre)
{
	movieInfo = input;
	movieType = genre;
}



bool Movie::operator==(const Movie& rhs) const
{

	//if (movieType == 'C') {
	//	if (sort == rhs.sort && rhs.stock > 0) {
	//		return (sort == rhs.sort);
	//	} else if (sort == rhs.sort && rhs.stock == 0) {
	//		return false;
	//	} else if (sort != rhs.sort && movieInfo == rhs.movieInfo) {
	//		return movieInfo == rhs.movieInfo;
	//	}
	//	/*if (sort == rhs.sort && rhs.stock==0) {
	//		return false;
	//	}*/
	//}
	return (sort == rhs.sort);
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
