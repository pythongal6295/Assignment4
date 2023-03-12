#include "businessLogic.h"
#include <iostream>
#include <string>

// Default constructor
BusinessLogic::BusinessLogic()
{
	////customerHashTable = new HashTable();	//hash table with all customers
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
	char movieType;
	Movie* newMovie;

	for (;;) {
		infile >> movieType;
		ifstream temp;
		
		// If movieType is comedy, classic or drama insert information in binary tree node
		if (movieType == 'F' || movieType == 'C' || movieType == 'D') {
			newMovie = movieFactory.createMovieObject(movieType, infile);

			switch (movieType) {
			case 'F':
				//comediesBST->insert(newMovie);
				break;
			case 'C':
				//classicsBST->insert(newMovie);
				break;
			case 'D':
				//dramasBST->insert(newMovie);
				break;
			}
		} else {	// Empty current line to get next movieType in file
			//getline(infile);
		}
		// If movieType is unknown, then read next line in file if not empty
		if (infile.eof()) break;		// Stop if no more lines of data
	}
}

void BusinessLogic::loadCustomers(ifstream&)
{

}

// -----------------------------------loadCommands-----------------------------------
	  // Reads each command line from file
	  // Uses public command functions of BusinessLogic ()
void BusinessLogic::loadCommands(ifstream& infile)
{
	char transaction;
	Transaction* newTransaction;

	for (;;) {
		infile >> transaction;
		// If transaction type is borrow, return, show inventory or show client history, do transaction
		if (transaction == 'B' || transaction == 'R' || transaction == 'I' || transaction == 'H') {
			newTransaction = transactionFactory.createTransactionObject(transaction, infile);
			newTransaction->doTransaction();
			delete newTransaction;
			newTransaction = nullptr;

		}
		// If transaction type is unknown, then read next line in file if not empty
		if (infile.eof()) break;		// Stop if no more lines of data
	}
}