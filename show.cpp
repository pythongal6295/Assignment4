#include "show.h"

Show::Show()
{
	bstComedies = nullptr;
	bstDramas = nullptr;
	bstClassics = nullptr;
}

// -----------------------------------Show()-----------------------------------
// Parametrized constructor for Show class
Show::Show(BinTree*& bstF, BinTree*& bstD, BinTree*& bstC)
{
	bstComedies = bstF;
	bstDramas = bstD;
	bstClassics = bstC;

}


Show::~Show()
{
}

void Show::doTransaction()
{
	cout << endl << "Comedy movies:" << endl << *bstComedies << endl;
	cout << endl << "Drama movies:" << endl << *bstDramas << endl;
	cout << endl << "Classic movies:" << endl << *bstClassics << endl;
}

void Show::setData(ifstream& infile)
{
}

