// ---------------------------------------------- hashTable.h ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 2/25/23
// Date of Last Modification: 3/16/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Header file for HashTable class
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Hash table is built using an array of CustomerNode pointers
//  -Closed hashing with a double hash function is used
// Assumptions:
//	-The movie store will have a maximum of 100 customers
// ---------------------------------------------------------------------------------------------------------------
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <fstream>
#include "customer.h"
using namespace std;

// Set hashTable size to 223 because we're execting a maximun of 100 customers. To avoid collisions chose a prime number number > 2*#customers
const int SIZE_HT = 223;	// Max number of cells in hashTable

// -----------------------------struct CustomerNode-------------------------------------
// The structure represent a node of type CustomerNode.
// CustomerNode node is used to create a hash table.
struct CustomerNode
{
	int hashValue;				//hash value/index of array calculated by hash function
	Customer* headCustomer;		//pointer to customer object
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
	// Parameter: pointer to Customer object
	void setInTable(Customer*);

	// ----------------------------------getFromTable------------------------------------
	// Function to get a Customer from hash table using customer ID
	//Parameter: int - customer ID
	//Return: pointer to Customer object
	Customer* getFromTable(int);

private:
	// ----------------------------------hashFunctions------------------------------------
	// Function that returns a hash from customer ID for adding a new customer
	//Parameter: int - customer ID
	//Return: int - hash
	int hashFunctionSet(int);

	// Function that returns a hash from customer ID for retrieving a customer
	//Parameter: int - customer ID
	//Return: int - hash
	int hashFunctionGet(int);

	CustomerNode* hashTable[SIZE_HT]; // hash table of CustomerNode* 
};

#endif