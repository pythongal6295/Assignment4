// ---------------------------------------------- classics.h ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 2/25/23
// Date of Last Modification: 2/25/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Header file for derived class Classics
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Movie is the base class for Classics
//  -Sorted by release date, then Major actor
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------
#ifndef CLASSICS_H
#define CLASSICS_H

#include <iostream>
#include <fstream>
#include <string>
#include "movie.h"

using namespace std;

class Classics : public Movie
{

public:
	// -----------------------------------Classics()-----------------------------------
	// Default constructor for Classics class
	Classics();

	// -----------------------------------Classics-----------------------------------
	// Paramaterized constructor for Classics
	//Classics(string title, string director, int month, int year, int currStock, string majorActor);

	// -----------------------------------Classics-----------------------------------
	// Constructor with parameter for Classics class
	Classics(ifstream&);

	// -----------------------------------~Classics()-----------------------------------
	// Destructor for Classics
	~Classics();

	// -----------------------------------display-----------------------------------
	// Outputs to the screen all of the details of the movie (Year, Title, Director, Stock)
	void display();

	// -----------------------------------getYear-----------------------------------
	// Returns the year of the movie
	int getMonth();

	// -----------------------------------getTitle-----------------------------------
	// Returns the title of the movie
	string getTitle();

	// -----------------------------------getStock-----------------------------------
	// Returns the stock of the movie
	int getStock();

	// -----------------------------------getDirector-----------------------------------
	// Returns the name of the directory of the movie
	string getDirector();

	// -----------------------------------getMajorActor-----------------------------------
	// Returns the name of the major actor of the movie
	string getMajorActor();

	// -----------------------------------insert-----------------------------------
	// This movie object inserts itself into the Classics binary search tree
	//parameters: string - remaining current command line from data4movies.txt
	//void insert(ifstream&);

	//bool operator==(const Classics&) const;
	//bool operator>(const Classics&) const;

private:

	// Describes a node composed of information about the classics movie object.
	// The created node is added to the Classics binary search tree
	/*struct ClassicsBST
	{*/
	int stock; //stock of specific classics movie
	int releaseYear;  //year of specific classics movie
	int releaseMonth; //month of specific classics movie
	string title;  //title of specific classics movie
	string director;  //director of specific classics movie
	string firstName; //Major actor's first name
	string lastName; //Major actor's last name
	//ClassicsBST* right;  //pointer to right child in BST
	//ClassicsBST* left;  //pointer to left child in BST
	//};

};
#endif