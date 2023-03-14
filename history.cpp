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

void History::doTransaction()
{
	Customer* currentCustomer;
	currentCustomer = customerTable->getFromTable(idNum);
	currentCustomer->displayHistory();
}

void History::setData(ifstream& infile)
{
}
