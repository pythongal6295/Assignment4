#include "borrow.h"

// Default constructor for Borrow class
Borrow::Borrow()
{
	idNum = 0, releaseYear = 0, releaseMonth = 0;
	mediaType = '\0', movieType = '\0';
	movieTitle = "", movieDirector = "", releaseDate = "";
	doAction = true;
}

//// Constructor with parameter for Borrow class
//Borrow::Borrow(ifstream& infile) :Borrow()
//{
//	infile >> idNum >> mediaType >> movieType;
//	setData(infile);
//	// If invalid customerID or media type
//	if (mediaType != 'D') {
//		cout << endl << "Invalid type of media" << endl;
//		doAction = false;
//		getline(infile, garbage);
//	}
//}

// Constructor with parameter for Borrow class
Borrow::Borrow(ifstream& infile, BinTree*& bstF, BinTree*& bstD, BinTree*& bstC) :Borrow()
{
	doAction = true;

	bstComedies = bstF;
	bstDramas = bstD;
	bstClassics = bstC;

	infile >> idNum >> mediaType >> movieType;
	// If invalid media type, no transaction is to be done
	if (mediaType != 'D') {
		cout << "Invalid type of media" << endl;
		doAction = false;
		getline(infile, garbage);
	} else {
		setData(infile);
	}

	// If invalid customerID

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
			// Set transaction in customer history
			if (stockAvailable == false) {
				cout << "Movie out of stock" << endl;
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