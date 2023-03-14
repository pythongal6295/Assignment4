// ---------------------------------------------- hashTable.h ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 2/25/23
// Date of Last Modification: 2/25/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Header file for HashTable class
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Hash table is built using an array of CustomerNode pointers
//  -If data clustering happens when inserting a new customer in hashTable, current cell
//   will point to a linked list with all customers and it will be added to the front of //   the linked list (new headCustomer).
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <fstream>
#include "customer.h"
using namespace std;

const int SIZE_HT = 39;	// Max number of cells in hashTable

// -----------------------------struct CustomerNode-------------------------------------
// The structure represent a node of type CustomerNode.
// CustomerNode node is used to create a hash table.
struct CustomerNode
{
	int hashValue;
	Customer* headCustomer;
};

class HashTable
{
public:

  //------------------------------------HashTable------------------------------
  //default constructor
  HashTable();

  //deconstructor
  ~HashTable();

  // -----------------------------------setInTable-------------------------------------	
  // Function to set Customer object in hashTable[]
	void setInTable(Customer *);	

  // ----------------------------------getFromTable------------------------------------
	// Function to get a Customer from hash table using customer ID
	Customer* getFromTable(int);	

private:
  // ----------------------------------hashFunctions------------------------------------
	// Function that returns a hash from customer ID for adding a new customer
	int hashFunctionSet(int);	

	// Function that returns a hash from customer ID for retrieving a customer
  int hashFunctionGet(int);

	CustomerNode * hashTable[SIZE_HT]; // hash table of CustomerNode* 
};

#endif