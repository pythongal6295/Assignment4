#include "borrow.h"

// Default constructor for Borrow class
Borrow::Borrow()
{
	idNum = 0, releaseYear = 0, releaseMonth = 0;
	mediaType = '\0', movieType = '\0';
	movieTitle = "", movieDirector = "";
	doAction = true;
}

// Constructor with parameter for Borrow class
Borrow::Borrow(ifstream& infile) :Borrow()
{
	infile >> idNum >> mediaType >> movieType;
	setData(infile);
	// If invalid customerID or media type
	if (mediaType != 'D') {
		cout << "Invalid type of media" << endl;
		doAction = false;
		getline(infile, garbage);
	}
}

// Default destructor for Borrow class
Borrow::~Borrow()
{

}


void Borrow::doTransaction()
{
	if (doAction != false) {}
}

// TO DO: See if data is correct for movies (wrong input)
void Borrow::setData(ifstream& infile)
{
	// If movieType is comedy, classic or drama, save movie information
	//if (movieType == 'F' || movieType == 'C' || movieType == 'D') {
	switch (movieType) {
	case 'F':
		// Store location string in NodeData array
		getline(infile, movieTitle, ',');
		movieTitle.erase(0, 1); // Removing front blank space
		infile >> releaseYear;
		break;
	case 'C':
		infile >> releaseMonth >> releaseYear;
		getline(infile, majorActor);
		majorActor.erase(0, 1);
		break;
	case 'D':
		getline(infile, movieDirector, ',');
		movieDirector.erase(0, 1);
		getline(infile, movieTitle, ',');
		movieDirector.erase(0, 1);
		break;
	default:
		cout << "Invalid video code" << endl;
		getline(infile, garbage);
		break;
	}
	//} else {	// Else movieType is unknown
	//	cout << "Invalid video code";
	//}
}