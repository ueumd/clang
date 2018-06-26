#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;
class Node {
public:
	Node();
	Node *SearchNode(int index);
	void DeleteNode();
	void PreorderTraversal();
	void InorderTraversal();
	void PostorderTraversal();
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

Node *Node::SearchNode(int index) {
	if (this->index == index) {
		return this;
	}
	if (this->pLChild != NULL && this->pLChild->index==index) {
		return this->pLChild;
	}
	if (this->pRChild != NULL && this->pRChild->index == index) {
		return this->pRChild;
	}
	return NULL;
}


void Node::DeleteNode() {
	if (this->pLChild != NULL) {
		this->pLChild->DeleteNode();
	}

	if (this->pRChild != NULL) {
		this->pRChild->DeleteNode();
	}

	if (this->pParent != NULL) {
		if (this->pParent->pLChild == this) {
			this->pParent->pLChild = NULL;
		}

		if (this->pParent->pRChild == this) {
			this->pParent->pRChild = NULL;
		}
	}

	delete this;
}

//Ç°Ðò
void Node::PreorderTraversal() {
	cout <<this->index << " : " << this->data << endl;
	if (this -> pLChild != NULL) {
		this->pLChild->PreorderTraversal();
	}
	if (this->pRChild != NULL) {
		this->pRChild->PreorderTraversal();
	}
}

//ÖÐÐò
void Node::InorderTraversal() {
	
	if (this->pLChild != NULL) {
		this->pLChild->InorderTraversal();
	}

	cout << this->index << " : " << this->data << endl;

	if (this->pRChild != NULL) {
		this->pRChild->InorderTraversal();
	}
}

//ºóÐò
void Node::PostorderTraversal() {

	if (this->pLChild != NULL) {
		this->pLChild->PostorderTraversal();
	}

	if (this->pRChild != NULL) {
		this->pRChild->PostorderTraversal();
	}

	cout << this->index << " : " << this->data << endl;
}

#endif