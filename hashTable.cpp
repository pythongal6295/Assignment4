// ---------------------------------------------- hashTable.cpp ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 3/10/23
// Date of Last Modification: 3/16/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Implementation file for HashTable class
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Hash table is built using an array of CustomerNode pointers
//  -Closed hashing with a double hash function is used
// Assumptions:
//	-The movie store will have a maximum of 100 customers
// ---------------------------------------------------------------------------------------------------------------

#include "hashTable.h"
#include <string>

//-----------------------------------HashTable ()------------------------------------
//Default constructor
HashTable::HashTable()
{
	//initialize the array with NULLs for each index
	for (int i = 0; i < SIZE_HT; i++) {
		hashTable[i] = NULL;
	}
}

// ---------------------------------- ~HashTable--------------------------------------
//Deconstructor
HashTable::~HashTable()
{
	for (int i = 0; i < SIZE_HT; i++) {
		//delete each customer node
		delete hashTable[i];
	}
}

// ----------------------------------hashFunctionSet------------------------------------
// Function that returns a hash from customer ID for adding a new customer
//Parameter: int - customer ID
//Return: int - hash
int HashTable::hashFunctionSet(int customerID)
{
	//h(x)  = h % 223
	//D(i) = i * h_2
	//h_2(x) = 7 - (x % 7)

	int index = 0;
	int collisionNum = 0;
	int prevIndex = 0;
	int indexCheck = 0;

	//check for duplicate customer, by trying to access the customer in the hash table
	//-1 for an index means the customer does not already exist in the hash table
	indexCheck = hashFunctionGet(customerID);

	//Customer does not already exist, so continue with hash function
	if (indexCheck == -1) {

		index = customerID % 223;
		prevIndex = index;

		//check if there is an open spot in the array or if the customer ID at the current index matches the one passed into this function
		//Do we need to check if there is a duplicate Customer ID? Answer: Yes, I think it's a good idea -Brenda
		/*while (hashTable[index] != NULL || hashTable[index]->headCustomer->getIdNum() != customerID) {*/
		while (hashTable[index] != NULL) {
			collisionNum++;
			index = (prevIndex + collisionNum * (7 - (customerID % 7))) % 223;
		}

	}

	//Customer exists so index is set to arbitrary -2 for setInTable() to handle
	else {
		index = -2;
	}

	return index;

}

// ----------------------------------hashFunctionGet------------------------------------
  // Function that returns a hash from customer ID for retrieving a customer
int HashTable::hashFunctionGet(int customerID)
{
	//h(x)  = h % 223
	//D(i) = i * h_2
	//h_2(x) = 7 - (x % 7)

	int index = 0;
	int collisionNum = 0;
	int prevIndex = 0;
	bool indexCheck;

	index = customerID % 223;
	prevIndex = index;
	indexCheck = false;

	//check if the customer ID at the current index matches the one passed into this function
	while (!indexCheck) {
		//if the current index brings up to a NULL spot, then return the index as -1
		if (hashTable[index] == NULL) {
			index = -1;
			indexCheck = true;
		}

		//if the current index has a customer ID that matches the one passed into the function, then retun that index
		else if (hashTable[index]->headCustomer->getIdNum() == customerID) {
			indexCheck = true;
		}

		//otherwise calculate and try a new index
		else {
			collisionNum++;
			index = (prevIndex + collisionNum * (7 - (customerID % 7))) % 223;
		}

	}

	return index;
}
 // -----------------------------------setInTable-------------------------------------	
// Function to set Customer object in hashTable[]
void HashTable::setInTable(Customer * customer){
    int index = 0;

	
	index = hashFunctionSet(customer->getIdNum());

	//Customer does not already exist in the table
	if (index != -2) {
		//Create a new CustomerNode
		CustomerNode* newCustomer = new CustomerNode;
		newCustomer->headCustomer = customer;

		newCustomer->hashValue = index;

		hashTable[index] = newCustomer;
	}

	//Customer already exists
	else {
		cout << "Customer " << customer->getIdNum() << " already exists in the system" << endl;
	}
    
  }

  // ----------------------------------getFromTable------------------------------------
	// Function to get a Customer from hash table using customer ID
  //return: Return a customer pointer or NULL if a customer doesn't exist
	Customer* HashTable::getFromTable(int customerID){
    int index = 0;
    
    index = hashFunctionGet(customerID);

	if (index != -1) {
		return hashTable[index]->headCustomer;
	}

	//if customer could not be found, then return NULL
	else {
		return NULL;
	}
}
