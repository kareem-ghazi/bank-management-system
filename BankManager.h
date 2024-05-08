#ifndef BANKMANAGER_H
#define BANKMANAGER_H

#include "Database.h"
#include "BankManager.h"
#include <iostream>

using namespace std;

// converts currency
// accesses accounts (including transactions for each one)
// adds accounts & removes accounts
// manages database

// FOR FARIS: Transfer from account to account
// passing object inside parameter
class BankManager
{
private:
	Database database;
	int num;
	int currency;
	double Dollar, Riyal, Euro, Dinar, Pound;

public:
	BankManager();

	void setvalue();
	double result();
};

#endif