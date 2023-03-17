// ---------------------------------------------- borrow.h ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 3/9/23
// Date of Last Modification: 3/16/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Header file for class Borrow. Handles borrowing of a movie
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Borrow is the child class of Transaction
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------
#ifndef BORROW_H
#define BORROW_H

#include <iostream>
#include <fstream>
#include "transaction.h"
#include "classics.h"
#include "drama.h"
#include "comedy.h"

using namespace std;

class Borrow :public Transaction
{
public:
	// -----------------------------------Borrow()------------------------------------
	// Default constructor for Borrow class  
	Borrow();

	// ------------------------------------Borrow-------------------------------------
	// Parametrized constructor for Borrow class
	Borrow(ifstream&, BinTree*&, BinTree*&, BinTree*&, HashTable*&);

	// -----------------------------------~Borrow()-----------------------------------
	// Destructor for Borrow class
	~Borrow();

	// -----------------------------------doTransaction-------------------------------
	// Carry out a transaction (borrow) for the rental store.
	// Declared as "abstract class" in transaction.h. 
	virtual void doTransaction();

private:
	virtual void setData(ifstream&);	// Sets data from file to variables

	HashTable* clientsHashTable;	// Pointer to hash table of customers
	BinTree* bstComedies;	// Pointer to binary tree of comedy movies
	BinTree* bstDramas;		// Pointer to binary tree of drama movies
	BinTree* bstClassics;	// Pointer to binary tree of classic movies

	Customer* curCustomer;	// Pointer to customer borrowing the movie

	Movie* movieToFind;		// Movie being borrowed (Information is set in doTransaction())
	bool doAction;			// Variable which states if doTransaction can be executed or not
	string garbage;			// String used to remove garbage information in file
	string stringToFind;	// Movie info set in stringToFind from file
	string searchByInfo;	// Used by classic movie type to search for the same object in bst

	// Properties of movie to borrow
	int idNum, releaseYear, releaseMonth;
	char mediaType, movieType;
	string movieTitle, movieDirector, majorActor, releaseDate;

};
#endif