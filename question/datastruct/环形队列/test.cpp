#include<iostream>
using namespace std;
#include "MyQueue.h"

void main() {

	MyQueue *Queue = new MyQueue(4);

	Queue->push(10);
	Queue->push(20);
	Queue->push(40);
	Queue->push(50);
	Queue->push(60);

	if (Queue->isEmpty())
		cout << "Empty queue" << endl;
	else
		cout << "Not Empty" << endl;

	cout << "Length: " << Queue->size() << endl;

	Queue->traverse();

	int tmp;
	Queue->pop(tmp);
	Queue->pop(tmp);
	Queue->pop(tmp);
	Queue->pop(tmp);
	cout << "Length: " << Queue->size() << endl;
	Queue->traverse();
	/*
	Not Empty
	Length: 4
	------------开始遍历--------------
	10   前面还有0
	20   前面还有1
	40   前面还有2
	50   前面还有3

	Length: 0
	------------开始遍历--------------

	*/

	cin.get();
}