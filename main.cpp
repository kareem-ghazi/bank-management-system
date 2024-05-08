#include <iostream>

#include "Account.h"
#include "Person.h"
#include "Transfer.h"
#include "Database.h"
#include "BankManager.h"

using namespace std;

//BankManager bankManager;

void loginUser();
void createUser();

int main()
{
	cout << "===============================================" << endl;
	cout << "- Bank Management System: ta3bneen feh wallah -" << endl;
	cout << "===============================================" << endl;
	cout << "1. Login to user." << endl;
	cout << "2. Create a new person user." << endl;
	cout << "Enter your choice: ";
	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1:
		loginUser();
	case 2:
		createUser();
	case 3:
	default:
		break;
	}

	// KAREEM'S CODE
	//Database database;
	//Person person("Kareem", "Gedila Mansoura Egypt", "123456", 19);
	//Account account(person);

	////database.addEntry(account); // CANNOT ADD BALANCE BECAUSE WE CLOSED IT
	//database.load();

	return 0;
}

void loginUser()
{
	do {
		cout << "Enter your username: " << endl;
		string username;
		cin >> username;

		cout << "Enter your password: " << endl;
		string password;
		cin >> password;

		//bankManager.login(username, password);
	} while (true);
}

void createUser()
{
	cout << "Enter your name: ";
	string name;
	cin >> name;

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

	Person person(name, address, password, age);

	//bankManager.addPerson(person);
}