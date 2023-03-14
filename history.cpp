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
	idNum = 0;
}

History::History(ifstream& infile):History()
{
	infile >> idNum;
}

History::~History()
{
}

void History::doTransaction(HashTable* customerTable)
{
	//look up customer in hashtable

	//call displayHistory
}

void History::setData(ifstream& infile)
{
}
