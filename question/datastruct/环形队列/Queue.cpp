#include "Queue.h"
template<typename T>
Queue<T>::Queue(int capacity =0)
{
	m_iCapacity = capacity;
	m_iHead = 0;
	m_iTail = 0;
	m_iSize = 0;
	m_pQueue = new T[m_iCapacity];

	clear();
}

template<typename T>
Queue<T>::~Queue()
{
	delete[]m_pQueue;
	m_pQueue = NULL;
}

template<typename T>
void Queue<T>::clear() {
	m_iHead = 0;
	m_iTail = 0;
	m_iSize = 0;
}

template<typename T>
