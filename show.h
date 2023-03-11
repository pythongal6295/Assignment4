// ---------------------------------------------- show.h ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 2/25/23
// Date of Last Modification: 3/9/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Header file for class Show. Displays the inventory for all movies.
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Show is the child class of Transaction
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

	//Default destructor for Show class
	~Show();

	void doTransaction();

private:
	void setData(ifstream&);

};

#endif
