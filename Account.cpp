#include "Account.h"

Account::Account()
{

}

Account::Account(Person owner)
{
	this->owner = owner;
	this->balance = 0;
	this->accountNumber = generateAccountNumber();
}

Person Account::getOwner() const
{
	return this->owner;
}

void Account::setOwner(Person owner)
{
	this->owner = owner;
}

double Account::getBalance() const {
	return balance;
}

// WRITE CODE FOR THIS
long long Account::generateAccountNumber()
{
	return 0;
}

//void Account::deposit(double amount)
//{
//	if (amount > 0) {
//		balance += amount;
//		cout << "Deposit Successful. Current Balance: $" << balance << endl;
//	}
//	else {
//		cout << "Error: Invalid Deposit Amount." << endl;
//	}
//}
//
//void Account::withdraw(double amount) {
//	if (amount >= 0 && amount <= balance) {
//		balance -= amount;
//		cout << "Withdrawal Successful. Current Balance:" << balance << "\n";
//	}
//	else {
//		cout << "Wrong Withdrawal Amount / Insufficient Funds." << endl;
//	}
//}



