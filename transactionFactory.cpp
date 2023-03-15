#include "transactionFactory.h"

// -----------------------------------TransactionFactory()-----------------------------------
// Default constructor for TransactionFactory class
TransactionFactory::TransactionFactory()
{
}

// -----------------------------------~TransactionFactory()-----------------------------------
// Destructor for TransactionFactory class
TransactionFactory::~TransactionFactory()
{
}

// ----------------------------------createTransactionObject----------------------------------
// Creates new transaction object with switch, using first letter from current 
// string line in data4commands.txt (BusinessLogic::loadCommands())
//Transaction* TransactionFactory::createTransactionObject(char command, ifstream& infile)
Transaction* TransactionFactory::createTransactionObject(char command, ifstream& infile, BinTree*& bstF, BinTree*& bstD, BinTree*& bstC, HashTable*& ht)
//Transaction* TransactionFactory::createTransactionObject(char command, ifstream& infile, BinTree*& bstF, BinTree*& bstD, BinTree*& bstC)
{
	Transaction* selection = nullptr;

	// Create a new object with the data in the first line of infile
	switch (command) {
	case 'B':
		selection = new Borrow(infile, bstF, bstD, bstC, ht);
		break;
	case 'R':
		selection = new Return(infile, bstF, bstD, bstC, ht);
		break;
	case 'I':
		selection = new Show(bstF, bstD, bstC);
		break;
	case 'H':
		selection = new History(infile);
		break;
	}
	return selection;
}