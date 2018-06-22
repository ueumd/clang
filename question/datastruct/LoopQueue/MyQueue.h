#ifndef MYQUEUE_H
#define MYQUEUE_H
/*
队列
普通队列：分两种情况，一是队头离开，后面全部前移；二是队头离开，不移，往后继续排，这两种结果都不好
环形队列：充分利用资源，也不牺牲效率；队头队尾重叠只有两种情况，要么为空，要么为满。
*/
/*
	环形队列设计
*/
class MyQueue
{
public:
	MyQueue(int queueCapacity);
	virtual ~MyQueue();
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
#endif
