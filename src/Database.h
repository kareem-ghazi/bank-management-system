#ifndef DATABASE_H
#define DATABASE_H

#include "Account.h"
#include "Person.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Database
{
private:
	vector<Account> accounts;
	vector<Person> people;

	ifstream inputFile;
	ofstream outputFile;

public:
	Database();
	~Database();

	string encrypt(string phrase);
	string decrypt(string phrase);

	void addEntry(Account account);
	void addEntry(Person person);
	void deleteEntry(Account account);
	void load();
	void save();

	vector<Account> getAccounts() const;
	Account* getAccount(long long accountNumber);
	vector<Person> getPeople() const;
};

#endif

