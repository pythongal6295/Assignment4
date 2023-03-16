// ---------------------------------------------- show.h ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 2/25/23
// Date of Last Modification: 3/16/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Header file for class Show. Displays the inventory for all movies.
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Show is the child class of Transaction.
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------
#ifndef SHOW_H
#define SHOW_H

#include <iostream>
#include <fstream>
#include "transaction.h"

using namespace std;

class Show : public Transaction
{
public:
	// -----------------------------------Show()-----------------------------------
	// Default constructor for Show class
	Show();

	// -----------------------------------Show()-----------------------------------
	// Parametrized constructor for Show class
	Show(BinTree*&, BinTree*&, BinTree*&);

	// -----------------------------------~Show()----------------------------------
	//Destructor for Show class
	~Show();

	// --------------------------------doTransaction-------------------------------
	// Carry out printing current movies inventory for the rental store
	virtual void doTransaction();

private:
	BinTree* bstComedies;	// Pointer to BST for comedy movies
	BinTree* bstDramas;		// Pointer to BST for drama movies
	BinTree* bstClassics;	// Pointer to BST for classics movies

	// -----------------------------------setData----------------------------------
	// Not needed for this class, but has to be included.
	// Defined as abstract in parent class.
	virtual void setData(ifstream&);
};

#endif
