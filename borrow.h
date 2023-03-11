// ---------------------------------------------- borrow.h ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 3/9/23
// Date of Last Modification: 2/25/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Header file for class Borrow. Handles borrowing of a movie
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Borrow is the child class of Transaction
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------
#ifndef BORROW_H
#define BORROW_H

#include <iostream>
#include <fstream>
#include "transaction.h"
using namespace std;

class Borrow:public Transaction
{
public:
	// Default constructor for Borrow class  
	Borrow();

	// Default destructor for Borrow class
	~Borrow();

	virtual void doTransaction();
	virtual void setData(ifstream&);

private:
	int customerID, releaseYear, releaseMonth;
	char mediaType, movieType;
	string movieTitle, movieDirector, majorActor;

};
#endif