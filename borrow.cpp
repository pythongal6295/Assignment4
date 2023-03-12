#include "borrow.h"

// Default constructor for Borrow class
Borrow::Borrow()
{
	idNum = 0, releaseYear = 0, releaseMonth = 0;
	mediaType = '\0', movieType = '\0';
	movieTitle = "", movieDirector = "";
	addNode = true;
}

// Constructor with parameter for Borrow class
Borrow::Borrow(ifstream& infile):Borrow()
{
	infile >> idNum >> mediaType >> movieType;
	setData(infile);
	// If invalid customerID or media type
	if (mediaType != 'D') {
		cout << "Invalid type of media";
	}
}

// Default destructor for Borrow class
Borrow::~Borrow()
{

}


void Borrow::doTransaction()
{

}

void Borrow::setData(ifstream& infile)
{
	// If movieType is comedy, classic or drama, save movie information
	//if (movieType == 'F' || movieType == 'C' || movieType == 'D') {
	switch (movieType) {
	case 'F':
		// Store location string in NodeData array
		getline(infile, movieTitle, ',');
		infile >> releaseYear;
		break;
	case 'C':
		infile >> releaseMonth >> releaseYear;
		getline(infile, majorActor, ',');
		break;
	case 'D':
		getline(infile, movieDirector, ',');
		getline(infile, movieTitle, ',');
		break;
	default:
		cout << "Invalid video code";
		getline(infile, garbage);
		break;
	}
	//} else {	// Else movieType is unknown
	//	cout << "Invalid video code";
	//}
}