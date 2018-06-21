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
	------------��ʼ����--------------
	10   ǰ�滹��0
	20   ǰ�滹��1
	40   ǰ�滹��2
	50   ǰ�滹��3

	Length: 0
	------------��ʼ����--------------

	*/

	cin.get();
}