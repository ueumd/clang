/*
ʵ�ֶ�̬������������
1.  Ҫ�м̳�
2�� Ҫ���麯����д
3�� �ø���ָ�루�������ã� ָ���������
*/
/*
C++�ж�̬��ʵ��ԭ��
�����������麯��ʱ��������������������һ���麯����
�麯������һ���洢���Ա����ָ������ݽṹ
�麯�������ɱ������Զ�������ά����
virtual��Ա�����ᱻ�����������麯������
�����麯��ʱ��ÿ�������ж���һ��ָ���麯�����ָ��(vptrָ��)
*/

#include "iostream"
using namespace std;

class Parent71
{
public:
	Parent71(int a = 0)
	{
		this->a = a;
	}
	virtual void print() //1 ���ֽ� дvirtual�ؼ��� �����⴦�� //�麯����
	{
		cout << "���ǵ�" << endl;
	}
private:
	int a;
};

class Child71 : public Parent71
{
public:
	Child71(int a = 0, int b=0):Parent71(a)
	{
		this->b = b;
	}
	virtual void print()
	{
		cout << "���Ƕ���" << endl;
	}
private:
	int b;
};

class ParentVptr
{
	ParentVptr(int a = 0)
	{
		this->a = a;
	}
	void print()
	{
		cout << "���ǵ�" << endl;
	}
private:
	int a;
};

class ParentVptr2
{
	ParentVptr2(int a = 0)
	{
		this->a = a;
	}
	virtual void print()
	{
		cout << "���ǵ�" << endl;
	}
private:
	int a;
};

void HowToPlay(Parent71 *base)
{
	base->print();//�ж�̬���� //2 ���ֽ�

	/*
		Ч����������������� ִ�������print���� �������� ִ�и���� print����
		c++��������������Ҫ������������� ���Ǹ������

		���������������ֱ��в�vptrָ�� ==>�麯���� ===> ��������ڵ�ַ ������ʵ����
		�ٰ�����е�ʱ��c++�������Ż�ȥ�жϣ�
	*/
}

void main()
{
	Parent71 p1; //3 ���ֽ� ���ඨ������ʱ�� c++���������ڶ��������һ��vptrָ��
	Child71 c1; //��������Ҳ��һ����vptrָ��

	HowToPlay(&p1);
	HowToPlay(&c1);

	//���� ��ô֤��vptrָ�����

	printf("ParentVptr:%d ,ParentVptr2:%d\n", sizeof(ParentVptr), sizeof(ParentVptr2));
	// x86 4 8

	cout << "hello..." << endl;

	system("pause");
	return;
}