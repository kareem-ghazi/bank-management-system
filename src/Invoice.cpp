#include "Invoice.h"

// Returns a vector of the deposits.
vector<Deposit> Invoice::getDeposits() const
{
    return this->deposits;
}

// Returns a vector of the withdraws.
vector<Withdraw> Invoice::getWithdraws() const
{
    return this->withdraws;
}

// Returns a vector of the transfers.
vector<Transfer> Invoice::getTransfers() const
{
    return this->transfers;
}

// Adds a deposit transaction to the deposits.
void Invoice::addTransaction(Deposit deposit)
{
    deposits.push_back(deposit);
}

// Adds a withdraw transaction to the withdraws.
void Invoice::addTransaction(Withdraw withdraw)
{
    withdraws.push_back(withdraw);
}

// Adds a transfer transaction to the transfers.
void Invoice::addTransaction(Transfer transfer)
{
    transfers.push_back(transfer);
}

// Clears the transactions from the invoice.
void Invoice::clearTransactions()
{
    deposits.clear();
    withdraws.clear();
    transfers.clear();
}

// Gets the account that's linked to the invoice.
Account Invoice::getAccount()
{
    return this->account;
}

// Sets the account that's linked to the invoice.
void Invoice::setAccount(Account account)
{
    this->account = account;
}