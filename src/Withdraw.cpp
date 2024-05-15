#include "Withdraw.h"

Withdraw::Withdraw(Account account)
{
	this->account = account;
}

Account Withdraw::getAccount() const
{
    return this->account;
}

void Withdraw::setAccount(Account account)
{
    this->account = account;
}

void Withdraw::setAmount(double amount)
{
	if (account.getBalance() >= amount)
	{
		this->amount = amount;
	}
	else {
		cout << "Error: Couldn't withdraw money. Not enough in balance." << endl;
		//assert(false);
	}
}
