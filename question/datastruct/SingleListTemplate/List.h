#ifndef LIST_H
#define LIST_H

#include<iostream>
#include "Node.h"

/*
线性表 -- 单向链表
*/
template <typename T>
class List {
public:
	List();
	~List();

	void clear();
	bool isEmpty();
	int getLength();

	bool getElem(int i, Node<T> *node);										//获取指定位置的元素 
	int locateElem(Node<T> *node);													//查找指定元素的下标
	bool priorElem(Node<T> *currentNode, Node<T> *preNode);	//获取指定元素的前驱
	bool nextElem(Node<T> *currentNode, Node<T> *preNode);
	bool insert(int i, Node<T> *node);
	bool insertHead(Node<T> *node);		//头插
	bool insertTail(Node<T> *node);		//尾插
	bool remove(int i, Node<T> *node);
	void traverse();

private:
	int m_iLength;								 //已有元素的个数
	Node<T> *m_pList;
};

template <typename T>
List<T>::List() {
	m_iLength = 0;

	// 创建头指针 [0, NULL]
	m_pList = new Node<T>;

	//m_pList->data = 0;
	m_pList->next = NULL;
}

template <typename T>
List<T>::~List() {
	this->clear();
}

template <typename T>
void List<T>::clear() {
	//敌人的上线  敌人  敌人的下线
	Node<T> *currentNode = m_pList->next;
	while (currentNode != NULL) {
		Node<T> *temp = currentNode->next;
		delete currentNode;
		currentNode = temp;
	}
	m_pList->next = NULL;
}

template <typename T>
bool List<T>::isEmpty() {
	return m_iLength == 0 ? true : false;
}

template <typename T>
int List<T>::getLength() {
	return m_iLength;
}

template <typename T>
bool List<T>::getElem(int i, Node<T> *node) {
	if (i < 0 || i >= m_iLength) {
		return false;
	}

	//头节点
	Node<T> *currentNode = m_pList;

	Node<T> *currentNodeBefor = NULL;

	for (int k = 0; k < i; k++) {
		currentNodeBefor = currentNode;
		currentNode= currentNode->next;
	}

	node->data = currentNode->data;

	return true;
}

template <typename T>
int List<T>::locateElem(Node<T> *node) {
	Node<T> *currentNode = m_pList;

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

template <typename T>
bool List<T>::priorElem(Node<T> *pCurrentNode, Node<T> *pPreNode) {
	Node<T> *currentNode = m_pList;
	Node<T> *tempNode<T> = NULL;

	while (currentNode->next != NULL) {
		tempNode<T> = currentNode;
		currentNode = currentNode->next;
		if (currentNode->data == pCurrentNode->data) {
			if (tempNode<T> == m_pList) {
				return false;
			}
			pPreNode->data = tempNode<T>->data;
			return true;
		}
	}
	return false;
}

template <typename T>
bool List<T>::nextElem(Node<T> *pCurrentNode, Node<T> *pNextNode) {
	Node<T> *currentNode = m_pList;

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

template <typename T>
void List<T>::traverse() {
	Node<T> *currentNode = m_pList;

	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
		currentNode->printNode();
	}
}

template <typename T>
bool List<T>::insert(int i, Node<T> *node) {

	if (i < 0 || i > m_iLength) return false;

	Node<T> *currentNode = m_pList;

	for (int k = 0; k < i; k++) {
		currentNode = currentNode->next;
	}

	//从堆中分配内存
	Node<T> *newNode = new Node<T>;
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
template <typename T>
bool List<T>::insertHead(Node<T> *node) {
	Node<T> *temp = m_pList->next;

	//从堆中分配内存
	Node<T> *newNode = new Node<T>;
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
template <typename T>
bool List<T>::insertTail(Node<T> *node) {
	Node<T> *currentNode = m_pList;
	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
	}

	Node<T> *newNode = new Node<T>;
	if (newNode == NULL) {
		return false;
	}
	newNode->data = node->data;
	newNode->next = NULL;

	currentNode->next = newNode;

	m_iLength++;
	return true;
}

template <typename T>
bool List<T>::remove(int i, Node<T> *node) {

	if (i < 0 || i >= m_iLength) return false;

	//头节点
	Node<T> *currentNode = m_pList;
	Node<T> *currentNodeBefor = NULL;

	for (int k = 0; k <= i; k++) {
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