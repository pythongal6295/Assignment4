#include "return.h"

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

//Return::Return(ifstream& infile, BinTree*& bstF, BinTree*& bstD, BinTree*& bstC) : Return()
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

Return::~Return() {}

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