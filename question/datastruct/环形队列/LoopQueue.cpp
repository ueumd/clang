#include "LoopQueue.h"
#include <iostream>
using namespace std;

template <class T> LoopQueue<T>::LoopQueue(int capacity)
{
	m_iCapacity = capacity;
	m_iHead = 0;
	m_iTail = 0;
	m_iSize = 0;
	m_pQueue = new T[m_iCapacity];

	clear();
}

template <class T> LoopQueue<T>::~LoopQueue()
{
	delete[] m_pQueue;
	m_pQueue = NULL;
}

template <class T> void LoopQueue<T>::clear() {
	m_iHead = 0;
	m_iTail = 0;
	m_iSize = 0;
}

template <class T> bool LoopQueue<T>::isEmpty() const {
	if (m_iSize == 0) {
		return true;
	}
	return false;
}

template <class T> bool LoopQueue<T>::isFull() const {
	if (m_iSize == m_iCapacity) {
		return true;
	}

	return false;
}

template <class T> int  LoopQueue<T>::size() const {
	return m_iSize;
}

template <class T> bool LoopQueue<T>::push(T element) {
	if (isFull()) {
		return false;
	}
	m_pQueue[m_iTail] = element;
	m_iTail++;
	m_iSize++;
	m_iTail = m_iTail % m_iCapacity;
	return true;
}

template <class T> bool LoopQueue<T>::pop(T &element) {
	if (isEmpty()) {
		return false;
	}
	m_pQueue[m_iHead] = element;
	m_iHead++;
	m_iSize--;
	m_iHead = m_iHead % m_iCapacity;
	return true;
}

template <class T> void LoopQueue<T>::traverse() {
	for (int i = m_iHead; i < m_iSize + m_iHead; i++) {
		cout << m_pQueue[i % m_iCapacity] << "  ";
	}
	cout << endl;
}