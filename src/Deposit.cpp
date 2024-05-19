#include "Deposit.h"

Deposit::Deposit(Account account)
{
	this->account = account;
}

Account Deposit::getAccount() const
{
    return this->account;
}

void Deposit::setAccount(Account account)
{
    this->account = account;
}

void Deposit::setAmount(double amount)
{
	if (amount >= 0)
	{
		this->amount = amount;
	}
	else {
		cout << "[!] Error: Invalid amount for depositing." << endl;
	}
}
