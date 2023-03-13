#include "movie.h"

Movie::Movie() {}

Movie::~Movie() {}

// -----------------------------------display-----------------------------------
// Outputs to the screen all of the details of the movie (Year, Title, Director, Stock)
void Movie::setDisplay(string input)
{
	toDisplay = input;
}

// -----------------------------------setSort-----------------------------------
// Sets private variable sort
void Movie::setSort(string input)
{
	sort = input;
}

// -----------------------------------getSort()-----------------------------------
// Gets variable sort
string Movie::getSort()
{
	return sort;
}

bool Movie::operator==(const Movie& rhs) const
{
	return (sort == rhs.sort);
}

bool Movie::operator!=(const Movie& rhs) const
{
	return !(*this == rhs);
}

bool Movie::operator>(const Movie& rhs) const
{
	return (sort > rhs.sort);
}

bool Movie::operator<(const Movie& rhs) const
{
	return (sort < rhs.sort);
}

//-------------------------- operator<< --------------------------------------
ostream& operator<<(ostream& output, const Movie& nd)
{
	output << nd.toDisplay;
	return output;
}
