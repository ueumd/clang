#ifndef LIST_H
#define LIST_H

#include<iostream>
#include "Node.h"

/*
线性表 -- 单向链表
*/

class List {
public:
	List();
	~List();

	void clear();
	bool isEmpty();
	int getLength();

	bool getElem(int i, Node *node);										//获取指定位置的元素 
	int locateElem(Node *node);													//查找指定元素的下标
	bool priorElem(Node *currentNode, Node *preNode);	//获取指定元素的前驱
	bool nextElem(Node *currentNode, Node *preNode);
	bool insert(int i, Node *node);
	bool insertHead(Node *node);		//头插
	bool insertTail(Node *node);		//尾插
	bool remove(int i, Node *node);
	void traverse();

private:
	int m_iLength;								 //已有元素的个数
	Node *m_pList;
};

List::List() {
	m_iLength = 0;

	// 创建头指针 [0, NULL]
	m_pList = new Node;

	m_pList->data = 0;
	m_pList->next = NULL;
}

List::~List() {
	this->clear();
}

void List::clear() {
	//敌人的上线  敌人  敌人的下线
	Node *currentNode = m_pList->next;
	while (currentNode != NULL) {
		Node *temp = currentNode->next;
		delete currentNode;
		currentNode = temp;
	}
	m_pList->next = NULL;
}

bool List::isEmpty() {
	return m_iLength == 0 ? true : false;
}

int List::getLength() {
	return m_iLength;
}

bool List::getElem(int i, Node *node) {
	if (i < 0 || i >= m_iLength) {
		return false;
	}

	//头节点
	Node *currentNode = m_pList;

	Node *currentNodeBefor = NULL;

	for (int k = 0; k < i; k++) {
		currentNodeBefor = currentNode;
		currentNode = currentNode->next;
	}

	node->data = currentNode->data;

	return true;
}

int List::locateElem(Node *node) {
	Node *currentNode = m_pList;

	int count = 0;
	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
		if (currentNode->data == node->data) {
			return count;
		}
		count++;
	}
	
	return -1;
}

bool List::priorElem(Node *pCurrentNode, Node *pPreNode) {
	Node *currentNode = m_pList;
	Node *tempNode = NULL;

	while (currentNode->next != NULL) {
		tempNode = currentNode;
		currentNode = currentNode->next;
		if (currentNode->data == pCurrentNode->data) {
			if (tempNode == m_pList) {
				return false;
			}
			pPreNode->data = tempNode->data;
			return true;
		}
	}
	return false;
}

bool List::nextElem(Node *pCurrentNode, Node *pNextNode) {
	Node *currentNode = m_pList;

	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
		if (currentNode->data == pCurrentNode->data) {
			if (currentNode->next == NULL) {
				return false;
			}
			pNextNode->data = currentNode->next->data;
			return true;
		}
	}
	return false;
}

void List::traverse() {
	Node *currentNode = m_pList;

	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
		currentNode->printNode();
	}
}

bool List::insert(int i, Node *node) {

	if (i < 0 || i > m_iLength) return false;

	Node *currentNode = m_pList;

	for (int k = 0; k < i; k++) {
		currentNode = currentNode->next;
	}

	//从堆中分配内存
	Node *newNode = new Node;
	if (newNode == NULL) {
		return false;
	}

	newNode->data = node->data;
	newNode->next = currentNode->next;
	currentNode->next = newNode;

	m_iLength++;
	return true;
}

/*
头插法
[0,n]      [3,n] [2,n] [1,n]
     [4,n]
*/
bool List::insertHead(Node *node) {
	Node *temp = m_pList->next;

	//从堆中分配内存
	Node *newNode = new Node;
	if (newNode == NULL) {
		return false;
	}

	newNode->data = node->data;
	newNode->next = temp;

	m_pList->next = newNode;

	m_iLength++;
	return true;
}

/*
尾插法
[0,n] [1,n] [2,n] [3,n] 
                        [4,n]
*/
bool List::insertTail(Node *node) {
	Node *currentNode = m_pList;
	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
	}

	Node *newNode = new Node;
	if (newNode == NULL) {
		return false;
	}
	newNode->data = node->data;
	newNode->next = NULL;

	currentNode->next = newNode;

	m_iLength++;
	return true;
}

bool List::remove(int i, Node *node) {

	if (i < 0 || i >= m_iLength) return false;

	//头节点
	Node *currentNode = m_pList;
	Node *currentNodeBefor = NULL;

	for (int k = 0; k < i; k++) {
		currentNodeBefor = currentNode;
		currentNode = currentNode -> next;
	}

	currentNodeBefor->next = currentNode->next;
	node->data = currentNode->data;

	delete currentNode;
	currentNode = NULL;
	m_iLength--;

	return true;
}
#endif