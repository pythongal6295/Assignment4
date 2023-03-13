#include "movie.h"

Movie::Movie() {}

Movie::~Movie() {}

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
