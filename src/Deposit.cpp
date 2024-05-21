#include "Deposit.h"

// Initializes a deposit transaction with an account.
Deposit::Deposit(Account account)
{
	this->account = account;
}

// Gets the account that deposited.
Account Deposit::getAccount() const
{
    return this->account;
}

// Sets the account that deposits.
void Deposit::setAccount(Account account)
{
    this->account = account;
}

// Sets the amount that will be deposited.
void Deposit::setAmount(double amount)
{
	if (amount < 100)
	{
		cout << "[!] Error: Couldn't set the amount of deposit." << endl;
		return;
	}

	this->amount = amount;
}
