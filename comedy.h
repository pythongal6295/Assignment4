// ---------------------------------------------- comedy.h ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 2/25/23
// Date of Last Modification: 2/25/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Header file for derived class Comedy
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Movie is the base class for Comedy
//  -Sorted by title, then year it was released
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------
#ifndef COMEDY_H
#define COMEDY_H

#include <iostream>
#include <fstream>
#include "movie.h"

using namespace std;

class Comedy : public Movie
{

public:
// -----------------------------------Comedy()-----------------------------------
//Default constructor for Comedy 
  Comedy();

//Paramaterized constructor for Comedy 
  Comedy(string title, string director, int year, int currStock);

// -----------------------------------~Comedy()-----------------------------------
//Destructor for class Comedy 
  ~Comedy();

// -----------------------------------display-----------------------------------
// Outputs to the screen all of the details of the movie (Year, Title, Director, Stock)
void display();

// -----------------------------------getTitle-----------------------------------
// Accessor - get the movieTitle of an object Comedy.
string getTitle();

// -----------------------------------getStock-----------------------------------
// Accessor - Get the number of copies available of a Comedy Movie.
int getStock();

// -----------------------------------getDirector-----------------------------------
// Accessor - get the movieDirector of a Comedy movie.
string getDirector();

// -----------------------------------setStock-----------------------------------
// Mutator -  Modify data member stock after a command.
void setStock(int);

// -----------------------------------insert-----------------------------------
// Insert a new object of type Comedy in a BST.
// Precondition: String - current command line from data4movies.txt.
void insert(ifstream&);

private:

// -----------------------------------struct ComedyBST-----------------------------------
// The structure represents a node that describes a comedy movie.
// The created node is added to the Comedy binary search tree.
// BST sorted by title, then year it was released
struct ComedyBST {
 int year;  //year of specific comedy movie
 int stock;  //stock of specific comedy movie
 string title;  //title of specific comedy movie
 string director;  //director of specific comedy movie
 ComedyBST *right;  //pointer to right child in BST
 ComedyBST *left;  //pointer to left child in BST
};

};

#endif
