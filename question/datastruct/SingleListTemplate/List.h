#ifndef LIST_H
#define LIST_H

#include<iostream>
#include "Node.h"

/*
���Ա� -- ��������
*/
template <typename T>
class List {
public:
	List();
	~List();

	void clear();
	bool isEmpty();
	int getLength();

	bool getElem(int i, Node<T> *node);										//��ȡָ��λ�õ�Ԫ�� 
	int locateElem(Node<T> *node);													//����ָ��Ԫ�ص��±�
	bool priorElem(Node<T> *currentNode, Node<T> *preNode);	//��ȡָ��Ԫ�ص�ǰ��
	bool nextElem(Node<T> *currentNode, Node<T> *preNode);
	bool insert(int i, Node<T> *node);
	bool insertHead(Node<T> *node);		//ͷ��
	bool insertTail(Node<T> *node);		//β��
	bool remove(int i, Node<T> *node);
	void traverse();

private:
	int m_iLength;								 //����Ԫ�صĸ���
	Node<T> *m_pList;
};

template <typename T>
List<T>::List() {
	m_iLength = 0;

	// ����ͷָ�� [0, NULL]
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
	//���˵�����  ����  ���˵�����
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

	//ͷ�ڵ�
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

	//�Ӷ��з����ڴ�
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
ͷ�巨
[0,n]      [3,n] [2,n] [1,n]
     [4,n]
*/
template <typename T>
bool List<T>::insertHead(Node<T> *node) {
	Node<T> *temp = m_pList->next;

	//�Ӷ��з����ڴ�
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
β�巨
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

	//ͷ�ڵ�
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