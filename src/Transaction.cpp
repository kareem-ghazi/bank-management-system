#include "Transaction.h"

// Gets the date of the transaction.
string Transaction::getDate() const {
	return this->date;
}

// Sets the date of the transaction.
void Transaction::setDate(string date) {
	this->date = date;
}

// Gets the amount of the transaction.
double Transaction::getAmount() const {
	return this->amount;
}

// Sets the amount of the transaction.
void Transaction::setAmount(double amount)
{
	this->amount = amount;
}
