#include "MyQueue.h"
#include <iostream>
using namespace std;

//初始化
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
队列满的情况下
队尾要置0 m_iTail = m_iTail % m_iQueueCapacity = 4 % 4=0 
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
队列空的情况下
队头要置0 m_iHead = m_iHead % m_iQueueCapacity = 4 % 4=0
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
遍历 要从 队头开始  m_iHead
*/
void MyQueue::traverse() {
	cout << "------------开始遍历--------------" << endl;
	for (int i = m_iHead; i < m_iSize+m_iHead; i++) {
		cout << m_pQueue[i%m_iCapacity] << "   ";

		cout << "前面还有" << i - m_iHead << endl; //删除元素的时候从第0个开始
	}
	cout << endl;
}