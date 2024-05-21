#include "Withdraw.h"

// Initializes the transaction with an account.
Withdraw::Withdraw(Account account)
{
	this->account = account;
}

// Returns the account withdrawing.
Account Withdraw::getAccount() const
{
    return this->account;
}

// Sets the account withdrawing.
void Withdraw::setAccount(Account account)
{
    this->account = account;
}

// Sets the amount to be withdrawn.
void Withdraw::setAmount(double amount)
{
	if (amount <= 0 || amount >= account.getBalance())
	{
		cout << "[!] Error: Couldn't set the amount of withdraw." << endl;
		return;
	}

	this->amount = amount;
}
