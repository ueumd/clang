#ifndef LOOPQUEUE
#define LOOPQUEUE
#endif // !QUEUE

/*
���ζ������
*/
template <class T> class LoopQueue {
public:
	LoopQueue(int capacity);
	virtual ~LoopQueue();
	void clear();							//��ն���
	bool isEmpty() const;
	bool isFull() const;
	int  size() const;
	bool push(T element);			//���Ԫ��
	bool pop(T &element);			//ɾ��Ԫ��
	void traverse();						//����

private:
	int *m_pQueue;									//��������ָ��
	int m_iSize;								//����Ԫ�ظ���	
	int m_iCapacity;						//������������
	int m_iHead;										//��ͷ
	int m_iTail;										//��β
};

