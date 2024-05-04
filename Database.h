#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Database
{
private:
	fstream dataMgt;
	fstream dataMgtc;
	string reader[20];
	string readerc[20]; //int

public:
	bool is16Digts(long long num1);
	void addAccount();
	void readAccount();
	void print(int ch);
};

#endif

