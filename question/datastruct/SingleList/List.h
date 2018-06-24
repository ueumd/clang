#ifndef LIST_H
#define LIST_H

#include<iostream>
#include "Node.h"
/*
���Ա� -- ��������
*/

class List {
public:
	List();
	~List();

	void clear();
	bool isEmpty();
	int getLength();

	bool getElem(int i, Node *node);										//��ȡָ��λ�õ�Ԫ�� 
	int locateElem(Node *node);													//����ָ��Ԫ�ص��±�
	bool priorElem(Node *currentNode, Node *preNode);	//��ȡָ��Ԫ�ص�ǰ��
	bool nextElem(Node *currentNode, Node *preNode);
	bool insert(int i, Node *node);
	bool insertHead(Node *node);		//ͷ�巨
	bool insertTail(Node *node);		//β�巨
	bool remove(int i, Node *node);
	void traverse();

private:
	int m_iLength;								//����Ԫ�صĸ���
	Node *m_pList;
};

List::List() {
	// ��һ���ڵ�[0, NULL]
	m_pList = new Node;
	m_pList->data = 0;
	m_pList->next = NULL;
	m_iLength = 0;
}

List::~List() {
	this->clear();
}

void List::clear() {
	//���˵�����  ����  ���˵�����
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

	//ͷ�ڵ�
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
	//ͷ�ڵ�
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

bool List::priorElem(int *currentElem, int *preElem) {
	int temp = locateElem(currentElem);
	if (temp == -1 || temp == 0) return false; //��һ��Ԫ����û��ǰ����

	*preElem = m_pList[temp - 1];
	return true;
}


bool List::nextElem(int *currentElem, int *preElem) {
	int temp = locateElem(currentElem);
	if (temp == -1 || temp == m_iLength) return false; // ���һ��

	*preElem = m_pList[temp - 1];
	return true;
}

void List::traverse() {
	for (int i = 0; i < m_iLength; i++) {
		std::cout << m_pList[i] << " ";
	}
	std::cout << std::endl;
}


bool List::insert(int i, Node *node) {

	if (i < 0 || i > m_iLength) return false;

	
	Node *currentNode = m_pList; //ͷ�ڵ�

	for (int k = 0; k < i; k++) {
		currentNode = currentNode->next;
	}

	//�Ӷ��з����ڴ�
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

bool List::insertHead(Node *node) {
	Node *temp = m_pList->next;

	//�Ӷ��з����ڴ�
	Node *newNode = new Node;
	if (newNode == NULL) {
		return false;
	}

	newNode->data = node->data;
	m_pList->next = newNode;
	newNode->next = temp;
	m_iLength++;
	return true;
}

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

	//ͷ�ڵ�
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