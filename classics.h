// ---------------------------------------------- classics.h ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 2/25/23
// Date of Last Modification: 2/25/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Header file for derived class Classics
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Movie is the base class for Classics
//  -Sorted by release date, then Major actor
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------
#ifndef CLASSICS_H
#define CLASSICS_H

#include <iostream>
#include <fstream>
#include <string>
#include "movie.h"

using namespace std;

class Classics : public Movie
{
public:
	// -----------------------------------Classics()-----------------------------------
	// Default constructor for Classics class
	Classics();

	// -----------------------------------Classics-----------------------------------
	// Paramaterized constructor for Classics, multiple data parameter
	//Classics(string title, string director, int month, int year, int currStock, string majorActor);

	// -----------------------------------Classics-----------------------------------
	// Parametrized constructor for Classics, ifstream parameter type
	Classics(ifstream&);

	// -----------------------------------~Classics()-----------------------------------
	// Destructor for Classics
	virtual ~Classics();

	// -----------------------------------display-----------------------------------
	// Outputs to the screen all of the details of the movie (Release Date, Title, Director, Stock, Major Actor)
	void display();

	// -----------------------------------getMonth-----------------------------------
	// Returns the year of the movie
	int getMonth();

	// -----------------------------------getYear-----------------------------------
	// Returns the year of the movie
	int getYear();

	// -----------------------------------getTitle-----------------------------------
	// Returns the title of the movie
	string getTitle();

	// -----------------------------------getStock-----------------------------------
	// Returns the stock of the movie
	int getStock();

	// -----------------------------------getDirector-----------------------------------
	// Returns the name of the directory of the movie
	string getDirector();

	// -----------------------------------getMajorActor-----------------------------------
	// Returns the name of the major actor of the movie
	string getMajorActor();

	// -----------------------------------setStock-----------------------------------
	// Sets a new value for the stock depending on borrow/rent actions
	// Parameter: int - the new stock value
	void setStock(int);

	// -----------------------------------insert-----------------------------------
	// This movie object inserts itself into the Classics binary search tree
	//parameters: string - remaining current command line from data4movies.txt
	//void insert(ifstream&);

	//// -----------------------------------Operator==---------------------------------
	//// Overloading == operator
	//virtual bool operator==(const Classics&) const;

	//// -----------------------------------Operator!=---------------------------------
	//// Overloading != operator
	//virtual bool operator!=(const Classics&) const;

	//// -----------------------------------Operator>----------------------------------
	//// Overloading > operator
	//virtual bool operator>(const Classics&) const;

	//// -----------------------------------Operator<----------------------------------
	//// Overloading < operator
	//virtual bool operator<(const Classics&) const;
	//
	//// Struct of ll node to find same movie in stock
	//struct listNode
	//{
	//	Classics* item;
	//	listNode* next;
	//};


private:
	//listNode* head;
	//string sortC; // V1

	// Describes a node composed of information about the classics movie object.
	// The created node is added to the Classics binary search tree
	//struct ClassicsBST {
	// int year;  //year of specific classics movie
	// int stock; //stock of specific classics movie
	// int month; //month of specific classics movie
	// string title;  //title of specific classics movie
	// string director;  //director of specific classics movie
	// string majorActor; //major actor of specific classics movie
	// ClassicsBST *right;  //pointer to right child in BST
	// ClassicsBST *left;  //pointer to left child in BST
	//};

	//Since we have a node structure in NodeData, we may not need another node structure for each movie type
	//Also I couldn't figure out how to do a getter with the structure
	int stock; //stock of specific classics movie
	int year;  //release year of specific classics movie
	int month; //release month of specific classics movie
	string title;  //title of specific classics movie
	string director;  //director of specific classics movie
	string firstName; //Major actor's first name
	string lastName; //Major actor's last name
	string releaseDate;
	string majorActor;

	// Overload of operators == and > if implemented for nodeBST in BinTree
	//bool operator==(const Classics&) const;
	//bool operator>(const Classics&) const;

};
#endif