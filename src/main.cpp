#include <iostream>

#include "Account.h"
#include "Person.h"
#include "Transfer.h"
#include "Database.h"
#include "BankManager.h"

using namespace std;

BankManager bankManager;
Person person;
Account account;

void loginUser();
void createUser();

void userInterface();
void enterAccount();
void createAccount();
void deleteAccount();
void printPersonInformation();

void accountsInterface();
void deposit();
void withdraw();
void transfer();
void printInvoice();
void printAccountInformation();

int main()
{
	while (true)
	{
		cout << "===============================================" << endl;
		cout << "- Bank Management System: ta3bneen feh wallah -" << endl;
		cout << "===============================================" << endl;
		cout << "[1] Login to user." << endl;
		cout << "[2] Create a new person user." << endl;
		cout << "[3] Save." << endl;
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

	bool status = bankManager.login(username, password);

	if (status)
	{
		cout << "Successful login." << endl;
		person = bankManager.getPerson(username);
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

	bankManager.addPerson(person);
	bankManager.addAccount(account); //done
}

void userInterface()
{
	while (true)
	{
		cout << "===============================================" << endl;
		cout << "- Welcome, " << person.getUsername() << ": ta3bneen feh wallah^2 -" << endl;
		cout << "===============================================" << endl;
		cout << "[1] Enter an account." << endl;
		cout << "[2] Create an account." << endl;
		cout << "[3] Delete an account." << endl;
		cout << "[4] Print information." << endl;
		cout << "[5] Save." << endl;
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
			printPersonInformation();
			break;
		case 5:
			cout << "Successfully logined out." << endl;
			return;
		default:
			break;
		}
	}
}

void enterAccount()
{
	vector<Account> accounts = bankManager.getAccountsOf(person);
	
	int i = 0;
	for (i = 0; i < accounts.size(); i++)
	{
		cout << "[" << i + 1 << "]: " << accounts[i].getAccountNumber() << endl; 
	}

	cout << "Enter your choice: ";
	int choice;
	cin >> choice;

	account = accounts[choice - 1];
	accountsInterface();
}

void createAccount()
{
	Account account(person);

	bankManager.addAccount(account);
}

void deleteAccount()
{
	vector<Account> accounts = bankManager.getAccountsOf(person);

	int i = 0;
	for (i = 0; i < accounts.size(); i++)
	{
		cout << "[" << i + 1 << "]: " << accounts[i].getAccountNumber() << endl;
	}

	cout << "Enter your choice: ";
	int choice;
	cin >> choice;

	bankManager.removeAccount(accounts[choice - 1]);
}

void accountsInterface()
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
		cout << "[5] Print information." << endl;
		cout << "[6] Save." << endl;
		cout << "Enter your choice: ";
		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
			deposit();
			break;
		case 2:
			withdraw();
			break;
		case 3:
			transfer();
			break;
		case 4:
			printInvoice();
			break;
		case 5:
			printAccountInformation();
			break;
		case 6:
			cout << "Successfully logined out." << endl;
			return;
		default:
			break;
		}
	}
}

void deposit()
{
	cout << "Enter amount: ";
	double amount;
	cin >> amount;

	bankManager.deposit(account, amount);
}

void withdraw()
{
	cout << "Enter amount: ";
	double amount;
	cin >> amount;

	bankManager.withdraw(account, amount);
}

void transfer()
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

void printInvoice()
{
	//bankManager.printInvoice(account);
}

void printAccountInformation()
{
	bankManager.printInformation(account);
}

void printPersonInformation()
{
	bankManager.printInformation(person);
}