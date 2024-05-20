#include "Person.h"

// Empty constructor.
Person::Person()
{

}

// Initializes a person with a name, username, address, password, and age.
Person::Person(string name, string username, string address, string password, int age)
{
	this->name = name;
	this->username = username;
	this->address = address;
	this->password = password;
	this->age = age;
}

// Returns the name of the person.
string Person::getName() const
{
	return this->name;
}

// Sets the name of the person.
void Person::setName(string name)
{
	this->name = name;
}

// Returns the username of the person.
string Person::getUsername() const
{
	return this->username;
}

// Sets the username of the person.
void Person::setUsername(string username)
{
	this->username = username;
}

// Returns the address of the person.
string Person::getAddress() const
{
	return this->address;
}

// Sets the address of the person.
void Person::setAddress(string address)
{
	this->address = address;
}

// Returns the password of the person.
string Person::getPassword() const
{
	return this->password;
}

// Returns the age of the person.
int Person::getAge() const
{
	return this->age;
}

// Sets the age of the person (must be above 18).
void Person::setAge(int age)
{
	if (age >= 18)
	{
		this->age = age;
	}
	else {
		cout << "[!] Error: Invalid age. Must be 18 at least to be registered in the bank." << endl;
	}
}


