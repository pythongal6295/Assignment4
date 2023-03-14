// ---------------------------------------------- comedy.cpp ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 3/10/23
// Date of Last Modification: 2/25/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Implementation file for derived class Comedy
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Movie is the base class for Comedy
//  -Sorted by title, then year it was released
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include "comedy.h"

//Default constructor for Comedy 
Comedy::Comedy()
{
	year = 0;
	//stock = 0;
	title = "";
	director = "";
}

////Paramaterized constructor for Comedy 
//Comedy::Comedy(string movieTitle, string movieDirector, int movieYear, int currStock)
//{
//	//set up the comedy movie node for the BST
//	ComedyBST * comedyMovie = new ComedyBST;
//	comedyMovie->title = movieTitle;
//	comedyMovie->director = movieDirector;
//	comedyMovie->year = movieYear;
//	comedyMovie->stock = currStock;
//	comedyMovie->left = NULL;
//	comedyMovie->right = NULL;
//}

Comedy::Comedy(ifstream& infile)
{
	string temp;
	getline(infile, temp, ',');
	setStock(stoi(temp));
	getline(infile, director, ',');
	director.erase(0, 1);//Removing front blank space
	getline(infile, title, ',');
	title.erase(0, 1);//Removing front blank space
	infile >> year;
	getline(infile, temp);

	setSort(title + ' ' + to_string(year));
	setDisplay(title + ',' + to_string(year) + ',' + director + ',');
}

Comedy::~Comedy() {}

//// -----------------------------------getYear-----------------------------------
//// Returns the year of the movie
//int Comedy::getYear()
//{
//	return year;
//}
//
//// -----------------------------------getTitle-----------------------------------
//// Returns the title of the movie
//string Comedy::getTitle()
//{
//	return title;
//}
//
//// -----------------------------------getStock-----------------------------------
//// Returns the stock of the movie
//int Comedy::getStock()
//{
//	return stock;
//}
//
//// -----------------------------------getDirector-----------------------------------
//// Returns the name of the directory of the movie
//string Comedy::getDirector()
//{
//	return director;
//}
//
//// -----------------------------------setStock-----------------------------------
//// Sets a new value for the stock depending on borrow/rent actions
//// Parameter: int - the new stock value
//void Comedy::setStock(int newStock)
//{
//	stock = newStock;
//	//stock += newStock;	// Add newStock to current stock
//}

