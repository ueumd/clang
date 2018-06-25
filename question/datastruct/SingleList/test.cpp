#include<iostream>
#include "List.h"
#include "Node.h"

void main() {
	Node node1;
	node1.data = 1;

	Node node2;
	node2.data = 2;

	Node node3;
	node3.data = 3;

	Node node4;
	node4.data = 4;


	Node node5;
	node5.data = 5;

	List *p = new List();

	p->insertTail(&node1);
	p->insertTail(&node2);
	p->insertTail(&node3);
	p->insertTail(&node4);

	p->insertHead(&node5);

	p->traverse(); // 4 3 2 1

	delete p;
	p = NULL;

	std::cin.get();
}