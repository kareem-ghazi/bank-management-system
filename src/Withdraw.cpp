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
	this->amount = amount;
}
