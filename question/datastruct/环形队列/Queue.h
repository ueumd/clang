#ifndef QUEUE
#define QUEUE
#endif // !QUEUE

/*
���ζ������
*/
template<typename T>
class Queue
{
public:
	Queue(int queueCapacity);
	virtual ~Queue();
	void clear();							//��ն���
	bool isEmpty() const;
	bool isFull() const;
	int  size() const;
	bool push(int element);			//���Ԫ��
	bool pop(int &element);			//ɾ��Ԫ��
	void traverse();						//����

private:
	int *m_pQueue;									//��������ָ��
	int m_iSize;								//����Ԫ�ظ���	
	int m_iCapacity;						//������������
	int m_iHead;										//��ͷ
	int m_iTail;										//��β
};

