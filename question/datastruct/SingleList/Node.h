#ifndef NODE_H
#define NODE_H
#include<iostream>
class Node {

public:
	int data;
	Node * next;
public:
	void printNode() {
		std::cout << data << std::endl;
	};
};

#endif