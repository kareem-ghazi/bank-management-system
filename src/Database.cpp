#include "Database.h"

// Initializes and reads data from the file.
Database::Database()
{
	this->inputFile.open("data/data.txt", ios::in);
	
	this->load();

	this->inputFile.close();
}

// Destroys and saves data to the file.
Database::~Database()
{
	this->outputFile.open("data/data.txt", ios::out);

	this->save();

	this->outputFile.close();
}

// Encrypts the passed string (usually a password).
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

// Decrypts the passed string (usually a password).
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

// Adds an account to the database.
void Database::addEntry(Account account)
{
	accounts.push_back(account);
}

// Deletes entry from the database.
void Database::deleteEntry(Account account)
{
	for (int i = 0; i < accounts.size(); i++)
	{
		
	}
}

// Reads and loads data from the file.
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
	}
}

// Saves data to the file text.
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

// Returns a vector of accounts.
vector<Account> Database::getAccounts() const
{
	return this->accounts;
}
