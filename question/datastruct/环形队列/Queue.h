#ifndef QUEUE
#define QUEUE
#endif // !QUEUE

/*
环形队列设计
*/
template<typename T>
class Queue
{
public:
	Queue(int queueCapacity);
	virtual ~Queue();
	void clear();							//清空队列
	bool isEmpty() const;
	bool isFull() const;
	int  size() const;
	bool push(int element);			//添加元素
	bool pop(int &element);			//删除元素
	void traverse();						//遍历

private:
	int *m_pQueue;									//队列数组指针
	int m_iSize;								//队列元素个数	
	int m_iCapacity;						//队列数组容量
	int m_iHead;										//队头
	int m_iTail;										//队尾
};

