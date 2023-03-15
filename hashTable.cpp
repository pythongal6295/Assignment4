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
//  -If data clustering happens when inserting a new customer in hashTable, current cell
//   will point to a linked list with all customers and it will be added to the front of //   the linked list (new headCustomer).
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------

#include "hashTable.h"
#include <string>

  //-----------------------------------HashTable ()------------------------------------
HashTable::HashTable()
{
	//initialize the array with NULLs for each index
	for (int i = 0; i < SIZE_HT; i++) {
		hashTable[i] = NULL;
	}
}

// ---------------------------------- ~HashTable--------------------------------------
HashTable::~HashTable()
{
	for (int i = 0; i < SIZE_HT; i++) {
		//delete each customer node
		delete hashTable[i];
	}
}

// ----------------------------------hashFunctionSet------------------------------------
  // Function that returns a hash from customer ID for adding a new customer
int HashTable::hashFunctionSet(int customerID)
{
	//h(x)  = h % 39
	//D(i) = i * h_2
	//h_2(x) = 7 - (x % 7)

	int index = 0;
	int collisionNum = 0;
	int prevIndex = 0;

	index = customerID % 39;
	prevIndex = index;

	//check if there is an open spot in the array or if the customer ID at the current index matches the one passed into this function
	//Do we need to check if there is a duplicate Customer ID? Answer: Yes, I think it's a good idea -Brenda
	/*while (hashTable[index] != NULL || hashTable[index]->headCustomer->getIdNum() != customerID) {*/
	while (hashTable[index] != NULL) {
		collisionNum++;
		index = (prevIndex + collisionNum * (7 - (customerID % 7))) % 39;
	}

	return index;

}

// ----------------------------------hashFunctionGet------------------------------------
  // Function that returns a hash from customer ID for retrieving a customer
int HashTable::hashFunctionGet(int customerID)
{
	//h(x)  = h % 39
	//D(i) = i * h_2
	//h_2(x) = 7 - (x % 7)

	int index = 0;
	int collisionNum = 0;
	int prevIndex = 0;
	bool indexCheck;

	index = customerID % 39;
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
			index = (prevIndex + collisionNum * (7 - (customerID % 7))) % 39;
		}

	}

	return index;
}
    // -----------------------------------setInTable-------------------------------------	
  // Function to set Customer object in hashTable[]
void HashTable::setInTable(Customer * customer){
    int index = 0;

    //Create a new CustomerNode
    CustomerNode * newCustomer = new CustomerNode;
    newCustomer->headCustomer = customer;

    index = hashFunctionSet(customer->getIdNum());

    newCustomer->hashValue = index;

    hashTable[index] = newCustomer;
    
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
