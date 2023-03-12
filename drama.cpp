// ---------------------------------------------- drama.cpp ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 3/10/23
// Date of Last Modification: 2/25/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Implementation file for derived class Drama
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Movie is the base class for Drama
//  -Sorted by director, then title
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include "drama.h"

//Default constructor for Drama 
Drama::Drama()
{
	month = 0;
	year = 0;
	stock = 0;
	title = "";
	director = "";
}

////Paramaterized constructor for Drama 
//Drama::Drama(string movieTitle, string movieDirector, int movieYear, int currStock)
//{
//	//set up the comedy movie node for the BST
//	DramaBST* dramaMovie = new DramaBST;
//	dramaMovie->title = movieTitle;
//	dramaMovie->director = movieDirector;
//	dramaMovie->year = movieYear;
//	dramaMovie->stock = currStock;
//	dramaMovie->left = NULL;
//	dramaMovie->right = NULL;
//}

// -----------------------------------Drama()-----------------------------------
// Constructor with parameter for Drama class
Drama::Drama(ifstream& infile) :Drama()
{
	//infile >> stock >> director >> title >> releaseYear;
	string temp;
	getline(infile, temp, ',');
	stock = stoi(temp);
	getline(infile, director, ',');
	director.erase(0, 1);//Removing front blank space
	getline(infile, title, ',');
	title.erase(0, 1);//Removing front blank space
	infile >> year;
	getline(infile, temp);
}

Drama::~Drama()
{
}

// -----------------------------------getYear-----------------------------------
// Returns the year of the movie
int Drama::getYear()
{
	return year;
}

// -----------------------------------getTitle-----------------------------------
// Returns the title of the movie
string Drama::getTitle()
{
	return title;
}

// -----------------------------------getStock-----------------------------------
// Returns the stock of the movie
int Drama::getStock()
{
	return stock;
}

// -----------------------------------getDirector-----------------------------------
// Returns the name of the directory of the movie
string Drama::getDirector()
{
	return director;
}

// -----------------------------------setStock-----------------------------------
// Sets a new value for the stock depending on borrow/rent actions
// Parameter: int - the new stock value
void Drama::setStock(int newStock)
{
	stock = newStock;
	//stock += newStock;	// Add newStock to current stock
}

//bool Drama::operator==(const Drama&) const
//{
//	return false;
//}
//
//bool Drama::operator>(const Drama&) const
//{
//	return false;
//}
