#if 0
��������ȱ��
�ŵ㣺
1�����εķֵ���ÿ����ֻ��Ҫ�����Լ��ô���Ĺ��������ô���Ĵ��ݸ���һ��������ɣ�����ȷ��������η�Χ�����������С��װԭ��
2�����Ը�����Ҫ������Ϲ������̡��繤�����̷����仯������ͨ�����·�������������Ӧ�µĹ������̡�
3��������֮�����������ϵ���ʽ������֯��
ȱ�㣺
��Ϊ����ʱ��������ʽ�ڶ���䴫����Ϣ������ʵ�ַ�ʽ��ͬ���п��ܻ�Ӱ�촦����ٶȡ�
�����ڣ�
����ʽ�������顣�������̻�����Ϣ�������̻����������̻���

#endif

#include<iostream>
using namespace std;
class CarHandle {
public:
	virtual void HandleCar() = 0;

public:
	/*
	������ģʽ �������꣬������ȥ
	*/
	CarHandle *setNextHandle(CarHandle *carhandle){
		this->carhandle = carhandle;
		return this->carhandle;
	}

protected:
	CarHandle *carhandle;
};

class CarHandleHead :public CarHandle {
public:
	virtual void HandleCar() {
		cout << "����ͷ" << endl;

		//�� �공ͷ�� ������ ���ݽ��� ��һ��������
		if (this->carhandle != NULL) {
			carhandle->HandleCar();
		}
	}
};

class CarHandleBody:public CarHandle {
public:
	virtual void HandleCar() {
		cout << "������" << endl;

		if (this->carhandle != NULL) {
			carhandle->HandleCar();
		}
	}
};

class CarHandleTail :public CarHandle {
public:
	virtual void HandleCar() {
		cout << "����β" << endl;

		if (this->carhandle != NULL) {
			carhandle->HandleCar();
		}
	}
};

void main() {
#if 0
	CarHandleHead *head = new CarHandleHead;
	CarHandleBody *body = new CarHandleBody;
	CarHandleTail *tail = new CarHandleTail;

	//ҵ���߼� д���ڿͻ��� ����������
	head->HandleCar();
	body->HandleCar();
	tail->HandleCar();
#endif

	CarHandleHead *head = new CarHandleHead;
	CarHandleBody *body = new CarHandleBody;
	CarHandleTail *tail = new CarHandleTail;

	head->setNextHandle(body);
	body->setNextHandle(tail);
	tail->setNextHandle(NULL);

	//����
	head->HandleCar();
	/*
	����ͷ
  ������
  ����β
	*/

	cin.get();
}