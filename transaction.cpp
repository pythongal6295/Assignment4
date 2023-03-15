// ---------------------------------------------- transaction.cpp ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 3/9/23
// Date of Last Modification: 3/16/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Implementation file for base class Transaction
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Transaction is the base class for Borrow, Return, Show, and History classes
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------

#include "transaction.h"

// -----------------------------------Transaction()-----------------------------------
// Default constructor for Transaction class
Transaction::Transaction()
{

}

// ----------------------------------~Transaction()-----------------------------------
//Default deconstructor for Transaction class
Transaction::~Transaction() 
{

}

// -----------------------------------doTransaction-----------------------------------
// Carry out a transaction (command) for the rental store
// Delared as "abstract class". 
void Transaction::doTransaction()
{

}

// -----------------------------------setData-----------------------------------
// Sort using the data structure which has all movies, it's being build for the first time. 
// Delared as "abstract class". 
// Parameters are string (remaining current command line from data4movies.txt)
void Transaction::setData(ifstream&)
{

}