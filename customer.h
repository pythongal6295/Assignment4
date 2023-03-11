// ---------------------------------------------- customer.h ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Jessica Lee Chan
// Maria Ixchel Arias Cruz
// Brenda S. Vega Contreras 
// Creation Date : 2/25/23
// Date of Last Modification: 2/25/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Header file for Customer class
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -
// Assumptions:
//
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
	string typeOfTransaction; // Borrowing or returning item
	customerHistory* next;	// Pointer to previous transaction (pointing to next History item in LL)
};

class Customer
{
public:

// -----------------------------------Customer()-----------------------------------
// Default constructor for Movie class
Customer();

// -----------------------------------Customer()-----------------------------------
// Parameterized constructor for Movie class from a istream object
Customer(istream&);

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


// -----------------------------------setCustomerInfo-----------------------------------
// Set customer information from a istream object
bool setCustomerInfo(istream& input);

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
customerHistory* lastTransaction;	// Pointer to last borrowed or returned movie (history) (transaction at the front of LL)
list<customerHistory> customerHistory; //Linked List of specific customer's history transactions
};

#endif
