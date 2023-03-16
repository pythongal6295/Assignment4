// ---------------------------------------------- borrow.cpp ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 3/9/23
// Date of Last Modification: 3/16/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Implementation file for class Borrow. Handles borrowing of a movie
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Borrow is the child class of Transaction
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------

#include "borrow.h"

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

// Constructor with parameter for Borrow class
//Borrow::Borrow(ifstream& infile, BinTree*& bstF, BinTree*& bstD, BinTree*& bstC) :Borrow()
Borrow::Borrow(ifstream& infile, BinTree*& bstF, BinTree*& bstD, BinTree*& bstC, HashTable*& ht) :Borrow()
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
	} else {	// If invalid customer ID
		cout << "Invalid customer ID" << endl;
		doAction = false;
		getline(infile, garbage);
	}
}

// Default destructor for Borrow class
Borrow::~Borrow() {}

void Borrow::doTransaction()
{
	if (doAction != false) {
		movieToFind.setSort(stringToFind);
		movieToFind.setActionCode('B');
		Movie* p = nullptr;
		//bool found = false;
		int inStock = -2; // -1 not found, 0 movie found but not in stock, 1 found
		bool stockAvailable = false;

		switch (movieType) {
		case 'F':
			inStock = bstComedies->retrieve(movieToFind, p);
			break;
		case 'C':
			inStock = bstClassics->retrieve(movieToFind, p); // if return 1 do another search only with title, year and director
			// If found but not in stock, find same movie with different major actor
			if (inStock == 0) {
				//searchByInfo = p->getMovieInfo();//to_string(releaseYear) + ' ' + to_string(releaseMonth) + ' ' + p->getTitle() + ' ' + p->getDirector();
				// Compare release date, title and director instead of comparing release date and major actor.
				//movieToFind.setMovieInfo(searchByInfo, 'C');
				movieToFind.setMovieInfo(p->getMovieInfo() , 'C');
				// If instock is 1 movie was found, if not found it's -1
				inStock = bstClassics->retrieve(movieToFind, p);
			}
			break;
		case 'D':
			inStock = bstDramas->retrieve(movieToFind, p);
			break;
		default: // If movieType is unknown, do nothing. newMovie is set to NULL in MovieFactory
			break;
		}
		if (inStock == 1 && p != nullptr) {
			//cout << "Movie to borrow: " << p->getSort() << " Stock: " << p->getStock() << endl;
			stockAvailable = p->borrowMovie();	//Borrow stock -1
			//cout << "Movie after borrow: " << p->getSort() << " Stock: " << p->getStock() << endl;

			if (stockAvailable == false) {
				cout << "Movie out of stock" << endl;
			} else {
				// Set transaction in customer history
				curCustomer->insertHistoryNode(p, 'B');
			}
			// In classics go to movies with different major actors
		} else {
			cout << "Movie not found" << endl;
		}
	}
}

// TO DO: See if data is correct for movies (wrong input)
void Borrow::setData(ifstream& infile)
{
	// If movieType is comedy, classic or drama, save movie information
	switch (movieType) {
	case 'F':
		// Store location string in NodeData array
		getline(infile, movieTitle, ',');
		movieTitle.erase(0, 1); // Removing front blank space
		infile >> releaseYear;
		stringToFind = movieTitle + ' ' + to_string(releaseYear);
		// Optional: set searchByInfo
		break;
	case 'C':
		infile >> releaseMonth >> releaseYear;
		getline(infile, majorActor);
		majorActor.erase(0, 1);
		stringToFind = to_string(releaseYear) + ' ' + to_string(releaseMonth) + ' ' + majorActor;
		//searchByInfo = to_string(releaseYear) + ' ' + to_string(releaseMonth) + ' ' + movieTitle + ' ' + movieDirector;
		break;
	case 'D':
		getline(infile, movieDirector, ',');
		movieDirector.erase(0, 1);
		getline(infile, movieTitle, ',');
		movieTitle.erase(0, 1);
		stringToFind = movieDirector + ' ' + movieTitle;
		// Optional: set searchByInfo
		break;
	default:
		cout << endl << "Invalid video code" << endl;
		getline(infile, garbage);
		doAction = false;
		break;
	}
}