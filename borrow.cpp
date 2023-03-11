#include "borrow.h"



Borrow::Borrow()
{
	customerID = 0, releaseYear = 0, releaseMonth = 0;
	mediaType = '\0', movieType = '\0';
	string movieTitle = "", movieDirector = "", majorActor = "";
}

Borrow::~Borrow()
{
}

void Borrow::doTransaction()
{

}

void Borrow::setData(ifstream& infile)
{
	infile >> customerID >> mediaType >> movieType;
	// If invalid customerID or media type

	// If movieType is comedy, classic or drama, save movie information
	if (movieType == 'F' || movieType == 'C' || movieType == 'D') {
		switch (movieType) {
		case 'F':
			// Store location string in NodeData array
			getline(infile, movieTitle,',');
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
		}
	} else {	// Else movieType is unknown,
		cout << "Invalid video code";
	}
}