// ---------------------------------------------- classics.cpp ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 3/10/23
// Date of Last Modification: 2/25/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Implementation file for derived class Classics
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Movie is the base class for Classics
//  -Sorted by release date, then Major actor
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include "classics.h"

//Default constructor for Comedy 
Classics::Classics()
{

}

//Paramaterized constructor for Comedy 
Classics::Classics(string movieTitle, string movieDirector, int movieMonth, int movieYear, int currStock, string actor)
{
	//set up the comedy movie node for the BST
	/*ClassicsBST* classicsMovie = new ClassicsBST;
	classicsMovie->title = movieTitle;
	classicsMovie->director = movieDirector;
	classicsMovie->year = movieYear;
	classicsMovie->month = movieMonth;
	classicsMovie->majorActor = majorActor;
	classicsMovie->stock = currStock;
	classicsMovie->left = NULL;
	classicsMovie->right = NULL;*/

	//if we don't use the structure, then just set the private attributes
	title = movieTitle;
	director = movieDirector;
	year = movieYear;
	month = movieMonth;
	majorActor = actor;
	stock = currStock;
}

// -----------------------------------~Classics()-----------------------------------
// Destructor for Classics
Classics::~Classics()
{
}

// -----------------------------------display-----------------------------------
// Outputs to the screen all of the details of the movie (Release Date, Title, Director, Stock, Major Actor)
void Classics::display()
{
	cout << "*********************************************************" << endl;
	cout << "Title: " << getTitle() << endl;
	cout << "Release Date: " << getMonth() << " " << getYear() << endl;
	cout << "Major Actor: " << getMajorActor() << endl;
	cout << "Director: " << getDirector() << endl;
	cout << "Stock: " << getStock() << endl;
}

// -----------------------------------getMonth-----------------------------------
// Returns the year of the movie
int Classics::getMonth()
{
	return month;
}

// -----------------------------------getYear-----------------------------------
// Returns the year of the movie
int Classics::getYear()
{
	return year;
}

// -----------------------------------getTitle-----------------------------------
// Returns the title of the movie
string Classics::getTitle()
{
	return title;
}

// -----------------------------------getStock-----------------------------------
// Returns the stock of the movie
int Classics::getStock()
{
	return stock;
}

// -----------------------------------getDirector-----------------------------------
// Returns the name of the directory of the movie
string Classics::getDirector()
{
	return director;
}

// -----------------------------------getMajorActor-----------------------------------
// Returns the name of the major actor of the movie
string Classics::getMajorActor()
{
	return majorActor;
}
// -----------------------------------setStock-----------------------------------
// Sets a new value for the stock depending on borrow/rent actions
// Parameter: int - the new stock value
void Classics::setStock(int newStock)
{
	stock = newStock;
}
