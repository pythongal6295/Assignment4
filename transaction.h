// ---------------------------------------------- transaction.h ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 3/9/23
// Date of Last Modification: 2/25/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Header file for base class Transaction
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Transaction is the base class for Borrow, Return, Show, and History classes
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <fstream>
#include <string>
#include "bintree.h"
#include"hashTable.h"

using namespace std;

class Transaction
{
public:
	// -----------------------------------Transaction()-----------------------------------
	// Default constructor for Transaction class
	Transaction();

	// ----------------------------------~Transaction()-----------------------------------
	//Default deconstructor for Transaction class
	~Transaction();

	// -----------------------------------doTransaction-----------------------------------
	// Carry out a transaction (command) for the rental store
	// Declared as "abstract class". 
	// Parameters are 
	virtual void doTransaction() = 0;

private:
	// -----------------------------------setData-----------------------------------
	// Sort using the data structure which has all movies, it's being build for the first time. 
	// Delared as "abstract class". 
	// Parameters are string (remaining current command line from data4movies.txt)
	virtual void setData(ifstream&) = 0;

};
#endif