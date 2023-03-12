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
Transaction* TransactionFactory::createTransactionObject(char command, ifstream& infile)
{
	Transaction* selection = nullptr;

	// Create a new object with the data in the first line of infile
	switch (command) {
	case 'B':
		selection = new Borrow(infile);
		break;
	case 'R':
		selection = new Return(infile);
		break;
	case 'I':
		selection = new Show();
		break;
	case 'H':
		selection = new History(infile);
		break;
	}
	return selection;
}