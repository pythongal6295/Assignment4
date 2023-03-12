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

void History::doTransaction()
{

}

void History::setData(ifstream& infile)
{
}
