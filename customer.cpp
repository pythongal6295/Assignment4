// ---------------------------------------------- customer.cpp ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 3/12/23
// Date of Last Modification: 2/25/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Header file for Customer class
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -
// Assumptions:
//
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
}

// Parameterized constructor for Movie class from a istream object
Customer::Customer(ifstream& infile)
{
	infile >> idNum;
	infile >> firstName;
	infile >> lastName;

	//string s;
	////saves ID, first name, and last name from line in file
	//string customerDetails[3];
	//string temp = "";
	//char space = ' ';
	//int arrayCount = 0;

	////get next line from file to build a new customer
	//getline(infile, s);

	////parse the data from the line
	//for (int i = 0; i < s.length(); i++) {
	//	if (s[i] != space) {
	//		temp += s[i];
	//	}

	//	else {
	//		customerDetails[arrayCount] = temp;
	//		arrayCount++;
	//		temp.clear();
	//	}

	//	customerDetails[arrayCount + 1] = temp;
	//}

	//	//set the customer properties based on what was parsed from the file

	//	idNum = stoi(customerDetails[0]);


}

// -----------------------------------~Customer()-----------------------------------
// Destructor for class Customer 
// Deallocates dinamic memory to the heap
Customer::~Customer()
{
}

// -----------------------------------displayHistory-----------------------------------
// Output all the transactions of a customer
void Customer::displayHistory()
{

	//run through the history linked list
	//print each attribute from the history struct
	cout << getFirstName() << " " << getLastName() << "'s Transaction History" << endl;
	for (list<customerHistory>::iterator it = historyList.begin(); it != historyList.end(); ++it)
		cout << ' ' << *it;

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
// -----------------------------------inserHistoryNode-----------------------------------
// insert new history node to LL with information from history class, pointer to movie, type of transaction
void Customer::insertHistoryNode(Movie* movie, char transactionType)
{
	//customerHistory *historyNode = new customerHistory;

	historyNode.currentMovie = movie;
	historyNode.typeOfTransaction = transactionType;

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

//---------------------------------Friend operator <<-----------------------------
//Prints out a HistoryNode
ostream& operator<<(ostream& output, const customerHistory& ch)
{
	string transaction = "";

	if (ch.typeOfTransaction == 'B') {
		transaction = "Borrowed";
	}

	else if (ch.typeOfTransaction == 'R') {
		transaction = "Returned";
	}

	else {
		transaction = "unknown";
	}
	
	cout << transaction << ch.currentMovie << endl;

	return output;
}
