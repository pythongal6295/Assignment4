// ---------------------------------------------- classics.cpp ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 3/10/23
// Date of Last Modification: 3/16/23
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
	month = 0;
	year = 0;
	title = "";
	director = "";
	firstName = "";
	lastName = "";
}

// -----------------------------------Classics-----------------------------------
// Parametrized constructor for Classics, ifstream parameter type
Classics::Classics(ifstream& infile)
{
	string temp;

	getline(infile, temp, ',');
	setStock(stoi(temp));
	getline(infile, director, ',');
	director.erase(0, 1);//Removing front blank space
	getline(infile, title, ',');
	title.erase(0, 1);//Removing front blank space
	infile >> firstName >> lastName >> month >> year;
	getline(infile, temp);
	releaseDate = to_string(year) + ' ' + to_string(month);
	majorActor = firstName + ' ' + lastName;

	setSort(releaseDate + ' ' + majorActor);
	setMovieInfo(to_string(year)+' '+to_string(month) + title + ' ' + director, 'C');
	setDisplay(releaseDate + ',' + majorActor + ',' + title + ',' + director + ',');
}

Classics::~Classics() {}


