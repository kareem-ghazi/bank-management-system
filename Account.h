#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

using namespace std;

class Account
{
private:
	double balance;

public:
	Account(double initialBalance);

	void deposit(double amount);
	void withdraw(double amount);
	double getBalance() const;
};

#endif

