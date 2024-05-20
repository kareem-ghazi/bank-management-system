#ifndef BANKMANAGER_H
#define BANKMANAGER_H

#include "Database.h"
#include "BankManager.h"
#include "Invoice.h"
#include "Deposit.h"
#include "Withdraw.h"
#include "Transfer.h"
#include "Account.h"
#include "Person.h"

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

class BankManager
{
private:
	Invoice invoice;
	Database database;

public:
	BankManager();

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

	void printForeignRates(int inputCurrency, double amount);
	string getDate();
};

#endif