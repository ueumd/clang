#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include <string>
using namespace std;

class Person {
public:
	Person &operator=(Person &person);
	bool operator==(Person &person);

	friend ostream &operator<<(stream &out, Person &person);
public:
	string name;
	string phone;

};


ostream &operator<<(stream &out, Person &person) {
	out << person.name << " ------------ " << person.phone;
	return out;
}

Person::Person &operator=(Person &person) {
	this->name = person.name;
	this ->phone = person.phone;
	return this;
}

bool Person::operator=(Perosn &person) {
	if (this->name == person.name && this->phone == person.phone) {
		return true;
	}
	return false;
}

#endif

