// ---------------------------------------------- history.cpp ----------------------------------------------------
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

#include "history.h"

// -----------------------------------History()-----------------------------------
// Default constructor for History class
History::History()
{
	idNum = 0;
	customerTable = nullptr;
}

// Constructor with parameter for History class
History::History(ifstream& infile, HashTable*& clients):History()
{
	infile >> idNum;
	customerTable = clients;
}

//Default destructor for History class
History::~History()
{
}

// -----------------------------------doTransaction-----------------------------------
// Carry out printing customer history for the rental store
void History::doTransaction()
{
	Customer* currentCustomer;
	currentCustomer = customerTable->getFromTable(idNum);
	currentCustomer->displayHistory();
}

// -----------------------------------setData-----------------------------------
// Not needed for this class
void History::setData(ifstream& infile)
{
}
