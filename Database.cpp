#include "Database.h"

Database::Database()
{
	this->inputFile.open("data.txt", ios::in);
	
	this->load();

	this->inputFile.close();
}

Database::~Database()
{
	this->outputFile.open("data.txt", ios::out);

	this->save();

	this->outputFile.close();
}

string Database::pasEncrypt(string pas)
{
	int stringSize = pas.size();

	for (int i = 0; i < stringSize; i++)
	{
		if (pas[i] == '4')
		{
			pas[i] = '&';
		}
		else {
			pas[i] = pas[i] + 7;
		}
	}

	return pas;
}   //unlinked

string Database::pasDecrypt(string pas)
{
	int stringSize = pas.size();

	for (int i = 0; i < stringSize; i++)
	{
		if (pas[i] == '&')
		{
			pas[i] = '4';
		}
		else {
			pas[i] = pas[i] - 7;
		}
	}

	return pas;  //unlinked
}

void Database::addEntry(Account account)
{
	accounts.push_back(account);
	/*outputFile << account.getOwner().getName() << ","
		<< account.getOwner().getAddress() << ","
		<< account.getOwner().getPassword() << ","
		<< account.getOwner().getAge() << ","
		<< account.getAccountNumber() << ","
		<< account.getBalance() << endl;*/

	/*for (int i = 0; i < accounts.size(); i++)
	{
		outputFile << accounts[i].getOwner().getName() << ","
			<< accounts[i].getOwner().getAddress() << ","
			<< accounts[i].getOwner().getPassword() << ","
			<< accounts[i].getOwner().getAge() << ","
			<< accounts[i].getAccountNumber() << ","
			<< accounts[i].getBalance() << endl;
	}*/

	//accounts.push_back();
}

void Database::deleteEntry(Account account)
{
	for (int i = 0; i < accounts.size(); i++)
	{
		
	}
}

void Database::load()
{
	string line;

	while (getline(inputFile, line))
	{
		if (line.empty())
		{
			continue;
		}

		string name;
		string username;
		string address;
		string password;
		int age;

		// idea: links line number to account number
		// idea: pointers to vectors
		// SEMICOLON CHANGE
		int comma = line.find(';');
		name = line.substr(0, comma);
		line.erase(0, comma + 1);

		comma = line.find(';');
		username = line.substr(0, comma);
		line.erase(0, comma + 1);

		comma = line.find(';');
		address = line.substr(0, comma);
		line.erase(0, comma + 1);

		comma = line.find(';');
		password = pasDecrypt(line.substr(0, comma));
		line.erase(0, comma + 1);

		comma = line.find(';');
		age = stoi(line.substr(0, comma));
		line.erase(0, comma + 1);

		Person person(name, username, address, password, age);
		people.push_back(person);

		long long accountNumber;
		double balance;

		comma = line.find(';');
		accountNumber = stoll(line.substr(0, comma));
		line.erase(0, comma + 1);

		comma = line.find(';');
		balance = stod(line.substr(0, comma));
		line.erase(0, comma + 1);

		Account account(person, accountNumber, balance);
		accounts.push_back(account);

		/*cout << "Name: " << name << endl;
		cout << "Username: " << username << endl;
		cout << "Address: " << address << endl;
		cout << "Password: " << password << endl;
		cout << "Age: " << age << endl;
		cout << "Account Number: " << accountNumber << endl;
		cout << "Balance: " << balance << endl;
		cout << endl;*/
	}
}

void Database::save()
{
	for (int i = 0; i < accounts.size(); i++)
	{
		outputFile << accounts[i].getOwner().getName() << ";"
			<< accounts[i].getOwner().getUsername() << ";"
			<< accounts[i].getOwner().getAddress() << ";"
			<< pasEncrypt(accounts[i].getOwner().getPassword()) << ";"
			<< accounts[i].getOwner().getAge() << ";"
			<< accounts[i].getAccountNumber() << ";"
			<< accounts[i].getBalance() << endl;
	}
}

vector<Account> Database::getAccounts() const
{
	return this->accounts;
}

