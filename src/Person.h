#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person {
private:
	string name;
	string username;
	string address;
	string password;
	int age;

public:
	Person();
	Person(string name, string username, string address, string password, int age);
	
	string getName() const;
	void setName(string name);
	string getUsername() const;
	void setUsername(string username);
	string getAddress() const;
	void setAddress(string address);
	string getPassword() const;
	int getAge() const;
	void setAge(int age);
};

#endif