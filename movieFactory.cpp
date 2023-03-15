// ---------------------------------------------- movieFactory.cpp ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 2/25/23
// Date of Last Modification: 3/16/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Header file for MovieFactory class
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------

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
		cout << endl << "Invalid movie code" << endl;
		break;
	}
	return selection;
}