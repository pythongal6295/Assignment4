//--------------------------------------businessLogic.cpp----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 2/25/23
// Date of Last Modification: 3/16/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Header file for BusinessLogic class of the inventory tracking system of a movie rental store
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//	- User is notified of invalid inputs and current line of data in file is discarded.
// Assumptions:
//	-All text files are in the correct format.
// ---------------------------------------------------------------------------------------------------------------

#include "businessLogic.h"

// -----------------------------------BusinessLogic()-------------------------------------
// Default constructor for BusinessLogic class
BusinessLogic::BusinessLogic()
{
	customerHashTable = new HashTable();	// Hash table with all customers
	comediesBST = new BinTree();		// BST of comedies
	dramasBST = new BinTree();			// BST of dramas
	classicsBST = new BinTree();		// BST of classics
}

// -----------------------------------~BusinessLogic()------------------------------------
// Destructor for BusinessLogic class
BusinessLogic::~BusinessLogic()
{
	delete comediesBST;
	delete dramasBST;
	delete classicsBST;
	delete customerHashTable;
}

// -----------------------------------loadMovies-------------------------------------
// Uses MovieFactory::createMovieObject() to create a new movie genre object
// (Comedy, Drama or Classics) with information from file.
// Calls BinTree::insert(string, Movie * root) to insert a new movie object in BST.
void BusinessLogic::loadMovies(ifstream& infile)
{
	string movieType;
	Movie* newMovie;

	for (;;) {
		// Get type of movie
		getline(infile, movieType, ',');

		// Create node newMovie to insert in BST. If invalid movie type, newMovie is set to NULL.
		newMovie = MovieFactory::createMovieObject(movieType[0], infile);

		// If movieType is comedy, classic or drama insert node with newMovie item in BST
		switch (movieType[0]) {
		case 'F':
			comediesBST->insert(newMovie);
			break;
		case 'C':
			classicsBST->insert(newMovie);
			break;
		case 'D':
			dramasBST->insert(newMovie);
			break;
		default: // If movieType is unknown, do nothing. newMovie is set to NULL in MovieFactory
			break;
		}

		if (infile.eof()) break;		// Stop if no more lines of data in file
	}
}


// -----------------------------------loadCustomers----------------------------------
// Sets Custumer info in hash table using HashTable::setInTable(string) and an object
// of type Customer
void BusinessLogic::loadCustomers(ifstream& infile)
{
	Customer* c;

	// Create a new customer;
	for (;;) {
		c = new Customer(infile);
		if (c->getIdNum() == 0 && c->getFirstName() == "" && c->getLastName() == "") {
			delete c;
			c = nullptr;
		} else {
			// Add customer to hash table
			customerHashTable->setInTable(c);
		}
		if (infile.eof()) break;		// Stop if no more lines of data
	}

}

// -----------------------------------loadCommands-----------------------------------
// Reads each command line from file. Uses TransactionFactory to create transaction
// object and execute transaction if valid command.
void BusinessLogic::loadCommands(ifstream& infile)
{
	char transaction;	// Type of transaction
	string garbage;		// Garbage from file
	Transaction* newTransaction;	// Pointer to Transaction object created in TransactionFactory
	for (;;) {
	
		infile >> transaction;
		// If transaction type is borrow, return, show inventory or show client history, do transaction
		if (transaction == 'B' || transaction == 'R' || transaction == 'I' || transaction == 'H') {
			newTransaction = TransactionFactory::createTransactionObject(transaction, infile, comediesBST, dramasBST, classicsBST, customerHashTable);
			newTransaction->doTransaction();
			delete newTransaction;
			newTransaction = nullptr;
		}
		// If transaction type is unknown, discard current line from file and notify the user
		else {
			getline(infile, garbage);
			cout << endl << "Invalid action code" << endl;
		}
		if (infile.eof()) break;		// Stop if no more lines of data
	}
}