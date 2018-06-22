#include<iostream>
#include<string>
#include "MyQueue.h"
#include "LoopQueue.h"
#include "Customer.h"
using namespace std;

void testMyQueue() {

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
}

void testQueue() {
	LoopQueue<int> *q = new LoopQueue<int>(4);
	q->push(10);
	q->push(20);
	q->push(30);
	q->push(40);
	q->push(50);
	cout << "Size: " << q->size() << endl;

	q->traverse();
}


void testQueue2() {
	LoopQueue<string> queue(5);

	queue.push("one");
	queue.push("two");
	queue.push("three");
	queue.push("four");
	queue.push("five");
	cout << "Size: " << queue.size() << endl;

	queue.traverse();
	/*
	Length: 5
	one  two  three  four  five
	*/
}

void testQueueCustomer() {
	LoopQueue<Customer> *q = new LoopQueue<Customer>(4);
	Customer c1("zhangsan", 20);
	Customer c2("lisi", 30);
	Customer c3("wangwu", 24);

	q->push(c1);
	q->push(c2);
	q->push(c3);

	cout << "Size: " << q->size() << endl;

	q->print();

}

void main() {
	// testQueue2();

	testQueueCustomer();

	cin.get();
}