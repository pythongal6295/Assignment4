// ---------------------------------------------- return.h ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 2/25/23
// Date of Last Modification: 2/25/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Header file for class Return. Handles return of a movie
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Return is the child class of Transaction
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------
#ifndef RETURN_H
#define RETURN_H

#include <iostream>
#include <fstream>
#include "transaction.h"

using namespace std;

class Return : public Transaction
{
public:
	// Default constructor for Return class
	Return();

	// Constructor with parameter for Return class
	Return(ifstream&);

	// Default destructor for Show class
	~Return();

	virtual void doTransaction();

private:
	virtual void setData(ifstream&);

	int idNum, releaseYear, releaseMonth;
	char mediaType, movieType;
	string movieTitle, movieDirector, majorActor;
};

#endif