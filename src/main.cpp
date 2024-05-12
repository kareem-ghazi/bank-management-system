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

int main()
{
	while (true)
	{
		cout << "===============================================" << endl;
		cout << "- Bank Management System: ta3bneen feh wallah -" << endl;
		cout << "===============================================" << endl;
		cout << "[1] Login to user." << endl;
		cout << "[2] Create a new person user." << endl;
		//cout << "[3] admistrator." << endl;
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
		//cout << "[3] Delete an account." << endl;
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
	
}

void createAccount()
{

}