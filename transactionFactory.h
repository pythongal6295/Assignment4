// ---------------------------------------------- transactionFactory.h ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 3/9/23
// Date of Last Modification: 2/25/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Header file for class TransactionFactory
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------
#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

#include <iostream>
#include <fstream>

#include "history.h"
#include "borrow.h"
#include "show.h"
#include "return.h"

using namespace std;

class TransactionFactory
{
public:
	// -----------------------------------TransactionFactory()-----------------------------------
	// Default constructor for TransactionFactory class
	TransactionFactory();

	// -----------------------------------~TransactionFactory()-----------------------------------
	// Destructor for TransactionFactory class
	~TransactionFactory();

	// ----------------------------------createTransactionObject----------------------------------
	// Creates new transaction object with switch, using first letter from current 
	// string line in data4commands.txt (BusinessLogic::loadCommands())
	//static Transaction* createTransactionObject(char, ifstream&, BinTree*&, BinTree*&, BinTree*&);
	static Transaction* createTransactionObject(char, ifstream&, BinTree*&, BinTree*&, BinTree*&, HashTable*&);
};

#endif