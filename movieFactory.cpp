#include "movieFactory.h"

// ----------------------------------createMovieObject----------------------------------
// Creates new movie genre object with switch, using first letter from current 
// string line in data4movies.txt (BusinessLogic::loadMovies())
Movie* MovieFactory::createMovieObject(char movieType, ifstream& infile)
{
	//char movieType;
	//infile >> movieType; // Set first character (movieType) in line

	Movie* selection = nullptr;

	// Create an object with all the movie information
	switch (movieType) {
	case 'F':
		selection = new Comedy(infile);
		break;
	case 'D':
		selection = new Drama(infile);
		break;
	case 'C':
		selection = new Classics(infile);
		break;
	default:	// If movieType is invalid, set pointer to NULL
		break;
	}
	return selection;
}