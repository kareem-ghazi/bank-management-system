#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Account.h"
#include "Person.h"

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

	void addEntry();
	void deleteEntry();
	void load();
};

#endif

