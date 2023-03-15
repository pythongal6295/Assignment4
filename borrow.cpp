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

	curCustomer = ht->getFromTable(to_string(idNum));

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
		Movie* p = nullptr;
		bool found = false;
		bool stockAvailable = false;

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
		default: // If movieType is unknown, do nothing. newMovie is set to NULL in MovieFactory
			break;
		}
		if (p != nullptr && found == true) {
			//cout << "Movie to borrow: " << p->getSort() << " Stock: " << p->getStock() << endl;
			stockAvailable = p->borrowMovie();	//Borrow stock -1
			//cout << "Movie after borrow: " << p->getSort() << " Stock: " << p->getStock() << endl;

			if (stockAvailable == false) {
				cout << "Movie out of stock" << endl;
			} else {
				// Set transaction in customer history
				curCustomer->insertHistoryNode(p, movieType); // We can modify parameter to receive char insted of string (Note)
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
		movieTitle.erase(0, 1);
		stringToFind = movieDirector + ' ' + movieTitle;
		break;
	default:
		cout << endl << "Invalid video code" << endl;
		getline(infile, garbage);
		doAction = false;
		break;
	}
}