#include <iostream>
using namespace std;
class Hello {
public:
	Hello(int a, int b) :m_a(a), m_b(b) {
		
	}
	Hello(const Hello &stu) {
		//����û�и�ֵ���� m_a m_b����������ֵ
		cout << "�������캯��" << endl;
	}
public:
	void display() {
		cout << "a=" << m_a << "b=" << m_b << endl;
	}
public:
	int m_a;
	int m_b;
};


void main11111() {
	Hello h(1, 3);    //��ʼ��
	h.display(); // 1 3

	Hello h3(h);			//���ÿ������캯��
	h3.display();

	/*
	���ÿ������캯��,���δ���忽�����캯�� c++����Ĭ�Ͽ������캯������������ˣ����ö���Ĺ��캯��
	*/
	Hello h2 = h;		// ���ÿ������캯�� ��ֵ
	h2.display();   // Ĭ�Ͽ������캯�� 1 3
	/*
	���ÿ������캯��������û�и�ֵ��������������ֵ
	a=-858993460b=-858993460
	*/

	cin.get();
}