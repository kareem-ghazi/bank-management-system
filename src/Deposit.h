#ifndef DEPOSIT_H
#define DEPOSIT_H

#include "Transaction.h"
#include "Account.h"

#include <iostream>

class Deposit : public Transaction
{
private:
	Account account;

public:
	Deposit(Account account);

	Account getAccount() const;
	void setAccount(Account account);

	void setAmount(double amount);
};

#endif

