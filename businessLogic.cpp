#include "businessLogic.h"

// -----------------------------------loadMovies-------------------------------------
// Uses private data member movieFactory to use MovieFactory::createMovieObject() 
// public function to create a new movie genre object(Comedy, Drama or Classics). 
// Calls Movie::insert(string, Movie * root) to include each line from file. 
void BusinessLogic::loadMovies(ifstream& infile)
{
	char movieType;
	MovieFactory curType;
	Movie* newMovie;
	for (;;) {
		infile >> movieType;
		// If movieType is comedy, classic or drama insert information in binary tree node
		if (movieType == 'F' || movieType == 'C' || movieType == 'D') {
			newMovie = curType.createMovieObject(infile);
			//newMovie->insert(infile);

			switch (movieType) {
			case 'F':
				comediesBST.insert(newMovie);
				break;
			case 'C':
				classicsBST.insert(newMovie);
				break;
			case 'D':
				dramasBST.insert(newMovie);
				break;
			}
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
	TransactionFactory curType;
	Transaction* newTransaction;
	for (;;) {
		infile >> transaction;
		// If transaction type is borrow, return, show inventory or show client history, do transaction
		if (transaction == 'B' || transaction == 'R' || transaction == 'I' || transaction == 'H') {
			newTransaction = curType.createTransactionObject(transaction);
			newTransaction->setData(infile);
			newTransaction->doTransaction();
		}
		// If transaction type is unknown, then read next line in file if not empty
		if (infile.eof()) break;		// Stop if no more lines of data
	}
}