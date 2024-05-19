#ifndef INVOICE_H
#define INVOICE_H

#include "Account.h"
#include "Deposit.h"
#include "Withdraw.h"
#include "Transfer.h"

#include <vector>

class Invoice
{
private:
	Account account;
	vector<Deposit> deposits;
	vector<Withdraw> withdraws;
	vector<Transfer> transfers;

public:
	vector<Deposit> getDeposits() const;
	vector<Withdraw> getWithdraws() const;
	vector<Transfer> getTransfers() const;

	void addTransaction(Deposit deposit);
	void addTransaction(Withdraw withdraw);
	void addTransaction(Transfer transfer);
	void clearTransactions();
	
	Account getAccount();
	void setAccount(Account account);
};

#endif

