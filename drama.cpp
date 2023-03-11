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
	releaseMonth = 0;
	releaseYear = 0;
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
Drama::Drama(ifstream& infile)
{
	infile >> stock >> director >> title >> releaseYear;
}

bool Drama::operator==(const Drama&) const
{
	return false;
}

bool Drama::operator>(const Drama&) const
{
	return false;
}
