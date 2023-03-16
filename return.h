// ---------------------------------------------- return.h ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 2/25/23
// Date of Last Modification: 3/16/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Header file for class Return. Handles return of a movie
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Return is the child class of Transaction
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------
#ifndef RETURN_H
#define RETURN_H

#include <iostream>
#include <fstream>
#include "transaction.h"

using namespace std;

class Return : public Transaction
{
public:
	// -----------------------------------Return()------------------------------------
	// Default constructor for Return class
	Return();

	// ------------------------------------Return-------------------------------------
	// Constructor with parameter for Return class
	Return(ifstream&, BinTree*&, BinTree*&, BinTree*&, HashTable*&);

	// -----------------------------------~Return()-----------------------------------
	// Default destructor for Return class
	~Return();

	// ---------------------------------doTransaction---------------------------------
	// Carry out a return for the rental store
	// Declared as "abstract class" in transaction.h. 
	virtual void doTransaction();

private:
	// ------------------------------------setData------------------------------------
	// Sort using the data structure which has all movies, it's being build for the 
	// first time. 
	virtual void setData(ifstream&);	// Sets data from file to variables

	HashTable* clientsHashTable;	// Pointer to hash table of customers
	BinTree* bstComedies;		// Pointer to binary tree of comedy movies
	BinTree* bstDramas;			// Pointer to binary tree of drama movies
	BinTree* bstClassics;		// Pointer to binary tree of classic movies

	Customer* curCustomer;		// Pointer to customer returning the movie

	Movie movieToFind;			// Movie being returned (Information is set in doTransaction())
	bool doAction;				// Variable which states if doTransaction can be executed or not
	string garbage;				// String used to remove garbage information in file
	string stringToFind;		// Movie info set in stringToFin from file
	string searchByInfo;		// Used by classic movie type to search for the same object in bst

	// Properties of movie to return
	int idNum, releaseYear, releaseMonth;
	char mediaType, movieType;
	string movieTitle, movieDirector, majorActor;
};

#endif