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
}

Return::Return(ifstream& infile) :Return()
{
	infile >> idNum >> mediaType >> movieType;
	setData(infile);
	// If invalid customerID or media type
	if (mediaType != 'D') {
		cout << endl << "Invalid type of media" << endl;
		getline(infile, garbage);
		doAction = false;
	}
	// If invalid customerID or media type
}

Return::~Return()
{
}

void Return::doTransaction()
{
	if (doAction != false) {}
}

// TO DO: See if data is correct for movies (wrong input)
void Return::setData(ifstream& infile)
{
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
		cout << endl << "Invalid video code" << endl;
		getline(infile, garbage);
		doAction = false;
		break;
	}
	//// If movieType is comedy, classic or drama, save movie information
	//	if (movieType == 'F' || movieType == 'C' || movieType == 'D') {
	//		switch (movieType) {
	//		case 'F':
	//			// Store location string in NodeData array
	//			getline(infile, movieTitle, ',');
	//			infile >> releaseYear;
	//			break;
	//		case 'C':
	//			infile >> releaseMonth >> releaseYear;
	//			getline(infile, majorActor, ',');
	//			break;
	//		case 'D':
	//			getline(infile, movieDirector, ',');
	//			getline(infile, movieTitle, ',');
	//			break;
	//		}
	//	} else {	// Else movieType is unknown,
	//		cout << "Invalid video code";
	//	}
	//	// If file empty stop
	//	//if (infile.eof()) break;		// Stop if no more lines of data
}