#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <iostream>
#include "Transaction.h"
#include "Account.h"

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

