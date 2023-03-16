// ---------------------------------------------- customer.h ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 2/25/23
// Date of Last Modification: 3/16/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Header file for Customer class
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Each history transaction for the customer is stored as a node in a linked list
//  -The node is defined as a customerHistory structure
// 
// Assumptions:
//	-Data from the customer text file is in the correct format and data type
// ---------------------------------------------------------------------------------------------------------------
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <fstream>
#include "movie.h"
#include <list>
using namespace std;

// -----------------------------------struct History-----------------------------------
// The structure represent a node of type History.
// The created node is added to the transactions LL.
struct customerHistory
{
	Movie* currentMovie;	// Pointer to the movie that was borrowed or returned
	char typeOfTransaction; // Borrowing or returning item
};


class Customer
{

public:

	// -----------------------------------Customer()-----------------------------------
	// Default constructor for Movie class
	Customer();

	// -----------------------------------Customer()-----------------------------------
	// Parameterized constructor for Movie class from a istream object
	Customer(ifstream&);

	// -----------------------------------~Customer()-----------------------------------
	// Destructor for class Customer 
	// Deallocates dinamic memory to the heap
	~Customer();

	// -----------------------------------displayHistory-----------------------------------
	// Output all the transactions of a customer
	void displayHistory();

	// -----------------------------------void displayCustomer-----------------------------------
	// Output Customer information 4 digit ID number, last name and first name.  
	void displayCustomer();

	// -----------------------------------void displayTransaction-----------------------------------
	// Output Transaction movie information
	void displayHistoryNode(const customerHistory*);

	// -----------------------------------inserHistoryNode-----------------------------------
	// insert new history node to LL with information from history class, pointer to movie, type of transaction
	void insertHistoryNode(Movie*, char);

	// -----------------------------------getIDNum------------------------------------------
	// Accessor - get the idNum of an object customer 
	int  getIdNum();

	// -----------------------------------getFirstName------------------------------------------
	// Accessor - get the firstName of an object customer 
	string getFirstName();

	// -----------------------------------getLastName------------------------------------------
	// Accessor - get the lastName of an object customer 
	string  getLastName();

private:
	// Data members of customer object 
	int idNum; //Specific customer ID number
	string lastName; //Specific customer last name
	string firstName; //Specific customer first name
	list<customerHistory*> historyList; //Linked List of specific customer's history transactions
};

#endif
