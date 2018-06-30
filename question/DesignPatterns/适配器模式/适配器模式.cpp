#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

/*
ͨ��Adapterģʽ���Ըı������ࣨ���ⲿ�ࣩ�Ľӿ���ʽ��

�����ڣ�

�ǽ�һ����Ľӿ�ת���ɿͻ�ϣ��������һ���ӿڡ�ʹ��ԭ�����ڽӿڲ����ݶ�����һ��������Щ�����һ������

*/


class Current18v {
public:
	void use18vCureent() {
		cout << "ʹ��18v�Ľ�����" << endl;
	}
};

class Current220v
{
public:
	void use220vCurrent()
	{
		cout << "ʹ��220v�Ľ�����" << endl;
	}
};

//
class Adapter :public Current18v {
public:
	Adapter(Current220v *p) {
		m_p220v = p;
	}
	void use18vCureent() {
		cout << "adapter��ʹ�õ���" << endl;
		m_p220v->use220vCurrent();
	}
private:
	Current220v * m_p220v;
};

void main() {
	Current220v *p220v = new Current220v;

	Adapter *padapter = new Adapter(p220v);
	padapter->use18vCureent();

	cin.get();
}