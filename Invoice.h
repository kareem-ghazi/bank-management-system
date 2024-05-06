#ifndef INVOICE_H
#define INVOICE_H

#include <vector>
#include "Account.h"
#include "Transaction.h"

class Invoice
{
private:
	Account account;
	Transaction transaction;

public:
	Transaction getTransaction();
	void setTransaction(Transaction transaction);
	Account getAccount();
	void setAccount(Account account);

	void printInvoice();
};

#endif

