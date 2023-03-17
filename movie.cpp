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

// -----------------------------------Movie()-----------------------------------
// Default constructor for Movie class
Movie::Movie() :stock(0), movieType('\0'), actionCode('\0') {}

//Movie::Movie(string sortInput, string movieInfoIn):Movie(){
//	sort = sortInput;
//	movieInfo = movieInfoIn;
//}
//Movie::Movie(string sortInput):Movie(){
//	
//	sort = sortInput;
//
//}

// ----------------------------------- ~Movie()-----------------------------------
// Destructor for Movie class
Movie::~Movie() {}

// ----------------------------------setDisplay-----------------------------------
// Outputs to the screen all of the details of the movie (Year, Title, Director, Stock)
void Movie::setDisplay(string input)
{
	toDisplay = input;
}

// -----------------------------------setStock-----------------------------------
// Sets stock of the movie object
void Movie::setStock(int input)
{
	stock += input;
}

// -----------------------------------getStock-----------------------------------
// Returns the stock of the movie object
int Movie::getStock()
{
	return stock;
}

// ---------------------------------borrowMovie()--------------------------------
// Sets movie object's stock = stock - 1 when borrowed if stock != 0
bool Movie::borrowMovie()
{
	if (stock > 0) {
		stock--;
		return true;
	}
	return false;
}

// ---------------------------------returnMovie()--------------------------------
// Sets movie object's stock = stock + 1 when borrowed if stock != 0
void Movie::returnMovie()
{
	stock++;
}

// -----------------------------------setSort-----------------------------------
// Sets private variable sort. Sort is used to sort movies in BST
//void Movie::setSort(string input)
//{
//	sort = input;
//}

// -----------------------------------getSort()-----------------------------------
// Gets variable sort. Sort is used to sort movies in BST
string Movie::getSort()
{
	return sort;
}

// ----------------------------------setMovieInfo()----------------------------------
// Sets string movieInfo with movie information. Useful when borrowing classic movies
void Movie::setMovieInfo(string input, char genre)
{
	movieInfo = input;
	movieType = genre;
}

// ---------------------------------getMovieInfo()---------------------------------
// Gets movieInfo of movie. Used for borrowing classic movies
string Movie::getMovieInfo()
{
	return movieInfo;
}

// -----------------------------------getGenre()-----------------------------------
// Gets type of movie (C,F or D)
char Movie::getGenre()
{
	return movieType;
}

// ---------------------------------setActionCode()---------------------------------
// Sets action code to borrow 'B'. Used when borrowing classic movies
void Movie::setActionCode(char code)
{
	actionCode = code;
}

// ---------------------------------getActionCode()---------------------------------
// Gets action code to borrow. Used when borrowing classic movies
char Movie::getActionCode()
{
	return actionCode;
}

////-----------------------------OVERLOADED OPERATORS------------------------------
//
//// -----------------------------------Operator==---------------------------------
//// Overloading == operator
//
//bool Movie::operator==(const Movie& rhs) const
//{
//	// Used When movie is being borrowed
//	if (actionCode == 'B') {
//		// If movie is a classic
//		if (movieType == 'C') {
//			// If movie in stock return true
//			if (movieInfo == rhs.movieInfo && rhs.stock > 0) {
//				return true;
//			}
//			// If movie info is different or the same but not in stock, return false
//			return false;
//		}
//		// If movie to borrow is a drama or a comedy, compare strings
//		return sort == rhs.sort;
//	}
//
//	// Used when inserting nodes to the bst of movies or returning a movie
//	return sort == rhs.sort;
//}
//
//// -----------------------------------Operator!=---------------------------------
//// Overloading != operator
//bool Movie::operator!=(const Movie& rhs) const
//{
//	return !(*this == rhs);
//}
//
//// -----------------------------------Operator>----------------------------------
//// Overloading > operator
//bool Movie::operator>(const Movie& rhs) const
//{
//	return (sort > rhs.sort);
//}
//
//// -----------------------------------Operator<----------------------------------
//// Overloading < operator
//bool Movie::operator<(const Movie& rhs) const
//{
//	return (sort < rhs.sort);
//}

//-------------------------- operator<< --------------------------------------
// Overloading << operator to print movie Objects
ostream& operator<<(ostream& output, const Movie& nd)
{
	output << nd.toDisplay + to_string(nd.stock);
	return output;
}
