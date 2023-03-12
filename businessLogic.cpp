#include "businessLogic.h"
#include <iostream>
#include <fstream>
#include <string>

// Default constructor
BusinessLogic::BusinessLogic()
{
	//customerHashTable = new HashTable();	//hash table with all customers
	//comediesBST = new BinTree();    //BST of comedies
	//dramasBST = new BinTree();		  //BST of dramas
	//classicsBST = new BinTree();		//BST of classics
}

BusinessLogic::~BusinessLogic()
{
}

// -----------------------------------loadMovies-------------------------------------
// Uses private data member movieFactory to use MovieFactory::createMovieObject() 
// public function to create a new movie genre object(Comedy, Drama or Classics). 
// Calls Movie::insert(string, Movie * root) to include each line from file. 
void BusinessLogic::loadMovies(ifstream& infile)
{
	string movieType;
	Movie* newMovie;

	for (;;) {
		// Get type of movie
		getline(infile, movieType, ',');

		// Create node newMovie to insert in BST. If invalid movie type, newMovie is set to NULL.
		newMovie = MovieFactory::createMovieObject(movieType[0], infile);

		// If movieType is comedy, classic or drama insert node newMovie in binary tree
		switch (movieType[0]) {
		case 'F':
			//comediesBST->insert(newMovie);
			break;
		case 'C':
			//classicsBST->insert(newMovie);
			break;
		case 'D':
			//dramasBST->insert(newMovie);
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
	//check if file can be opened
	if (!infile) {
		cout << "File could not be opened." << endl;
	}

	//create a new customer;
	else {
		for (;;) {
			Customer c(infile);
			//Add customer to hash table
			customerHashTable.setInTable(&c);

			if (infile.eof()) break;		// Stop if no more lines of data
		}
	}
}

// -----------------------------------loadCommands-----------------------------------
// Reads each command line from file
// Uses public command functions of BusinessLogic ()
void BusinessLogic::loadCommands(ifstream& infile)
{
	char transaction;
	string garbage;
	Transaction* newTransaction;

	for (;;) {
		infile >> transaction;
		// If transaction type is borrow, return, show inventory or show client history, do transaction
		if (transaction == 'B' || transaction == 'R' || transaction == 'I' || transaction == 'H') {
			newTransaction = TransactionFactory::createTransactionObject(transaction, infile);
			newTransaction->doTransaction();
			delete newTransaction;
			newTransaction = nullptr;
		}
		// If transaction type is unknown, empty current line
		else {
			getline(infile, garbage);	//	TO IMPROVE
		}
		if (infile.eof()) break;		// Stop if no more lines of data
	}
}