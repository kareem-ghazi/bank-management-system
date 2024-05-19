#ifndef TRANSFER_H
#define TRANSFER_H

#include "Account.h"
#include "Transaction.h"

#include <iostream>

using namespace std;

class Transfer : public Transaction
{
private:
    Account accountFrom;
    Account accountTo;
    
public:
    Transfer(Account accountFrom, Account accountTo);
    
    Account getAccountFrom() const;
    Account getAccountTo() const;
    void setAccountFrom(Account accountFrom);
    void setAccountTo(Account accountTo);

    void setAmount(double amount);
};

#endif

