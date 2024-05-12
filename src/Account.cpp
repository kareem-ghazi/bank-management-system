#include "Account.h"

// Empty constructor.
Account::Account()
{

}

// Initializes account with an owner.
Account::Account(Person owner)
{
	this->owner = owner;
	this->balance = 0;
	this->accountNumber = generateAccountNumber();
}

// Initializes an account with an owner, account number, and balance (for reading from database).
Account::Account(Person owner, long long accountNumber, double balance)
{
	this->owner = owner;
	this->balance = balance;
	this->accountNumber = accountNumber;
}

// Returns the owner of the account.
Person Account::getOwner() const
{
	return this->owner;
}

// Sets the owner of the account.
void Account::setOwner(Person owner)
{
	this->owner = owner;
}

// Returns the account number.
long long Account::getAccountNumber() const
{
	return this->accountNumber;
}

// Returns the balance of the account.
double Account::getBalance() const {
	return balance;
}

// Generates an new random account number.
long long Account::generateAccountNumber()
{
	srand(time(0));

	long long randomNumber = 33; // First two digits are constant.

	// For each of the remaining 14 digits in the 16 digit number, make them random.
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



