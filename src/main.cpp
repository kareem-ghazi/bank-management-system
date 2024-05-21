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
	// Contains the main menu of the program.
	while (true)
	{
		cout << "=====================================" << endl;
		cout << "       BANK MANAGEMENT SYSTEM" << endl;
		cout << "             [MAIN MENU]" << endl;
		cout << "=====================================" << endl;
		cout << "[1] Login to user." << endl;
		cout << "[2] Create a new person user." << endl;
		cout << "[3] Save & Quit." << endl;
		cout << "=====================================" << endl;
		cout << "Enter your choice (1 - 3): ";

		int choice = 0;
		cin >> choice;
		
		// If the cin fails (input isn't an integer),
		// reset the fail flag of the cin and ignore the rest of the input.
		// Reference: https://en.cppreference.com/w/cpp/io/basic_ios/fail 
		if (cin.fail())
		{
			cin.clear(); // Reset fail flag.
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the bad input up to the last enter pressed ('\n').
		}

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

// Logins the user into a user account.
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

// Creates a new user account.
void createUser()
{
	cout << "Enter your name: ";
	string name;
	// Clears garbage left over from the previous int input operation (such as \n).
	// This is necessary due to the behavior of inputting into an int before a string.
	getline(cin >> ws, name);

	cout << "Enter your username: ";
	string username;
	cin >> username;

	if (bankManager.findUsername(username))
	{
		cout << "[!] Error: Username already exists." << endl;
		return;
	}

	// The .find() returns npos (which means null position) if it couldn't find the character.
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

// The user interface for a user account.
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
		
		int choice = 0;
		cin >> choice;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

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

// Enters a bank account that the user owns.
void enterAccount()
{
	vector<Account> accounts = bankManager.getAccountsOf(person);
	
	int i = 0;
	// Lists all the bank accounts the user has as a menu.
	for (i = 0; i < accounts.size(); i++)
	{
		cout << "[" << i + 1 << "]: " << accounts[i].getAccountNumber() << endl; 
	}

	cout << "Enter your choice: ";
	int choice;
	cin >> choice;

	if (choice <= 0 || choice > i)
	{
		cout << "[!] Error: Invalid choice." << endl;
		return;
	}

	account = accounts[choice - 1];
	bankManager.clearInvoice();
	accountsInterface();
}

// Creates a bank account under a user's name.
void createAccount()
{
	Account account(person);

	cout << "[!] Successfully created a new account." << endl;
	cout << "[!!] Your new account's number is: (" << account.getAccountNumber() << ")" << endl;

	bankManager.addAccount(account);
}

// Deletes a bank account under a user's name.
void deleteAccount()
{
	vector<Account> accounts = bankManager.getAccountsOf(person);

	if (accounts.size() == 1)
	{
		cout << "[!] Error: You can't delete your only bank account." << endl;
		return;
	}

	int i = 0;
	for (i = 0; i < accounts.size(); i++)
	{
		cout << "[" << i + 1 << "]: " << accounts[i].getAccountNumber() << endl;
	}

	cout << "Enter your choice: ";
	int choice;
	cin >> choice;

	if (choice <= 0 || choice > i)
	{
		cout << "[!] Error: Invalid choice." << endl;
		return;
	}

	bankManager.removeAccount(accounts[choice - 1]);
}

// The accounts interface for a bank account under the logined user.
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
		
		int choice = 0;
		cin >> choice;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

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

// Deposits an amount of money to a user's bank account.
void deposit()
{
	cout << "Enter amount: ";
	double amount;
	cin >> amount;

	bankManager.deposit(account, amount);
}

// Withdraws an amount of money from a user's bank account.
void withdraw()
{
	cout << "Enter amount: ";
	double amount;
	cin >> amount;

	bankManager.withdraw(account, amount);
}

// Transfers an amount of money from a user's bank account to another user's bank account given an account number.
void transfer()
{
	cout << "Enter amount: ";
	double amount;
	cin >> amount;

	cout << "Enter account number that you want to transfer to: ";
	long long accountNumber;
	cin >> accountNumber;

	Account accountTo = bankManager.getAccount(accountNumber);

	bankManager.transfer(account, accountTo, amount);
}

// Prints an invoice listing all the transactions done in a bank account session.
void printInvoice()
{
	bankManager.printInvoice(account);
}

// Prints the information of a bank account.
void printAccountInformation()
{
	bankManager.printInformation(account);
}

// Prints the information of a user.
void printPersonInformation()
{
	bankManager.printInformation(person);
}

// Checks the current foreign rates for a given currency and an amount of it.
void printForeignRates()
{
	cout << endl << "[1] Dollar (USD)" << endl;
	cout << "[2] Egyptian Pound (EGP)" << endl;
	cout << "[3] Euro (EUR)" << endl;
	cout << "[4] Riyal (SAR)" << endl;
	cout << "[5] Great British Pound (GBP)" << endl;
	cout << "[6] Chinese Yuan (CNY)" << endl;
	cout << "[7] Kuwaiti Dinar (KWD)" << endl;
	
	cout << "Enter a choice (1 - 7): ";
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