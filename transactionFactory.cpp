#include "transactionFactory.h"
Transaction* TransactionFactory::createTransactionObject(char command){
  Transaction * selection;
  switch(command){
    case 'B':
      selection= new Borrow();
    break;
    case 'R':
      selection = new Return();
    break;
    case 'I':
      selection = new Show();
    break;
    case 'H':
      selection = new History();
    break;
  }
}