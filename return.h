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
	// Default constructor for Return class
	Return();

	// Constructor with parameter for Return class
	//Return(ifstream&);

	// Constructor with parameter for Return class
	//Return(ifstream&, BinTree*&, BinTree*&, BinTree*&);//Still missing hashtable
	Return(ifstream&, BinTree*&, BinTree*&, BinTree*&, HashTable*&);//Still missing hashtable

	// Default destructor for Return class
	~Return();

	// -----------------------------------doTransaction-----------------------------------
	// Carry out a return for the rental store
	virtual void doTransaction();

private:
	// -----------------------------------setData-----------------------------------
	// Sort using the data structure which has all movies, it's being build for the first time. 
	virtual void setData(ifstream&);

	HashTable* clientsHashTable;	//hash table of customers
	BinTree* bstComedies;		//binary tree that stores comedy movies
	BinTree* bstDramas;			//binary tree that stores drama movies
	BinTree* bstClassics;		//binary tree that stores classics movies

	Customer* curCustomer;		//customer that is renting

	Movie movieToFind;			//movie that is being rented
	bool doAction;
	int idNum, releaseYear, releaseMonth;
	char mediaType, movieType;
	string movieTitle, movieDirector, majorActor, garbage, stringToFind;
};

#endif