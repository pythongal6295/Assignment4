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

	// -----------------------------------History()-----------------------------------
	// Parametrized constructor for History class
	History(ifstream&, HashTable*&);

	// ----------------------------------~History()-----------------------------------
	//Destructor for History class
	~History();

	// ---------------------------------doTransaction----------------------------------
	// Carry out printing customer history for the rental store
	virtual void doTransaction();

private:

	// -----------------------------------setData-----------------------------------
	// Not needed for this class.
	// Defined as abstract in parent class.
	virtual void setData(ifstream&);

	int idNum;	// Customer's ID number
	HashTable* customerTable;	// Points to hash table that stores all the customers
};

#endif