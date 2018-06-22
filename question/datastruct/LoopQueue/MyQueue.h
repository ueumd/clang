#ifndef MYQUEUE_H
#define MYQUEUE_H
/*
����
��ͨ���У������������һ�Ƕ�ͷ�뿪������ȫ��ǰ�ƣ����Ƕ�ͷ�뿪�����ƣ���������ţ������ֽ��������
���ζ��У����������Դ��Ҳ������Ч�ʣ���ͷ��β�ص�ֻ�����������ҪôΪ�գ�ҪôΪ����
*/
/*
	���ζ������
*/
class MyQueue
{
public:
	MyQueue(int queueCapacity);
	virtual ~MyQueue();
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
#endif
