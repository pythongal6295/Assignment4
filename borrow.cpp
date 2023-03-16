// ---------------------------------------------- borrow.cpp ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 3/9/23
// Date of Last Modification: 3/16/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Implementation file for class Borrow. Handles borrowing of a movie
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Borrow is the child class of Transaction.
//  -When retreiving a movie from bst, return: -1 not found, 0 movie found but not in stock, 1 found.
//	-For classics, when movie found but out of stock. Look for same movie with different major actors first when 
//   movie not found, then if all are out stock print "out of stock" message.
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------

#include "borrow.h"

// -----------------------------------Borrow()-----------------------------------
// Default constructor for Borrow class
Borrow::Borrow()
{
	idNum = 0, releaseYear = 0, releaseMonth = 0;
	mediaType = '\0', movieType = '\0';
	movieTitle = "", movieDirector = "", releaseDate = "";
	doAction = true;
	clientsHashTable = nullptr;
	bstComedies = nullptr;
	bstDramas = nullptr;
	bstClassics = nullptr;
	curCustomer = nullptr;
}

// -----------------------------------Borrow-----------------------------------
// Parametrized constructor for Borrow class. Uses setData() if inputs are valid
// to set Borrow's private data members.
Borrow::Borrow(ifstream& infile, BinTree*& bstF, BinTree*& bstD, BinTree*& bstC, HashTable*& ht) :Borrow()
{
	doAction = true;		// Set action as true by default to execute transaction

	// Set pointers to data structures
	clientsHashTable = ht;
	bstComedies = bstF;
	bstDramas = bstD;
	bstClassics = bstC;

	infile >> idNum >> mediaType >> movieType;

	curCustomer = ht->getFromTable(idNum); // Get pointer of customer from hashTable

	// If valid customerID, continue
	if (curCustomer != NULL) {
		// If invalid media type, no transaction is to be done
		if (mediaType != 'D') {
			cout << "Invalid type of media" << endl;
			doAction = false;			// Do not execute transaction
			getline(infile, garbage);	// Discard information in current line
		} else {
			// Else, continue setting data members with information in file
			setData(infile);
		}
	} else {	// If invalid customer ID, discard information
		cout << "Invalid customer ID" << endl;
		doAction = false;	// Do not execute transaction
		getline(infile, garbage);
	}
}

// -----------------------------------~Borrow()-----------------------------------
// Destructor for Borrow class
Borrow::~Borrow() {}

void Borrow::doTransaction()
{
	// If command codes are correct (true), execute transaction
	if (doAction != false) {
		movieToFind.setSort(stringToFind);	// Set movie to be found
		movieToFind.setActionCode('B');		// Set type of action (borrow)
		Movie* p = nullptr;	// Points to movie if found in BST
		int inStock = -2; // Set to -2 by default. 
		// inStock = -1 not found, 0 movie found but not in stock, 1 found

		bool stockAvailable = false;

		// Pick from what BST we're getting the movie (Comedies, classics or dramas)
		switch (movieType) {
		case 'F':
			// For classics and dramas only can get inStock = 1 (found) or 0 (not found)
			inStock = bstComedies->retrieve(movieToFind, p);
			break;
		case 'C':
			// If inStock = 0 do another search in bst only with release date, title, and director
			// If inStock = 1 movie was found in bst
			// If inStock = -1 movie not found in bst
			inStock = bstClassics->retrieve(movieToFind, p); 
			//// If found but not in stock, find same movie with different major actor
			//if (inStock == 0) {
			//	// Compare release date, title and director instead of comparing release date and major actor.
			//	movieToFind.setMovieInfo(p->getMovieInfo(), 'C');
			//	// If instock is 1 movie was found, if not found it's -1
			//	inStock = bstClassics->retrieve(movieToFind, p);
			//}
			break;
		case 'D':
			// For dramas only can get inStock = 1 (found) or 0 (not found)
			inStock = bstDramas->retrieve(movieToFind, p);
			break;
		default: // If movieType is unknown, do nothing. newMovie is set to NULL in MovieFactory
			break;
		}
		// If movie was found, complete transaction (borrow movie)
		if (inStock == 1 && p != nullptr) {
			stockAvailable = p->borrowMovie();	//Borrow (stock - 1)
			// If movie is out of stock
			if (stockAvailable == false) {
				cout << "Movie out of stock" << endl;
			} else {	// If movie is in stock
				// Set transaction in customer history
				curCustomer->insertHistoryNode(p, 'B');
			}
		} else {
			cout << "Movie not found" << endl;
		}
	}
	// If invalid command code, discard transaction
}

// -----------------------------------setData--------------------------------------
// Sets data from file to variables. Wrong inputs are discarded and transaction is
// not executed.
void Borrow::setData(ifstream& infile)
{
	// If movieType is comedy, classic or drama, save movie information in data members
	switch (movieType) {
	case 'F':	// Comedies
		getline(infile, movieTitle, ',');
		movieTitle.erase(0, 1); // Removing front blank space
		infile >> releaseYear;
		stringToFind = movieTitle + ' ' + to_string(releaseYear);
		break;
	case 'C':	// Classics
		infile >> releaseMonth >> releaseYear;
		getline(infile, majorActor);
		majorActor.erase(0, 1);
		stringToFind = to_string(releaseYear) + ' ' + to_string(releaseMonth) + ' ' + majorActor;
		break;
	case 'D':	// Dramas
		getline(infile, movieDirector, ',');
		movieDirector.erase(0, 1);
		getline(infile, movieTitle, ',');
		movieTitle.erase(0, 1);
		stringToFind = movieDirector + ' ' + movieTitle;
		break;
	default:	// Unknown movie type
		cout << endl << "Invalid video code" << endl;
		getline(infile, garbage);	// Discard data from current line in file
		doAction = false;	// Don't execute transaction
		break;
	}
}