#ifndef TRANSFER_H
#define TRANSFER_H

#include <iostream>
#include "Account.h"
#include "Transaction.h"

using namespace std;

class Transfer : public Transaction
{
private:
    Account accountFrom;
    Account accountTo;
    
public:
    
};

#endif

