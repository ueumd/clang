#include "iostream"

using namespace std;

void maind11()
{
	cout << "hello..." << endl;
	system("pause");
}

//<< >> ��׼����cin�ͱ�׼���cout ʼ��д�ڲ����������

void maind12()
{
	//�������
	
	double r = 0;
	double s = 0;

	cout << "������Բ�İ뾶:";
	cin >> r; //cin�����׼����
	cout << "r:" << r << endl;
	s = 3.14*r*r;

	cout << "Բ�ε�����ǣ�" << s << endl;

	
	cout << "hello..." << endl;
	system("pause");
}

//c++�ж�����һ���Զ�����������
struct Circle
{
	double m_s; //Բ�����
	double m_r; 
};

//c++�ж�����һ���Զ����������� MyCircle

/*
1 ��ĳ��󣺳�Ա���� ��Ա����
2 ʵ���� ��Ķ���
*/
//����һ���������� ���̶���С�ڴ��ı�����������һ���࣬��һ������ĸ�������������ڴ�
//���������Ͷ��������ʱ��Ż�����ڴ�
class MyCircle
{
public:
	double m_s; //Բ�����  ��Ա����
	double m_r;

public:
	void setR(double r) //��Ա����
	{
		m_r = r;
	}

	double getR()
	{
		return m_r;
	}

	double getS()
	{
		m_s = 3.14*m_r*m_r;
		return m_s;
	}

protected:

};

void maind13()
{
	MyCircle c1, c2, c3;//���� ���� ����������
	double r;
	cout << "������c1Բ�εİ뾶��";
	cin >> r;

	c1.setR(r);
	cout << "c1Բ�ε�����ǣ�" << c1.getS() << endl;

	system("pause");
}