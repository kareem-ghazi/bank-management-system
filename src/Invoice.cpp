#include "Invoice.h"

Transaction Invoice::getTransaction()
{
    return this->transaction;
}

void Invoice::setTransaction(Transaction transaction)
{
    this->transaction = transaction;
}

Account Invoice::getAccount()
{
    return this->account;
}

void Invoice::setAccount(Account account)
{
    this->account = account;
}

void Invoice::printInvoice()
{
    cout << "name is: " << account.getOwner().getName();
    cout << "Account Number is:" << account.getAccountNumber();
}
