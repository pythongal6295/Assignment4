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
	releaseYear = 0;
	stock = 0;
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
	stock = stoi(temp);
	getline(infile, director, ',');
	director.erase(0, 1);//Removing front blank space
	getline(infile, title, ',');
	title.erase(0, 1);//Removing front blank space
	infile >> releaseYear;
	getline(infile, temp);
}

Comedy::~Comedy()
{
}

//bool Comedy::operator==(const Comedy& rhs) const
//{
//	/*if (director == rhs.director && title == rhs.title && releaseYear == rhs.releaseYear) {
//		return true;
//	}*/
//	return false;
//}
//
//bool Comedy::operator>(const Comedy&) const
//{
//	return true;
//}
