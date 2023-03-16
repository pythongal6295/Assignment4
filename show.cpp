// ---------------------------------------------- show.cpp ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 2/25/23
// Date of Last Modification: 3/16/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Implementation file for class Show. Displays the inventory for all movies.
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Show is the child class of Transaction.
//	-setData() is not used for Show class.
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------

#include "show.h"

// -----------------------------------Show()-----------------------------------
// Default constructor for Show class
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
	// Set pointers to BSTs
	bstComedies = bstF;
	bstDramas = bstD;
	bstClassics = bstC;

}

// -----------------------------------~Show()----------------------------------
//Default destructor for Show class
Show::~Show() {}

// -----------------------------------doTransaction----------------------------
// Show current inventory for the rental store. Uses overloaded operator << for 
// BinTree class
void Show::doTransaction()
{
	cout << endl << "Comedy movies:" << endl << *bstComedies << endl;
	cout << endl << "Drama movies:" << endl << *bstDramas << endl;
	cout << endl << "Classic movies:" << endl << *bstClassics << endl;
}

// -----------------------------------setData-----------------------------------
// Not needed for this class
// Defined as abstract in parent class.
void Show::setData(ifstream& infile){}

