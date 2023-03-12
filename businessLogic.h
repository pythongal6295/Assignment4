// ---------------------------------------------- businessLogic.h ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 2/25/23
// Date of Last Modification: 2/25/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Header file for BusinessLogic class of the inventory tracking system of a movie rental store
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// 
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------
#ifndef BUSINESSLOGIC_H
#define BUSINESSLOGIC_H

#include <iostream>
#include <fstream>
#include <string>
//#include "hashTable.h"
#include "movieFactory.h"
//#include "transaction.h"
#include "transactionFactory.h"
//#include "bintree.h"


using namespace std;

class BusinessLogic
{
public:
	// BusinessLogic() Default constructor
	BusinessLogic();
	// ~BusinessLogic() Default destructor
	~BusinessLogic();

	// -----------------------------------loadMovies-------------------------------------
	// Uses private data member movieFactory to use MovieFactory::createMovieObject() 
	// public function to create a new movie genre object(Comedy, Drama or Classics). 
	// Calls Movie::insert(string, Movie * root) to include each line from file. 
	void loadMovies(ifstream&);

	// -----------------------------------loadCustomers----------------------------------
	// Sets Custumer info in hash table using HashTable::setInTable(string) and an object
	// of type Customer
	void loadCustomers(ifstream&);

	// -----------------------------------loadCommands-----------------------------------
	// Reads each command line from file
	// Uses public command functions of BusinessLogic ()
	void loadCommands(ifstream&);

private:

	//HashTable* customerHashTable;	//hash table with all customers
	//BinTree* comediesBST;    //BST of comedies
	//BinTree* dramasBST;		  //BST of dramas
	//BinTree* classicsBST;		//BST of classics

	//MovieFactory movieFactory; //instance of MovieFactory to create movie objects (Remove)
	//TransactionFactory transactionFactory; //instance of TransactionFactory to create transaction objects (Remove)
};

#endif

