#include<iostream>
#include "Tree.h"

using namespace std;

void main() {

	int root = 3;

	Tree *p = new Tree(10, &root);

	int node1 = 5;
	int node2 = 8;

	p->AddNode(0, 0, &node1);
	p->AddNode(0, 1, &node2);


	int node3 = 2;
	int node4 = 6;

	p->AddNode(1, 0, &node3);
	p->AddNode(1, 1, &node4);


	int node5 = 9;
	int node6 = 7;

	p->AddNode(2, 0, &node5);
	p->AddNode(2, 1, &node6);

	p->TreeTraversal();			//3  5  8  2  6  9  7  0  0  0

	int *node = p->SearchNode(2);
	cout << "*node: " << *node << endl;  // 8

	int temp = 0;
	p->DeleteNode(6, &temp);
	cout << "temp: " << temp << endl;  // 7

	p->TreeTraversal();			//3  5  8  2  6  9  0  0  0  0


	delete p;

	cin.get();
}