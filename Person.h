#ifndef PERSON_H
#define PERSON_H

#include "Account.h"
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Person { // HAS BEEN EDITTED (BOTH .H & .CPP)
private:
	//Account accounts[3];
	string name;
	string address;
	int age;

public:
	Person();
	Person(string name, string address, int age);
	
	string getName() const;
	void setName(string name);
	string getAddress() const;
	void setAddress(string address);
	int getAge() const;
	void setAge(int age);

	void printInfo() const;
};

#endif