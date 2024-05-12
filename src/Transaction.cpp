#include "Transaction.h"

string Transaction::getDate() const {
	return this->date;
}

void Transaction::setDate(string date) {
	this->date = date;
}

double Transaction::getAmount() const {
	return this->amount;
}

void Transaction::setAmount(double amount)
{
	this->amount = amount;
}
