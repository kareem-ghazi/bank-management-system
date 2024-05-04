#ifndef BANKMANAGER_H
#define BANKMANAGER_H

#include <iostream>

using namespace std;

class BankManager
{
private:
    int num;
    int currency;
    double Dollar, Riyal, Euro, Dinar, Pound;

public:
    BankManager();

    void setvalue();
    double result();
};

#endif