//Database::Database()
//{
//	this->inputFile.open("data.txt");
//	this->outputFile.open("data.txt");
//}
//
//Database::~Database()
//{
//	this->inputFile.close();
//	this->outputFile.close();
//}
//
//void Database::addEntry()
//{
//	string name = "medhat";
//	int age = 69;
//	int cardNumber = 38424;
//
//	//accounts.push_back();
//
//	outputFile << name << "," << age << "," << cardNumber << endl;
//}
//
//void Database::deleteEntry()
//{
//
//}
//
//void Database::load()
//{
//
//}

// 

//#include <iostream>
//#include <fstream>
//#include <string>
//
//using namespace std;
//
//long long generateAccountNumber();

//int main()
//{
//	while (true)
//	{
//		cout << generateAccountNumber() << endl;
//	}
//
//	/*string s = "kareem";
//	cout << (s.find(',') != string::npos ? "has comma" : "has no comma") << endl;*/
//}

//void addEntry()
//{
//	ofstream outputFile("test.txt", ios::app);
//
//	string name = "medhat";
//	int age = 69;
//	int cardNumber = 38424;
//
//	outputFile << name << "," << age << "," << cardNumber << endl;
//	outputFile.close();
//}
//
//void deleteEntry()
//{
//
//}
//
//void load()
//{
//	ifstream inputFile("test.txt");
//
//	string line;
//
//	while (getline(inputFile, line))
//	{
//		if (line.empty())
//		{
//			continue;
//		}
//
//		string name;
//		int age;
//		int cardNumber;
//
//		cout << line << endl;
//
//		int comma = line.find(',');
//		name = line.substr(0, comma);
//		line.erase(0, comma + 1);
//
//		cout << line << endl;
//
//		comma = line.find(',');
//		age = stoi(line.substr(0, comma));
//		line.erase(0, comma + 1);
//
//		cout << line << endl << endl;
//
//		cardNumber = stoi(line.substr(0, line.length()));
//
//		cout << "Name: " << name << endl;
//		cout << "Age: " << age << endl;
//		cout << "Card Number: " << cardNumber << endl;
//		cout << endl;
//	}
//
//	inputFile.close();
//}

// YOUSEF'S CODE 

//bool Database::is16Digts(long long num1)
//{
//	long long div = num1 / 1000000000000000;
//	if (div < 0 || div == 0 || div >= 10)
//	{
//		return false;
//	}
//	return true;
//}
//
//void Database::addAccount()
//{
//	dataMgt.open("./data/accounts.txt", ios::app);
//	dataMgtc.open("./data/cardnumber.txt", ios::app);
//
//	int temp = 1;
//	long long waiting = 0;
//	string swaiting;
//	while (temp)
//	{
//		cout << "enter the number of the account\n";
//		cin >> waiting;
//		cout << "what is the name of the cardholder ?\n";
//		cin >> swaiting;
//		if (!(is16Digts(waiting)))
//		{
//			cout << "invaled number\n";
//			continue;
//		}
//
//		dataMgt << swaiting << "\n";
//		dataMgtc << waiting << "\n";
//
//		cout << "do you want any thing else sir?\n";
//		cout << "[1]\tyes\n";
//		cout << "[0]\tno\n";
//		cin >> temp;
//	}
//
//	dataMgt.close();
//	dataMgtc.close();
//}
//
//void Database::readAccount()
//{
//	dataMgt.open("./data/accounts.txt", ios::in);
//	dataMgtc.open("./data/cardnumber.txt", ios::in);
//	int chosen = 0;
//	// https://stackoverflow.com/questions/34181071/end-of-line-in-text-file-c
//	// stores
//	for (int i = 0; i < 20; i++)
//	{
//		getline(dataMgt, reader[i]);
//		getline(dataMgtc, readerc[i]);
//		//balance
//		//log
//	}
//	for (int i = 0; i < 20; i++)
//	{
//		cout << i + 1 << " : " << reader[i] << "\n";
//	}
//
//	cout << "choose\n";
//	cin >> chosen;
//	cout << "=============================================\n";
//	cout << "\t\t Name :\t" << reader[chosen - 1] << "\n";
//	cout << "\t\t Cardnumber :\t" << readerc[chosen - 1] << "\n";
//
//	dataMgt.close();
//	dataMgtc.close();
//}
