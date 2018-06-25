#ifndef NODE_H
#define NODE_H
#include<iostream>

template <typename T>
class Node {
public:
	T data;
	Node * next;
public:
	void printNode() {
		std::cout << data << std::endl;
	};
};

#endif