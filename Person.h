#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person {
private:
	string name;
	string address;
	int id;
	int age;
	long long accountNumber;

public:
	Person(string name, int id, string address, int age, long long accountNumber);

	void printInfo() const;
};

#endif