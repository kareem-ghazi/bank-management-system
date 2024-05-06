#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

using namespace std;

class Transaction // HAS BEEN EDITED (BOTH .H AND .CPP)
{
private:

protected:
	string date;
	double amount;

public:
	string getDate() const;
	void setDate(string date);
	double getAmount() const;
};

#endif
