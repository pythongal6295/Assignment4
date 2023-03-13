#include "movieFactory.h"

// -----------------------------------MovieFactory()-----------------------------------
// Default constructor for MovieFactory class
MovieFactory::MovieFactory()
{
}

// -----------------------------------~MovieFactory()-----------------------------------
// Destructor for MovieFactory class
MovieFactory::~MovieFactory()
{
}

// ----------------------------------createMovieObject----------------------------------
// Creates new movie genre object with switch, using first letter from current 
// string line in data4movies.txt (BusinessLogic::loadMovies())
Movie* MovieFactory::createMovieObject(char movieType, ifstream& infile)
{
	Movie* selection = nullptr;
	string garbage;

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
		getline(infile, garbage);	//	TO IMPROVE
		cout << "Invalid movie code" << endl;
		break;
	}
	return selection;
}