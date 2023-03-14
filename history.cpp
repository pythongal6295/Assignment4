// ---------------------------------------------- history.cpp ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 3/9/23
// Date of Last Modification: 2/25/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Header file for class History. Display's a customer's rental history
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -History is the child class of Transaction
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------

#include "history.h"

History::History()
{
	idNum = "";
}

History::History(ifstream& infile, HashTable*& clients):History()
{
	infile >> idNum;
	customerTable = clients;
}

History::~History()
{
}

void History::doTransaction(HashTable* customerTable)
{
	Customer* currentCustomer;
	currentCustomer = customerTable->getFromTable(idNum);
	currentCustomer->displayHistory();
}

void History::setData(ifstream& infile)
{
}
