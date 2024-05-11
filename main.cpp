#include <iostream>

#include "Account.h"
#include "Person.h"
#include "Transfer.h"
#include "Database.h"
#include "BankManager.h"

using namespace std;

BankManager bankManager;

void loginUser();
void createUser();

int main()
{
	cout << "===============================================" << endl;
	cout << "- Bank Management System: ta3bneen feh wallah -" << endl;
	cout << "===============================================" << endl;
	cout << "[1] Login to user." << endl;
	cout << "[2] Create a new person user." << endl;
	//cout << "[3] admistrator." << endl;
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
	//int tokeen = 1;

	while (true) {
		cout << "Enter your username: " << endl;
		string username;
		cin >> username;

		cout << "Enter your password: " << endl;
		string password;
		cin >> password;

		bool status = bankManager.login(username, password); //uncompleat

		if (status)
		{
			cout << "Successful login." << endl;
			//accountsInterface();
			break;
		}
		else {
			cout << "Invalid credentials." << endl;
		}
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

	bankManager.addPerson(person); //done
}