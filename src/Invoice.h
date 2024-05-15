#ifndef INVOICE_H
#define INVOICE_H

#include <vector>
#include "Account.h"
#include "Transaction.h"

class Invoice
{
private:
	Account account;
	vector<Transaction> transactions;

public:
	vector<Transaction> getTransactions() const;
	void addTransaction(Transaction transaction);
	Account getAccount();
	void setAccount(Account account);
};

#endif

