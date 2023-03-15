// ---------------------------------------------- history.h ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 3/9/23
// Date of Last Modification: 3/16/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Header file for class History. Display's a customer's rental history
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -History is the child class of Transaction
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------
#ifndef HISTORY_H
#define HISTORY_H

#include <iostream>
#include <fstream>
#include "transaction.h"

using namespace std;

class History : public Transaction
{
public:
	// -----------------------------------History()-----------------------------------
	// Default constructor for History class
	History();

	// Constructor with parameter for History class
	History(ifstream&, HashTable*&);

	//Default destructor for History class
	~History();

	// -----------------------------------doTransaction-----------------------------------
	// Carry out printing customer history for the rental store
	virtual void doTransaction();

private:

	// -----------------------------------setData-----------------------------------
	// Sort using the data structure which has all movies, it's being build for the first time. 
	// Parameters are string (remaining current command line from data4movies.txt)
	// Not needed for this class
	virtual void setData(ifstream&);

	int idNum;	//customer's ID number
	HashTable* customerTable;	//hash table that stores all the customers
};

#endif