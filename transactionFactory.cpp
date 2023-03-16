// ---------------------------------------------- transactionFactory.cpp ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 3/9/23
// Date of Last Modification: 3/16/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Implementation file for class TransactionFactory
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------

#include "transactionFactory.h"

// -----------------------------------TransactionFactory()-----------------------------------
// Default constructor for TransactionFactory class
TransactionFactory::TransactionFactory() {}

// -----------------------------------~TransactionFactory()-----------------------------------
// Destructor for TransactionFactory class
TransactionFactory::~TransactionFactory() {}

// ----------------------------------createTransactionObject----------------------------------
// Creates new transaction object with switch, using first letter from current 
// string line in data4commands.txt (BusinessLogic::loadCommands())
Transaction* TransactionFactory::createTransactionObject(char command, ifstream& infile, BinTree*& bstF, BinTree*& bstD, BinTree*& bstC, HashTable*& clients)
{
	Transaction* selection = nullptr;

	// Create a new object with the data in the first line of infile.
	switch (command) {
	case 'B':
		selection = new Borrow(infile, bstF, bstD, bstC, clients);
		break;
	case 'R':
		selection = new Return(infile, bstF, bstD, bstC, clients);
		break;
	case 'I':
		selection = new Show(bstF, bstD, bstC);
		break;
	case 'H':
		selection = new History(infile, clients);
		break;
	}
	return selection;
}