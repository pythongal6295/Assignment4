#include "return.h"

Return::Return()
{
	idNum = 0, releaseYear = 0, releaseMonth = 0;
	mediaType = '\0', movieType = '\0';
	string movieTitle = "", movieDirector = "", majorActor = "";
}

Return::Return(ifstream& infile)
{
	infile >> idNum >> mediaType >> movieType;
	// if invalid customerID or media type
}

Return::~Return()
{
}

void Return::doTransaction()
{

}

void Return::setData(ifstream& infile)
{
// If movieType is comedy, classic or drama, save movie information
	if (movieType == 'F' || movieType == 'C' || movieType == 'D') {
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
		}
	} else {	// Else movieType is unknown,
		cout << "Invalid video code";
	}
	// If file empty stop
	//if (infile.eof()) break;		// Stop if no more lines of data
}