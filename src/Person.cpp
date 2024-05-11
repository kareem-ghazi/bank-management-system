#include "Person.h"

Person::Person()
{

}

Person::Person(string name, string username, string address, string password, int age)
{
	this->name = name;
	this->username = username;
	this->address = address;
	this->password = password;
	this->age = age;
}

string Person::getName() const
{
	return this->name;
}

void Person::setName(string name)
{
	this->name = name;
}

string Person::getUsername() const
{
	return this->username;
}

void Person::setUsername(string username)
{
	this->username = username;
}

string Person::getAddress() const
{
	return this->address;
}

void Person::setAddress(string address)
{
	this->address = address;
}

string Person::getPassword() const
{
	return this->password;
}

int Person::getAge() const
{
	return this->age;
}

void Person::setAge(int age)
{
	if (age >= 18)
	{
		this->age = age;
	}
	else {
		cout << "Error: Invalid age. Must be 18 at least to be registered in the bank." << endl;
		assert(false);
	}
}

void Person::printInfo() const
{
	cout << "Name: " << name << endl;
	cout << "Address: " << address << endl;
	cout << "Age: " << age << endl;
}


