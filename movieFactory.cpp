#include "movieFactory.h"
// ----------------------------------createMovieObject----------------------------------
// Creates new movie genre object with switch, using first letter from current 
// string line in data4movies.txt (BusinessLogic::loadMovies())

Movie* MovieFactory::createMovieObject(char movieType)
{
	Movie* selection;
	switch (movieType) {
	case 'F':
		selection = new Comedy();
		break;
	case 'D':
		selection = new Drama();
		break;
	case 'C':
		selection = new Classics();
		break;
	default:
		selection = nullptr;
		break;
	}
	return selection;
}