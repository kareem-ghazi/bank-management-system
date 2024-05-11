#ifndef BANKMANAGER_H
#define BANKMANAGER_H

#include "Database.h"
#include "BankManager.h"
#include "Account.h"
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
	int termenator = 0;

public:
	BankManager();

	void setvalue();
	double result();

	int getTerm();
	bool login(string name, string pas);
	void addPerson(Person userPerson);
};

#endif