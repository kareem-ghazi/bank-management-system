#include "Transfer.h"

// Initializes the transfer with a sender and a receiver.
Transfer::Transfer(Account accountFrom, Account accountTo)
{
	this->accountFrom = accountFrom;
	this->accountTo = accountTo;
}

// Returns the sender account.
Account Transfer::getAccountFrom() const
{
	return this->accountFrom;
}

// Returns the receiver account.
Account Transfer::getAccountTo() const
{
	return this->accountTo;
}

// Set the sender account.
void Transfer::setAccountFrom(Account accountFrom)
{
	this->accountFrom = accountFrom;
}

// Sets the receiver account.
void Transfer::setAccountTo(Account accountTo)
{
	this->accountTo = accountTo;
}

// Sets the amount to be transferred.
void Transfer::setAmount(double amount)
{
	this->amount = amount;
}










