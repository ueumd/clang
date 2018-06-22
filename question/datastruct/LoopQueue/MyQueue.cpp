#include "MyQueue.h"
#include <iostream>
using namespace std;

//��ʼ��
MyQueue::MyQueue(int quequeCapacity = 0) {
	m_iCapacity = quequeCapacity;
	m_iHead = 0;
	m_iTail = 0;
	m_iSize = 0;
	m_pQueue = new int[m_iCapacity];

	clear();
}

MyQueue::~MyQueue()
{
	delete[] m_pQueue;
	m_pQueue = NULL;
}

void MyQueue::clear() {
	m_iHead = 0;
	m_iTail = 0;
	m_iSize = 0;
}

bool MyQueue::isEmpty() const {
	if (m_iSize == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool MyQueue::isFull() const {
	if (m_iSize == m_iCapacity) {
		return true;
	}
	else {
		return false;
	}
}

int MyQueue::size() const {
	return m_iSize;
}

/*
�������������
��βҪ��0 m_iTail = m_iTail % m_iQueueCapacity = 4 % 4=0 
*/
bool MyQueue::push(int element) {
	if (isFull()) {
		return false;
	}
	else {
		m_pQueue[m_iTail] = element;
		m_iTail++;
		m_iSize++;
		m_iTail = m_iTail % m_iCapacity;
		return true;
	}
}

/*
���пյ������
��ͷҪ��0 m_iHead = m_iHead % m_iQueueCapacity = 4 % 4=0
*/
bool MyQueue::pop(int &element) {
	if (isEmpty()){
		return false;
	}
	element = m_pQueue[m_iHead];
	m_iHead++;
	m_iSize--;
	m_iHead = m_iHead % m_iCapacity;
	return true;
}

/*
���� Ҫ�� ��ͷ��ʼ  m_iHead
*/
void MyQueue::traverse() {
	cout << "------------��ʼ����--------------" << endl;
	for (int i = m_iHead; i < m_iSize+m_iHead; i++) {
		cout << m_pQueue[i%m_iCapacity] << "   ";

		cout << "ǰ�滹��" << i - m_iHead << endl; //ɾ��Ԫ�ص�ʱ��ӵ�0����ʼ
	}
	cout << endl;
}