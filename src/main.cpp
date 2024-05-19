#include <iostream>

#include "Account.h"
#include "Person.h"
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
void printForeignRates();

int main()
{
	while (true)
	{
		cout << "=====================================" << endl;
		cout << "       BANK MANAGEMENT SYSTEM" << endl;
		cout << "            [MAIN MENU]" << endl;
		cout << "=====================================" << endl;
		cout << "[1] Login to user." << endl;
		cout << "[2] Create a new person user." << endl;
		cout << "[3] Save & Quit." << endl;
		cout << "=====================================" << endl;
		cout << "Enter your choice (1 - 3): ";
		int choice;
		cin >> choice;

		// ERROR: Putting any characters in the choice breaks the program. 
		// Must check that it is integer.

		switch (choice)
		{
		case 1:
			loginUser();
			break;
		case 2:
			createUser();
			break;
		case 3:
			cout << "[!] Successfully exited program." << endl;
			return 0;
		default:
			cout << "[!] Error: Invalid choice." << endl;
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
		cout << "[!] Successful login." << endl;
		person = bankManager.getPerson(username);
		userInterface();
	}
	else {
		cout << "[!] Error: Invalid credentials." << endl;
	}
}

void createUser()
{
	cout << "Enter your name: ";
	string name;
	// Clears garbage left over from the previous input operation (such as \n).
	getline(cin >> ws, name);

	cout << "Enter your username: ";
	string username;
	cin >> username;

	if (bankManager.findUsername(username))
	{
		cout << "[!] Error: Username already exists." << endl;
		return;
	}

	if (username.find(';') != string::npos)
	{
		cout << "[!] Error: Semicolon can't be in username." << endl;
		return;
	}

	cout << "Enter your age: ";
	int age;
	cin >> age;

	if (age < 18)
	{
		cout << "[!] Error: Can't create a user account under 18 years old." << endl;
		return;
	}

	cout << "Enter your address: ";
	string address;
	getline(cin >> ws, address);

	cout << "Enter your password: ";
	string password;
	cin >> password;

	Person person(name, username, address, password, age);
	Account account(person);

	bankManager.addPerson(person);
	bankManager.addAccount(account);
}

void userInterface()
{
	while (true)
	{
		cout << "=====================================" << endl;
		cout << "          Welcome, " << person.getUsername() << endl;
		cout << "             [USER MENU]" << endl;
		cout << "=====================================" << endl;
		cout << "[1] Enter an account." << endl;
		cout << "[2] Create an account." << endl;
		cout << "[3] Delete an account." << endl;
		cout << "[4] Print information." << endl;
		cout << "[5] Quit." << endl;
		cout << "=====================================" << endl;
		cout << "Enter your choice (1 - 5): ";
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
			cout << "[!] Successfully logined out." << endl;
			return;
		default:
			cout << "[!] Error: Invalid choice." << endl;
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
	bankManager.clearInvoice();
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
		cout << "=====================================" << endl;
		cout << "          Welcome, " << person.getUsername() << endl;
		cout << " Account Number: (" << account.getAccountNumber() << ")" << endl;
		cout << "            [ACCOUNT MENU]" << endl;
		cout << "=====================================" << endl;
		cout << "[1] Deposit an amount." << endl;
		cout << "[2] Withdraw an amount." << endl;
		cout << "[3] Transfer an amount." << endl;
		cout << "[4] Print an invoice." << endl;
		cout << "[5] Print information." << endl;
		cout << "[6] Check foreign rate for a currency." << endl;
		cout << "[7] Quit." << endl;
		cout << "=====================================" << endl;
		cout << "Enter your choice (1 - 7): ";
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
			printForeignRates();
			break;
		case 7:
			cout << "[!] Successfully logined out." << endl;
			return;
		default:
			cout << "[!] Error: Invalid choice." << endl;
			break;
		}
	}
}

void deposit()
{
	cout << "Enter amount: ";
	double amount;
	cin >> amount;

	// ERROR: Add a limit to the amount.

	bankManager.deposit(account, amount);
}

void withdraw()
{
	cout << "Enter amount: ";
	double amount;
	cin >> amount;

	// ERROR: Add a limit to the amount.

	bankManager.withdraw(account, amount);
}

void transfer()
{
	cout << "Enter amount: ";
	double amount;
	cin >> amount;

	// ERROR: Add a limit to the amount.

	cout << "Enter account number that you want to transfer to: ";
	long long accountNumber;
	cin >> accountNumber;

	Account accountTo = bankManager.getAccount(accountNumber);

	bankManager.transfer(account, accountTo, amount);
}

void printInvoice()
{
	bankManager.printInvoice(account);
}

void printAccountInformation()
{
	bankManager.printInformation(account);
}

void printPersonInformation()
{
	bankManager.printInformation(person);
}

void printForeignRates()
{
	cout << endl << "[1] Dollar (USD)" << endl;
	cout << "[2] Egyptian Pound (EGP)" << endl;
	cout << "[3] Euro (EUR)" << endl;
	cout << "[4] Riyal (SAR)" << endl;
	cout << "[5] Great British Pound (GBP)" << endl;
	cout << "[6] Chinese Yuan (CNY)" << endl;
	
	cout << "Enter a choice (1 - 6): ";
	int inputCurrency;
	cin >> inputCurrency;

	cout << "Enter an amount of the chosen currency: ";
	double amount;
	cin >> amount;

	if (amount <= 0)
	{
		cout << "[!] Error: Invalid amount." << endl;
		return;
	}

	bankManager.printForeignRates(inputCurrency, amount);
}