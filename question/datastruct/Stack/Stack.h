#ifndef STACK_H
#define STACK_H
/*
ջ�Ͷ��е�����
ջ    ֻ���� ջ�� ������ �� ɾ�� ������						   (����ȳ�)
����  ֻ���� ��ͷ ��ɾ�� ����, �� ��β �� ���� ����. (�Ƚ��ȳ�)

*/
/*
�Ƚ���� first in last out
ջҪ�أ�ջ�� ջ�� �������ӵ��ӣ�
ջ ������ ��
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
	bool push(T elem);		//��ջ ջ������
	bool pop(T &elem);		//��ջ ջ���½�
	void traverse(bool isFromBottom);
	void print(bool isFromBottom);

private:
	T *m_pBuffer;			//ջ�ռ�ָ��
	int m_iSize;			//ջ����
	int m_iTop;				//ջ����ջ��Ԫ�صĸ���
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
		//ջ�� ���ϱ���
		for (int i = 0; i < m_iTop; i++)
		{
			cout << m_pBuffer[i] << "\t";
			//m_pBuffer[i].printCoordinate();
		}
	}
	else
	{
		//ջ�� ���±���
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
		//ջ�� ���±���
		for (int i = 0; i < m_iTop; i++)
		{
			m_pBuffer[i].print();
		}
	}
	else
	{
		//ջ�� ���±���
		for (int i = m_iTop - 1; i >= 0; i--)
		{
			m_pBuffer[i].print();
		}
	}
}

#endif