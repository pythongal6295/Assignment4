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

using namespace std;

class Borrow :public Transaction
{
public:
	// Default constructor for Borrow class  
	Borrow();

	// Constructor with parameter for Borrow class
	Borrow(ifstream&, BinTree*&, BinTree*&, BinTree*&, HashTable*&);//Still missing hashtable

	// Default destructor for Borrow class
	~Borrow();

	virtual void doTransaction();

private:
	virtual void setData(ifstream&);

	HashTable* clientsHashTable;	//hash table of customers
	BinTree* bstComedies;	//binary tree of comedy movies
	BinTree* bstDramas;		//binary tree of drama movies
	BinTree* bstClassics;	//binary tree of classics movies

	Customer* curCustomer;	//pointer to customer borrowing the movie

	Movie movieToFind;	//movie being borrowed
	bool doAction;
	int idNum, releaseYear, releaseMonth;
	char mediaType, movieType;
	string movieTitle, movieDirector, majorActor, garbage, releaseDate, stringToFind, searchByInfo;

};
#endif