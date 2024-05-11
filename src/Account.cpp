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

Account::Account(Person owner, long long accountNumber, double balance)
{
	this->owner = owner;
	this->balance = balance;
	this->accountNumber = accountNumber;
}

Person Account::getOwner() const
{
	return this->owner;
}

void Account::setOwner(Person owner)
{
	this->owner = owner;
}

long long Account::getAccountNumber() const
{
	return this->accountNumber;
}

double Account::getBalance() const {
	return balance;
}

long long Account::generateAccountNumber()
{
	srand(time(0));

	long long randomNumber = 33;
	for (int i = 0; i < 14; i++) {
		randomNumber = randomNumber * 10 + (rand() % 10);
	}

	return randomNumber;
}

// SATOUR
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



