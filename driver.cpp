//Test file for Assignment 4


#include "businessLogic.h"
#include <iostream>
#include <fstream>

using namespace std;


int main()
{

	BusinessLogic movieStore;

	ifstream infile1("data4customers.txt");
	if (!infile1) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	ifstream infile2("data4movies.txt");
	if (!infile2) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	ifstream infile3("data4commands.txt");
	if (!infile3) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	movieStore.loadCustomers(infile1);
	//movieStore.loadMovies(infile2);
	//movieStore.loadCommands(infile3);

}
