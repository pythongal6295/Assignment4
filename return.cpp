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

// Constructor with parameter for Return class
Return::Return(ifstream& infile, BinTree*& bstF, BinTree*& bstD, BinTree*& bstC, HashTable*& ht) : Return()
{
	doAction = true;

	clientsHashTable = ht;
	bstComedies = bstF;
	bstDramas = bstD;
	bstClassics = bstC;

	infile >> idNum >> mediaType >> movieType;

	curCustomer = ht->getFromTable(idNum);

	// If valid customerID
	if (curCustomer != NULL) {
		// If invalid media type, no transaction is to be done
		if (mediaType != 'D') {
			cout << "Invalid type of media" << endl;
			doAction = false;
			getline(infile, garbage);
		} else {
			setData(infile);
		}
	} else {	// If invalid customerID
		cout << "Invalid customer ID" << endl;
		doAction = false;
		getline(infile, garbage);
	}
}

// Default destructor for Return class
Return::~Return() {}

// -----------------------------------doTransaction-----------------------------------
// Carry out a return for the rental store
void Return::doTransaction()
{
	if (doAction != false) {
		movieToFind.setSort(stringToFind);
		Movie* p = nullptr;
		bool found = false;

		switch (movieType) {
		case 'F':
			found = bstComedies->retrieve(movieToFind, p);
			break;
		case 'C':
			found = bstClassics->retrieve(movieToFind, p);
			break;
		case 'D':
			found = bstDramas->retrieve(movieToFind, p);
			break;
		default:
			break;
		}
		if (p != nullptr && found == true) {
			//cout << "Movie to return: " << p->getSort() << " Stock: " << p->getStock() << endl;
			p->returnMovie();	//Borrow stock -1
			//cout << "Movie after return: " << p->getSort() << " Stock: " << p->getStock() << endl;
				// Set transaction in customer history
			curCustomer->insertHistoryNode(p, 'R'); // We can modify parameter to receive char insted of string (Note)

			// in classics go to movies with different major actors
		} else {
			cout << "Movie not found";
		}
	}
}

// TO DO: See if data is correct for movies (wrong input)
void Return::setData(ifstream& infile)
{
	// If movieType is comedy, classic or drama, save movie information
	switch (movieType) {
	case 'F':
		// Store location string in NodeData array
		getline(infile, movieTitle, ',');
		movieTitle.erase(0, 1); // Removing front blank space
		infile >> releaseYear;
		stringToFind = movieTitle + ' ' + to_string(releaseYear);
		break;
	case 'C':
		infile >> releaseMonth >> releaseYear;
		getline(infile, majorActor);
		majorActor.erase(0, 1);
		stringToFind = to_string(releaseYear) + ' ' + to_string(releaseMonth) + ' ' + majorActor;
		break;
	case 'D':
		getline(infile, movieDirector, ',');
		movieDirector.erase(0, 1);
		getline(infile, movieTitle, ',');
		movieDirector.erase(0, 1);
		stringToFind = movieDirector + ' ' + movieTitle;
		break;
	default:	// Else movieType is unknown
		cout << endl << "Invalid video code" << endl;
		getline(infile, garbage);
		doAction = false;
		break;
	}
}