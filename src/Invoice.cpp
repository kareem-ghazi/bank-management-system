#include "Invoice.h"

vector<Transaction> Invoice::getTransactions() const
{
    return this->transactions;
}

void Invoice::addTransaction(Transaction transaction)
{
    transactions.push_back(transaction);
}

Account Invoice::getAccount()
{
    return this->account;
}

void Invoice::setAccount(Account account)
{
    this->account = account;
}