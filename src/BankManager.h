#ifndef BANKMANAGER_H
#define BANKMANAGER_H

#include "Database.h"
#include "BankManager.h"
#include "Invoice.h"
#include "Deposit.h"
#include "Withdraw.h"
#include "Transfer.h"
#include "Account.h"

#include <iostream>
#include <iomanip>

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

	bool findUsername(string username);
	bool login(string name, string pas);

	void addAccount(Account account);
	void removeAccount(Account account);
	void addPerson(Person person);
	
	Person getPerson(string username) const;
	Account getAccount(long long accountNumber);
	vector<Account> getAccountsOf(Person person) const;
	int getNumberOfAccounts(Person person) const;

	void printInformation(Account account);
	void printInformation(Person person);
	void clearInvoice();
	void printInvoice(Account account);

	void deposit(Account account, double amount);
	void withdraw(Account account, double amount);
	void transfer(Account accountFrom, Account accountTo, double amount);
};

#endif