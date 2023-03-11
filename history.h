// ---------------------------------------------- history.h ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 3/9/23
// Date of Last Modification: 2/25/23
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Header file for class History. Display's a customer's rental history
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//  -History is the child class of Transaction
// Assumptions:
//
// ---------------------------------------------------------------------------------------------------------------
#ifndef HISTORY_H
#define HISTORY_H

#include <iostream>
#include <fstream>
#include "transaction.h"

using namespace std;

class History: public Transaction
{
public:
    // -----------------------------------History()-----------------------------------
  // Default constructor for History class
  History();

  //Default destructor for History class
  ~History();

  void doTransaction();
  void setData(ifstream&);
};

#endif