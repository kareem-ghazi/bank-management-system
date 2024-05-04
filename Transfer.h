#ifndef TRANSFER_H
#define TRANSFER_H

#include <iostream>
#include "Transaction.h"

using namespace std;

class Transfer : public Transaction
{
private:
    double balance_B;

public:
    void main_menu();
};

#endif

