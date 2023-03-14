// ---------------------------------------------- classics.cpp ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 3/10/23
// Date of Last Modification: 2/25/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Implementation file for derived class Classics
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Movie is the base class for Classics
//  -Sorted by release date, then Major actor
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include "classics.h"

//Default constructor for Comedy 
Classics::Classics()
{
	month = 0;
	year = 0;
	//stock = 0;
	title = "";
	director = "";
	firstName = "";
	lastName = "";
}

// -----------------------------------Classics-----------------------------------
// Parametrized constructor for Classics, ifstream parameter type
Classics::Classics(ifstream& infile)
{
	string temp;

	getline(infile, temp, ',');
	setStock(stoi(temp));
	getline(infile, director, ',');
	director.erase(0, 1);//Removing front blank space
	getline(infile, title, ',');
	title.erase(0, 1);//Removing front blank space
	infile >> firstName >> lastName >> month >> year;
	getline(infile, temp);
	releaseDate = to_string(year) + ' ' + to_string(month);
	majorActor = firstName + ' ' + lastName;

	setSort(releaseDate + ' ' + majorActor);
	setDisplay(releaseDate + ',' + majorActor + ',' + title + ',' + director + ',');
}

Classics::~Classics() {}

//// -----------------------------------Operator==---------------------------------
//// Overloading == operator
//bool Classics::operator==(const Classics& rhs) const
//{
//	if (releaseDate==rhs.releaseDate && majorActor==rhs.majorActor && title==rhs.title && director==rhs.director) {
//		return true;
//	}
//	return false;
//}

// -----------------------------------display-----------------------------------
// Outputs to the screen all of the details of the movie (Release Date, Title, Director, Stock, Major Actor)
//void Classics::display()
//{
//	cout << "*********************************************************" << endl;
//	cout << "Title: " << getTitle() << endl;
//	cout << "Release Date: " << getMonth() << " " << getYear() << endl;
//	cout << "Major Actor: " << getMajorActor() << endl;
//	cout << "Director: " << getDirector() << endl;
//	cout << "Stock: " << getStock() << endl;
//}

//// -----------------------------------getMonth-----------------------------------
//// Returns the year of the movie
//int Classics::getMonth()
//{
//	return month;
//}
//
//// -----------------------------------getYear-----------------------------------
//// Returns the year of the movie
//int Classics::getYear()
//{
//	return year;
//}
//
//// -----------------------------------getTitle-----------------------------------
//// Returns the title of the movie
//string Classics::getTitle()
//{
//	return title;
//}
//
//// -----------------------------------getStock-----------------------------------
//// Returns the stock of the movie
//int Classics::getStock()
//{
//	return stock;
//}
//
//// -----------------------------------getDirector-----------------------------------
//// Returns the name of the directory of the movie
//string Classics::getDirector()
//{
//	return director;
//}
//
//// -----------------------------------getMajorActor-----------------------------------
//// Returns the name of the major actor of the movie
//string Classics::getMajorActor()
//{
//	return majorActor;
//}
//// -----------------------------------setStock-----------------------------------
//// Sets a new value for the stock depending on borrow/rent actions
//// Parameter: int - the new stock value
//void Classics::setStock(int newStock)
//{
//	stock = newStock;
//	//stock += newStock;	// Add newStock to current stock
//}



//// -----------------------------------Operator==---------------------------------
//// Overloading == operator
//bool Classics::operator==(const Classics &rhs) const
//{
//	if (director==rhs.director && title==rhs.title && releaseDate==rhs.releaseDate) {
//
//	}
//
//	//director
//	//title
//	//release day
//	return false;
//}
//
//// -----------------------------------Operator!=---------------------------------
//// Overloading != operator
//bool Classics::operator!=(const Movie&) const
//{
//	return false;
//}
//
//// -----------------------------------Operator>----------------------------------
//// Overloading > operator
//bool Classics::operator>(const Movie&) const
//{
//	return false;
//}
//
//// -----------------------------------Operator<----------------------------------
//// Overloading < operator
//bool Classics::operator<(const Movie&) const
//{
//	return false;
//}


