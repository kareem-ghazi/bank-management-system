#include "Invoice.h"

vector<Deposit> Invoice::getDeposits() const
{
    return this->deposits;
}

vector<Withdraw> Invoice::getWithdraws() const
{
    return this->withdraws;
}

vector<Transfer> Invoice::getTransfers() const
{
    return this->transfers;
}

void Invoice::addTransaction(Deposit deposit)
{
    deposits.push_back(deposit);
}

void Invoice::addTransaction(Withdraw withdraw)
{
    withdraws.push_back(withdraw);
}

void Invoice::addTransaction(Transfer transfer)
{
    transfers.push_back(transfer);
}

void Invoice::clearTransactions()
{
    deposits.clear();
    withdraws.clear();
    transfers.clear();
}

Account Invoice::getAccount()
{
    return this->account;
}

void Invoice::setAccount(Account account)
{
    this->account = account;
}