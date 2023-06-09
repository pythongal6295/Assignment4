// ---------------------------------------------- transaction.h ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 3/9/23
// Date of Last Modification: 3/16/23
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
#include "hashTable.h"

using namespace std;

class Transaction
{
public:
	// -----------------------------------Transaction()-----------------------------------
	// Default constructor for Transaction class.
	Transaction();

	// ----------------------------------~Transaction()-----------------------------------
	//Default destructor for Transaction class.
	~Transaction();

	// -----------------------------------doTransaction-----------------------------------
	// Carry out a transaction (command) for the rental store.
	// Declared as "abstract class". 
	virtual void doTransaction() = 0;

private:
	// -----------------------------------setData-----------------------------------------
	// When a line is read from commands file the data is set in each transaction object.
	// Delared as "abstract class". 
	virtual void setData(ifstream&) = 0;
};
#endif