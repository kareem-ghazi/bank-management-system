#include "Account.h"

Account::Account(double initialBalance) : balance(initialBalance)
{

}

double Account::getBalance() const {
	return balance;
}

void Account::deposit(double amount)
{
	if (amount > 0) {
		balance += amount;
		cout << "Deposit Successful. Current Balance: $" << balance << endl;
	}
	else {
		cout << "Error: Invalid Deposit Amount." << endl;
	}
}

void Account::withdraw(double amount) {
	if (amount >= 0 && amount <= balance) {
		balance -= amount;
		cout << "Withdrawal Successful. Current Balance:" << balance << "\n";
	}
	else {
		cout << "Wrong Withdrawal Amount / Insufficient Funds." << endl;
	}
}



