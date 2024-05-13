#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Person.h"
#include <iostream>

using namespace std;

class Account {
private:
	Person owner;
	long long accountNumber;
	double balance;

	long long generateAccountNumber();

public:
	Account();
	Account(Person owner);
	Account(Person owner, long long accountNumber, double balance);

	Person getOwner() const;
	void setOwner(Person owner);
	long long getAccountNumber() const;
	double getBalance() const;
	void setBalance(double balance);
};

#endif

