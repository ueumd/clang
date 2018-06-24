#ifndef STACK_H
#define STACK_H
/*
栈和队列的区别：
栈    只能在 栈顶 做插入 和 删除 操作。						   (后进先出)
队列  只能在 队头 做删除 操作, 在 队尾 做 插入 操作. (先进先出)

*/
/*
先进后出 first in last out
栈要素：栈顶 栈底 （如盘子叠加）
栈 不等于 堆
*/
template <typename T>
class Stack {
public:
	Stack(int size);
	~Stack();

	bool isEmpty();
	bool isFull();
	void clear();
	int  length();
	bool push(T elem);		//入栈 栈顶上升
	bool pop(T &elem);		//出栈 栈顶下降
	void traverse(bool isFromBottom);
	void print(bool isFromBottom);

private:
	T *m_pBuffer;			//栈空间指针
	int m_iSize;			//栈容量
	int m_iTop;				//栈顶，栈中元素的个数
};

template <typename T>
Stack<T>::Stack(int size)
{
	m_iSize = size;
	m_iTop = 0;
	m_pBuffer = new T[m_iSize];
};

template <typename T>
Stack<T>::~Stack() {
	delete[]m_pBuffer;
}

template <typename T>
bool Stack<T>::isEmpty() {
	if (m_iTop == 0) {
		return true;
	}
	return false;
}

template <typename T> bool Stack<T>::isFull() {
	if (m_iTop == m_iSize) {
		return true;
	}
	return false;
}

template <typename T>
void Stack<T>::clear() {
	m_iTop = 0;
}

template <typename T>
int Stack<T>::length() {
	return m_iTop;
}

template <typename T>
bool Stack<T>::push(T elem) {
	if (isFull()) {
		return false;
	}

	m_pBuffer[m_iTop] = elem;
	m_iTop++;
	return true;
}

template <typename T>
bool Stack<T>::pop(T &elem) {
	if (isEmpty()) {
		return false;
	}

	m_pBuffer[m_iTop] = elem;
	m_iTop--;
	return true;
}

template <typename T>
void Stack<T>::traverse(bool isFromBottom) {
	if (isFromBottom)
	{
		//栈底 往上遍历
		for (int i = 0; i < m_iTop; i++)
		{
			cout << m_pBuffer[i] << "\t";
			//m_pBuffer[i].printCoordinate();
		}
	}
	else
	{
		//栈顶 往下遍历
		for (int i = m_iTop - 1; i >= 0; i--)
		{
			cout << m_pBuffer[i] << "\t";
			//m_pBuffer[i].printCoordinate();
		}
	}
}

template <typename T>
void Stack<T>::print(bool isFromBottom) {
	if (isFromBottom)
	{
		//栈顶 往下遍历
		for (int i = 0; i < m_iTop; i++)
		{
			m_pBuffer[i].print();
		}
	}
	else
	{
		//栈顶 往下遍历
		for (int i = m_iTop - 1; i >= 0; i--)
		{
			m_pBuffer[i].print();
		}
	}
}

#endif