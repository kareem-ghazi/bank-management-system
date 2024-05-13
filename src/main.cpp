#include <iostream>

#include "Account.h"
#include "Person.h"
#include "Transfer.h"
#include "Database.h"
#include "BankManager.h"

using namespace std;

BankManager bankManager;
Account account;

void loginUser();
void createUser();

void userInterface();
void enterAccount();
void createAccount();
void deleteAccount();

void accountsInterface(Account account);
void deposit(Account account);
void withdraw(Account account);
void transfer(Account accountFrom);
void printInvoice(Account account);

int main()
{
	while (true)
	{
		cout << "===============================================" << endl;
		cout << "- Bank Management System: ta3bneen feh wallah -" << endl;
		cout << "===============================================" << endl;
		cout << "[1] Login to user." << endl;
		cout << "[2] Create a new person user." << endl;
		//cout << "[3] admistrator." << endl; // DONT THINK ITS IMPORTANT AS THE CODE IS GETTING VERY BIG!!!
		cout << "[4] Quit." << endl;
		cout << "Enter your choice: ";
		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
			loginUser();
			break;
		case 2:
			createUser();
			break;
		case 3:
			//bankmaneger(); // fogeit about it 
		case 4:
			cout << "Successfully exited program." << endl;
			return 0;
		default:
			break;
		}
	}

	return 0;
}

void loginUser()
{
	cout << "Enter your username: ";
	string username;
	cin >> username;

	cout << "Enter your password: ";
	string password;
	cin >> password;

	bool status = bankManager.login(username, password); //uncompleat

	if (status)
	{
		cout << "Successful login." << endl;
		account = bankManager.getAccount(username);
		userInterface();
	}
	else {
		cout << "Invalid credentials." << endl;
	}
}

void createUser()
{
	cout << "Enter your name: ";
	string name;
	cin >> name;

	cout << "Enter your username: ";
	string username;
	cin >> username;

	if (bankManager.findUsername(username))
	{
		cout << "Error: Username already exists.";
		return;
	}

	// NOTE: Deal with the exception handling. 
	cout << "Enter your age: ";
	int age;
	cin >> age;

	cout << "Enter your address: ";
	string address;
	cin >> address;

	cout << "Enter your password: ";
	string password;
	cin >> password;

	Person person(name, username, address, password, age);
	Account account(person);

	bankManager.addAccount(account); //done
}

void userInterface()
{
	while (true)
	{
		cout << "===============================================" << endl;
		cout << "- Welcome, " << account.getOwner().getUsername() << ": ta3bneen feh wallah^2 -" << endl;
		cout << "===============================================" << endl;
		cout << "[1] Enter an account." << endl;
		cout << "[2] Create an account." << endl;
		cout << "[3] Delete an account." << endl;
		cout << "[4] Quit." << endl;
		cout << "Enter your choice: ";
		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
			enterAccount();
			break;
		case 2:
			createAccount();
			break;
		case 3:
			deleteAccount();
			break;
		case 4:
			cout << "Successfully logined out." << endl;
			return;
		default:
			break;
		}
	}
}

void enterAccount()
{
	vector<Account> accounts = bankManager.getAccountsOf(account.getOwner());
	
	int i = 0;
	for (i = 0; i < accounts.size(); i++)
	{
		cout << "[" << i + 1 << "]: " << accounts[i].getAccountNumber() << endl; 
	}

	cout << "Enter your choice: ";
	int choice;
	cin >> choice;

	accountsInterface(accounts[choice - 1]);
}

void createAccount()
{

}

void deleteAccount()
{

}

void accountsInterface(Account account)
{
	while (true)
	{
		cout << "===============================================" << endl;
		cout << "- Accounts Interface: " << account.getOwner().getUsername() << ": ta3bneen feh wallah^3 -" << endl;
		cout << "===============================================" << endl;
		cout << "[1] Deposit an amount." << endl;
		cout << "[2] Withdraw an amount." << endl;
		cout << "[3] Transfer an amount." << endl;
		cout << "[4] Print an invoice." << endl;
		cout << "[5] Quit." << endl;
		cout << "Enter your choice: ";
		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
			deposit(account);
			break;
		case 2:
			withdraw(account);
			break;
		case 3:
			transfer(account);
			break;
		case 4:
			printInvoice(account);
			break;
		case 5:
			cout << "Successfully logined out." << endl;
			return;
		default:
			break;
		}
	}
}

void deposit(Account account)
{
	cout << "Enter amount: ";
	double amount;
	cin >> amount;

	bankManager.deposit(account, amount);
}

void withdraw(Account account)
{
	cout << "Enter amount: ";
	double amount;
	cin >> amount;

	//bankManager.withdraw(account, amount);
}

void transfer(Account accountFrom)
{
	cout << "Enter amount: ";
	double amount;
	cin >> amount;

	cout << "Enter account number that you want to transfer to: ";
	long long accountNumber;
	cin >> accountNumber;

	//Account accountTo = bankManager.getAccount(accountNumber);

	//bankManager.transfer(accountFrom, accountTo, amount);
}

void printInvoice(Account account)
{
	//bankManager.printInvoice(account);
}