// ---------------------------------------------- Assignment_4.cpp ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Jessica Lee Chan
// Maria Ixchel Arias Cruz
// Brenda S. Vega Contreras 
// Creation Date : 2/25/23
// Date of Last Modification: 2/25/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Driver file where a businessLogic object is created to test the movie store
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -Main is like a UI
//  -Files will be loaded into a ifstream variable and sent to the businessLogic component
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include "businessLogic.h"
using namespace std;

int main()
{
	//// Save movies in infileMov
	//ifstream infileMov("data4movies.txt");
	//if (!infileMov) {
	//	cout << "File could not be opened." << endl;
	//	return 1;
	//}

	//// Save customers in infileCus
	//ifstream infileCus("data4customers.txt");
	//if (!infileCus) {
	//	cout << "File could not be opened." << endl;
	//	return 1;
	//}

	// Save commands in infileCom
	ifstream infileCom("data4commands.txt");
	if (!infileCom) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	BusinessLogic movieStore;

	//movieStore.loadMovies(infileMov);
	//movieStore.loadCustomers(infileMov);
	movieStore.loadCommands(infileCom);	// Read commands line by line in BusinessLogic::loadCommands()


}
