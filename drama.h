// ---------------------------------------------- drama.h ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 2/25/23
// Date of Last Modification: 2/25/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Header file for derived class Drama
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Movie is the base class for Drama
//  -Sorted by director, then title
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------
#ifndef DRAMA_H
#define DRAMA_H

#include <iostream>
#include <fstream>
#include "movie.h"

using namespace std;

class Drama : public Movie
{
public:
// -----------------------------------Drama()-----------------------------------
//Default constructor for Drama 
  Drama();

 //Paramaterized constructor for Drama
  Drama(string title, string director, int year, int currStock);

// -----------------------------------~Drama()-----------------------------------
//Destructor for class Drama 
  ~Drama();

// -----------------------------------display-----------------------------------
// Outputs to the screen all of the details of the movie (Year, Title, Director, Stock)
void display();

// -----------------------------------getYear-----------------------------------
// Accessor - get the movieYear of an object Drama.
int getYear();

// -----------------------------------getTitle-----------------------------------
// Accessor - get the movieTitle of an object Drama.
string getTitle();

// -----------------------------------getStock-----------------------------------
// Accessor - Get the number of copies available of a drama Movie.
int getStock();

// -----------------------------------getDirector-----------------------------------
// Accessor - get the movieDirector of a Drama movie.
string getDirector();

// -----------------------------------setStock-----------------------------------
// Mutator -  Modify data member stock after a command.
void setStock(int);

// -----------------------------------insert-----------------------------------
// Insert a new object of type Drama in a BST.
// Precondition: String - current command line from data4movies.txt.
void insert(ifstream&);

private:

// -----------------------------------struct DramaBST-----------------------------------
// The structure represent a node of type drama.
// The created node is added to the Drama binary search tree.
// BST sorted by Director then by Title 

struct DramaBST {
 int year;  //year of specific drama movie
 int stock; //stock of specific drama movie
 string title;  //title of specific drama movie
 string director; // director of specific drama movie.
 DramaBST *right;  //pointer to right child in BST
 DramaBST *left;  //pointer to left child in BST
};

};
#endif
