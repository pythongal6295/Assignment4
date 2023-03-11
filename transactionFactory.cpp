#include "transactionFactory.h"

// ----------------------------------createTransactionObject----------------------------------
// Creates new transaction object with switch, using first letter from current 
// string line in data4commands.txt (BusinessLogic::loadCommands())
Transaction* TransactionFactory::createTransactionObject(ifstream& infile)
{
	Transaction* selection;
	char command;
	infile >> command; //Set command to first char in file

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
}