#include<iostream>
using namespace std;
/*
Proxyģʽ�ֽ�������ģʽ���ǹ����͵����ģʽ֮һ��������Ϊ���������ṩһ�ִ���Proxy���Կ��ƶ��������ķ��ʡ�
��ν������ָ���������Ԫ��������Ķ��󣩾�����ͬ�Ľӿڵ��࣬�ͻ��˱���ͨ�������뱻�����Ŀ���ཻ����������һ���ڽ����Ĺ����У�����ǰ�󣩣�����ĳЩ�ر�Ĵ���

��ʾ��a�а���b�ࣻa��b��ʵ��Э����protocol
*/

//Э����
class Subject {
public:
	virtual void sailbook() = 0;
};

//b��
class RealSubjectBook :public Subject {
public:
	virtual void sailbook() {
		cout << "sail book" << endl;
	}
};

//a��
class TaobaoProxy:public Subject {
public:
	virtual void sailbook() {
		m_realSubjectBook = new RealSubjectBook();
		dazhe();
		m_realSubjectBook->sailbook();
		delete m_realSubjectBook;
	}

	void dazhe() {
		cout << "˫ʮһ����" << endl;
	}

private:
	RealSubjectBook *m_realSubjectBook;
};

void main() {
	//ֱ������
	Subject *s = new RealSubjectBook;
	s->sailbook();

	//Taobao�������� 
	s = new TaobaoProxy;
	s->sailbook();

	delete s;

	cin.get();
}