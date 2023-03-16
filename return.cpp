// ---------------------------------------------- return.cpp ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 2/25/23
// Date of Last Modification: 3/16/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Implementation file for class Return. Handles return of a movie
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Return is the child class of Transaction
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------

#include "return.h"

// -----------------------------------Return()-----------------------------------
// Default constructor for Return class
Return::Return()
{
	idNum = 0;
	releaseYear = 0;
	releaseMonth = 0;
	mediaType = '\0';
	movieType = '\0';
	movieTitle = "";
	movieDirector = "";
	majorActor = "";
	doAction = true;
	curCustomer = nullptr;
}

// -----------------------------------Return------------------------------------
// Parametrized constructor for Borrow class. Uses setData() if inputs are valid
// to set Return's private data members.
Return::Return(ifstream& infile, BinTree*& bstF, BinTree*& bstD, BinTree*& bstC, HashTable*& ht) : Return()
{
	doAction = true;		// Set action as true by default to execute transaction

	// Set pointers to data structures
	clientsHashTable = ht;
	bstComedies = bstF;
	bstDramas = bstD;
	bstClassics = bstC;

	infile >> idNum >> mediaType >> movieType;

	curCustomer = ht->getFromTable(idNum);	// Get pointer of customer from hashTable

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

// -----------------------------------~Return()-----------------------------------
// Destructor for Return class
Return::~Return() {}

// -----------------------------------doTransaction-----------------------------------
// Carry out a return for the rental store
void Return::doTransaction()
{
	if (doAction != false) {
		//movieToFind->setSort(stringToFind);
		Movie* p = nullptr;	// Points to movie if found in BST
		bool found = false;

		// Pick from what BST we're returning the movie (Comedies, classics or dramas)
		switch (movieType) {
		case 'F':
			movieToFind = new Comedy(stringToFind);
			found = bstComedies->retrieve(*movieToFind, p);
			break;
		case 'C':
			movieToFind = new Classics(stringToFind);
			found = bstClassics->retrieve(*movieToFind, p);
			break;
		case 'D':
			movieToFind = new Drama(stringToFind);
			found = bstDramas->retrieve(*movieToFind, p);
			break;
		default:
			break;
		}
		// If movie was found, complete transaction (return movie)
		if (p != nullptr && found == true) {
			p->returnMovie();	//Return (stock + 1)
			// Set transaction in customer history
			curCustomer->insertHistoryNode(p, 'R');
			delete movieToFind;
			movieToFind = nullptr;
		} else {
			// If movie not found, do not set transaction in customer history
			cout << "Movie not found" << endl;
		}
	}
}

// -----------------------------------setData--------------------------------------
// Sets data from file to variables. Wrong inputs are discarded and transaction is
// not executed.
void Return::setData(ifstream& infile)
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
		movieDirector.erase(0, 1);
		stringToFind = movieDirector + ' ' + movieTitle;
		break;
	default:	// Unknown movie type
		cout << endl << "Invalid video code" << endl;
		getline(infile, garbage);	// Discard data from current line in file
		doAction = false;	// Don't execute transaction
		break;
	}
}