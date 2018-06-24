# ifndef LOOP_QUEUE_HPP
# define LOPP_QUEUE_HPP
/*
ģ��-���ζ���
һ��ʼû����һ���ļ�����Ǳ������ۣ�����

"��C++���˼�롷��15��(��300ҳ)��
ģ�嶨������⡣��template<��> ������κζ�������ζ�ű������ڵ�ʱ��Ϊ������洢�ռ䣬��һֱ���ڵȴ�״ֱ̬����һ��ģ��ʵ����֪��
�ڱ���������������ĳһ������һ������ȥ��ָ��ģ��Ķ��ض��塣
����Ϊ������ʹ�ã�����������ͷ�ļ��з���ȫ����ģ�������Ͷ��塣"[2]

*/
template <class T> 
class LoopQueue {
public:
	LoopQueue(int c);
	~LoopQueue();
	void clear();										//��ն���
	bool isEmpty();
	bool isFull();
	int  size();
	bool push(T element);						//���Ԫ��
	bool pop(T &element);						//ɾ��Ԫ��
	void traverse();								//����
	void print();										//����

private:
	T *m_pQueue;									//��������ָ��
	int m_iSize;								    //����Ԫ�ظ���	
	int m_iCapacity;								//������������
	int m_iHead;										//��ͷ
	int m_iTail;										//��β
};


template <class T> 
LoopQueue<T>::LoopQueue(int c):m_iCapacity(c), m_iHead(0), m_iTail(0), m_iSize(0), m_pQueue(nullptr)
{
	m_pQueue = new T[m_iCapacity];
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

template <class T> bool LoopQueue<T>::isEmpty() {
	if (m_iSize == 0) {
		return true;
	}
	return false;
}

template <class T> bool LoopQueue<T>::isFull() {
	if (m_iSize == m_iCapacity) {
		return true;
	}

	return false;
}

template <class T> int  LoopQueue<T>::size() {
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

template <class T> void LoopQueue<T>::print() {
	for (int i = m_iHead; i < m_iSize + m_iHead; i++) {
		cout << "ǰ�滹��" << i - m_iHead << "�����Ŷ�\t";
		m_pQueue[i % m_iCapacity].printInfo();
	}
	cout << endl;
}



#endif