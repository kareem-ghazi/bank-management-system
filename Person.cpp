#include "Person.h"

Person::Person(string name, int id, string address, int age, long long accountNumber)
{
	this->name = name;
	this->id = id;
	this->address = address;
	this->age = age;
	this->accountNumber = accountNumber;
}

void Person::printInfo() const
{
	cout << "Name: " << name << endl;
	cout << "ID: " << id << endl;
	cout << "Address: " << address << endl;
	cout << "Age: " << age << endl;
	cout << "Account Number: " << accountNumber << endl;
}


