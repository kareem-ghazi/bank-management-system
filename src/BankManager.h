#ifndef BANKMANAGER_H
#define BANKMANAGER_H

#include "Database.h"
#include "BankManager.h"
#include "Invoice.h"
#include "Deposit.h"
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
	Invoice invoice;
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
	void addAccount(Account account);
	Account getAccount(string username) const;
	vector<Account> getAccountsOf(Person person) const;
	void removeAccount(Account account);
	bool findUsername(string username);

	bool deposit(Account account, double amount);
};

#endif