#include "Transfer.h"

Transfer::Transfer(Account accountFrom, Account accountTo)
{
	this->accountFrom = accountFrom;
	this->accountTo = accountTo;
}

Account Transfer::getAccountFrom() const
{
	return this->accountFrom;
}

Account Transfer::getAccountTo() const
{
	return this->accountTo;
}

void Transfer::setAccountFrom(Account accountFrom)
{
	this->accountFrom = accountFrom;
}

void Transfer::setAccountTo(Account accountTo)
{
	this->accountTo = accountTo;
}

void Transfer::setAmount(double amount)
{
	this->amount = amount;
}










