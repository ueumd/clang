#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include <string>
using namespace std;

class Person {
public:
	//���ظ�ֵ
	Person &operator=(Person &person);

	//���رȽ�
	bool operator==(Person &person);

	//�������
	friend ostream & operator <<(ostream &out, Person &person);

public:
	string name;
	string phone;

};


Person &Person::operator=(Person &person){
	this->name = person.name;
	this ->phone = person.phone;
	return *this;
}

bool Person::operator==(Person &person) {
	if (this->name == person.name && this->phone == person.phone) {
		return true;
	}
	return false;
}

ostream &operator<<(ostream &out, Person &person) {
	out << person.name << " ------------ " << person.phone;
	return out;
}


#endif

