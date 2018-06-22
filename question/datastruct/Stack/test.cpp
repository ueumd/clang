#include<iostream>
#include<string>
#include "Statck.h"
using namespace std;

void testStatck() {
	Statck<int> *s = new Statck<int>(3);
	s->push(10);
	s->push(20);
	s->push(30);

	cout << s->length() << endl;
	s->traverse(true);
}

void testStatckString() {
	Statck<string> s(3);
	s.push("Hello");
	s.push("World");

	cout << s.length() << endl;
	s.traverse(true);
}

void main() {
	// testStatck();
	testStatckString();
	cin.get();
}