#ifndef STACK_H
#define STACK_H

template <typename T>
class Statck {
public:
	Statck(int size);
	~Statck();

	bool isEmpty();
	bool isFull();
	void clear();
	int  length();
	bool push(T elem);
	bool pop(T &elem);
	void traverse(bool isFromBottom);

private:
	T *m_pBuffer;	//栈空间指针
	int m_iSize;			//栈容量
	int m_iTop;				//栈顶，栈元素的个数
};

template <typename T>
Statck<T>::Statck(int size)
{
	m_iSize = size;
	m_iTop = 0;
	m_pBuffer = new T[m_iSize];
};

template <typename T>
Statck<T>::~Statck() {
	delete[]m_pBuffer;
}

template <typename T>
bool Statck<T>::isEmpty() {
	if (m_iTop == 0) {
		return true;
	}
	return false;
}

template <typename T>
bool Statck<T>::isFull() {
	if (m_iTop == m_iSize) {
		return true;
	}
	return false;
}

template <typename T>
void Statck<T>::clear() {
	m_iTop = 0;
}

template <typename T>
int Statck<T>::length() {
	return m_iTop;
}

template <typename T>
bool Statck<T>::push(T elem) {
	if (isFull()) {
		return false;
	}

	m_pBuffer[m_iTop] = elem;
	m_iTop++;
	return true;
}

template <typename T>
bool Statck<T>::pop(T &elem) {
	if (isEmpty()) {
		return false;
	}

	m_pBuffer[m_iTop] = elem;
	m_iTop--;
	return true;
}

template <typename T>
void Statck<T>::traverse(bool isFromBottom) {
	if (isFromBottom)
	{
		for (int i = 0; i < m_iTop; i++)
		{
			cout << m_pBuffer[i] << "\t";
			//m_pBuffer[i].printCoordinate();
		}
	}
	else
	{
		for (int i = m_iTop - 1; i >= 0; i--)
		{
			cout << m_pBuffer[i] << "\t";
			//m_pBuffer[i].printCoordinate();
		}
	}
}
#endif