// ---------------------------------------------- customer.cpp ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 3/12/23
// Date of Last Modification: 3/16/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Implementation file for Customer class
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Each history transaction for the customer is stored as a node in a linked list
//  -The node is defined as a customerHistory structure
// 
// Assumptions:
//	-Data from the customer text file is in the correct format and data type
// ---------------------------------------------------------------------------------------------------------------

#include "customer.h"
#include <string>
#include <iostream>
#include <fstream>

// -----------------------------------Customer()-----------------------------------
// Default constructor for Movie class
Customer::Customer()
{
	idNum = 0;
	firstName = "";
	lastName = "";
	//historyNode = nullptr;
}

// Parameterized constructor for Movie class from a istream object
Customer::Customer(ifstream& infile) :Customer()
{
	infile >> idNum;
	infile >> firstName;
	infile >> lastName;

}

// -----------------------------------~Customer()-----------------------------------
// Destructor for class Customer 
// Deallocates dinamic memory to the heap
Customer::~Customer()
{
	customerHistory* tempHistoryNode;

	// Deallocate memory used for historyNode
	for (list<customerHistory*>::iterator it = historyList.begin(); it != historyList.end(); ++it) {
		tempHistoryNode = *it;
		delete tempHistoryNode;
	}
}

// -----------------------------------displayHistory-----------------------------------
// Output all the transactions of a customer
void Customer::displayHistory()
{

	//run through the history linked list
	//print each attribute from the history struct
	cout << "***********************************" << endl;
	cout << getIdNum() << " " << getFirstName() << " " << getLastName() << "'s Transaction History" << endl;
	for (list<customerHistory*>::iterator it = historyList.begin(); it != historyList.end(); ++it) {
		customerHistory* test = *it;

		displayHistoryNode(test);

		//cout << test;
		//cout << test->currentMovie->getSort() << endl;
		//cout << test->typeOfTransaction << endl;
		//Movie input1 = **it
	}
	//cout << ' ' << *it;



}

// -----------------------------------void displayCustomer-----------------------------------
// Output Customer information 4 digit ID number, last name and first name.
void Customer::displayCustomer()
{
	cout << "***********************************" << endl;
	cout << idNum << endl;
	cout << firstName << endl;
	cout << lastName << endl;
}

//---------------------------------displayHistoryNode()------------------------------------
//Prints out a HistoryNode
void Customer::displayHistoryNode(const customerHistory* ch)
{
	string transaction = "";

	if (ch->typeOfTransaction == 'B') {
		transaction = "Borrowed";
	} else if (ch->typeOfTransaction == 'R') {
		transaction = "Returned";
	} else {
		transaction = "unknown";
	}

	cout << transaction << " : " << ch->currentMovie->getSort() << endl;
}

// -----------------------------------inserHistoryNode-----------------------------------
// insert new history node to LL with information from history class, pointer to movie, type of transaction
void Customer::insertHistoryNode(Movie* movie, char transactionType)
{
	//customerHistory *historyNode = new customerHistory;

	customerHistory* historyNode = new customerHistory();

	historyNode->currentMovie = movie;
	historyNode->typeOfTransaction = transactionType;

	historyList.push_front(historyNode);
}

// -----------------------------------getIDNum------------------------------------------
// Accessor - get the idNum of an object customer 
int Customer::getIdNum()
{
	return idNum;
}
// -----------------------------------getFirstName------------------------------------------
string Customer::getFirstName()
{
	return firstName;
}

// -----------------------------------getLastName------------------------------------------
// Accessor - get the lastName of an object customer 
string Customer::getLastName()
{
	return lastName;
}

////---------------------------------Friend operator <<-----------------------------
////Prints out a HistoryNode
//ostream& operator<<(ostream& output, const customerHistory* ch)
//{
//	string transaction = "";
//
//	if (ch->typeOfTransaction == 'B') {
//		transaction = "Borrowed";
//	}
//
//	else if (ch->typeOfTransaction == 'R') {
//		transaction = "Returned";
//	}
//
//	else {
//		transaction = "unknown";
//	}
//
//	cout << transaction << ch->currentMovie->getSort() << endl;
//
//	return output;
//}
