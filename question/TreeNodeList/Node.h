#ifndef NODE_H
#define NODE_H
class Node {
public:
	Node();
public:
	int index;
	int data;
	Node *pLChild;
	Node *pRChild;
	Node *pParent;
};

Node::Node() {
	index = 0;
	data = 0;
	pLChild = 0;
	pRChild = 0;
	pParent = 0;
}
#endif