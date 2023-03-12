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
	releaseMonth = 0;
	releaseYear = 0;
	stock = 0;
	title = "";
	director = "";
	firstName = "";
	lastName = "";
}

////Paramaterized constructor for Classics 
//Classics::Classics(string movieTitle, string movieDirector, int movieMonth, int movieYear, int currStock, string majorActor)
//{
//	//set up the comedy movie node for the BST
//	ClassicsBST* classicsMovie = new ClassicsBST;
//	classicsMovie->title = movieTitle;
//	classicsMovie->director = movieDirector;
//	classicsMovie->year = movieYear;
//	classicsMovie->month = movieMonth;
//	classicsMovie->majorActor = majorActor;
//	classicsMovie->stock = currStock;
//	classicsMovie->left = NULL;
//	classicsMovie->right = NULL;
//}

Classics::Classics(ifstream& infile)
{
	infile >> stock;
	getline(infile, director, ',');
	getline(infile, title, ',');
	infile >> firstName >> lastName >> releaseMonth >> releaseYear;
}

Classics::~Classics()
{
}

//bool Classics::operator==(const Classics&) const
//{
//	return false;
//}
//
//bool Classics::operator>(const Classics&) const
//{
//	return false;
//}
