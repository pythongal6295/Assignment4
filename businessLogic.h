// ---------------------------------------------- businessLogic.h ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 2/25/23
// Date of Last Modification: 3/16/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Header file for BusinessLogic class of the inventory tracking system of a movie rental store
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// 
// Assumptions:
//	-All text files are in the correct format
// ---------------------------------------------------------------------------------------------------------------
#ifndef BUSINESSLOGIC_H
#define BUSINESSLOGIC_H

#include <iostream>
#include <fstream>
#include <string>
#include "hashTable.h"
#include "customer.h"
#include "movieFactory.h"
#include "transactionFactory.h"
#include "bintree.h"


using namespace std;

class BusinessLogic
{
public:
	// ----------------------------------BusinessLogic()----------------------------------
	// Default constructor for BusinessLogic class
	BusinessLogic();

	// ----------------------------------~BusinessLogic()---------------------------------
	// Destructor for BusinessLogic class
	~BusinessLogic();

	// ------------------------------------loadMovies-------------------------------------
	// Uses MovieFactory::createMovieObject() to create a new movie genre object
	// (Comedy, Drama or Classics) with information from file.
	// Calls BinTree::insert(string, Movie * root) to insert a new movie object in BST.
	void loadMovies(ifstream&);

	// ------------------------------------loadCustomers----------------------------------
	// Sets Custumer info in hash table using HashTable::setInTable(string) and an object
	// of type Customer
	void loadCustomers(ifstream&);

	// ------------------------------------loadCommands-----------------------------------
	// Reads each command line from file. Uses TransactionFactory to create transaction
	// object and execute transaction if valid command.
	void loadCommands(ifstream&);

private:

	HashTable* customerHashTable;	// Pointer to hash table with all customers
	BinTree* comediesBST;			// Pointer to BST of comedies
	BinTree* dramasBST;				// Pointer to BST of dramas
	BinTree* classicsBST;			// Pointer to BST of classics
};

#endif

