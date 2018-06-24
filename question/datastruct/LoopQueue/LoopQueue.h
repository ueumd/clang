# ifndef LOOP_QUEUE_HPP
# define LOPP_QUEUE_HPP
/*
模版-环形队列
一开始没放在一个文件里，总是报错，蛋疼！！！

"《C++编程思想》第15章(第300页)：
模板定义很特殊。由template<…> 处理的任何东西都意味着编译器在当时不为它分配存储空间，它一直处于等待状态直到被一个模板实例告知。
在编译器和连接器的某一处，有一机制能去掉指定模板的多重定义。
所以为了容易使用，几乎总是在头文件中放置全部的模板声明和定义。"[2]

*/
template <class T> 
class LoopQueue {
public:
	LoopQueue(int c);
	~LoopQueue();
	void clear();										//清空队列
	bool isEmpty();
	bool isFull();
	int  size();
	bool push(T element);						//添加元素
	bool pop(T &element);						//删除元素
	void traverse();								//遍历
	void print();										//遍历

private:
	T *m_pQueue;									//队列数组指针
	int m_iSize;								    //队列元素个数	
	int m_iCapacity;								//队列数组容量
	int m_iHead;										//队头
	int m_iTail;										//队尾
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
		cout << "前面还有" << i - m_iHead << "人在排队\t";
		m_pQueue[i % m_iCapacity].printInfo();
	}
	cout << endl;
}



#endif