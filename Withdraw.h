#ifndef WITHDRAW_H
#define WITHDRAW_H

#include "Transaction.h"
#include "Account.h"
#include <cassert>

class Withdraw : public Transaction
{
private:
	Account account;

public:
	Account getAccount() const;
	void setAccount(Account account);

	void setAmount(double amount);
};

#endif

