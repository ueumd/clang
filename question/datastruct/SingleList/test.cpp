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

	List *p = new List();

	p->insertHead(&node1);
	p->insertHead(&node2);
	p->insertHead(&node3);
	p->insertHead(&node4);

	p->traverse(); // 4 3 2 1

	delete p;
	p = NULL;

	std::cin.get();
}