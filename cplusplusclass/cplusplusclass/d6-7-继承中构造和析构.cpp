#include "iostream"

using namespace std;

class Parent6
{
public:
	void printP(int a, int b)
	{
		this->a = a;
		this->b = b;
		cout << "���ǵ�" << endl;
	}
	Parent6(int a, int b)
	{
		this->a = a;
		this->b = b;
		cout << "Parent���캯��" << endl;
	}
	Parent6(const Parent6 &obj)
	{
		cout << "Parent copy���캯��" << endl;
	}
	~Parent6()
	{
		cout << "Parent��������" << endl;
	}
private:
	int a;
	int b;
};

class Child6 : public Parent6
{
public:
	Child6(int c, int a, int b) : Parent6(a, b)
	{
		this->c = c;
		cout << "Child6���캯��" << endl;
	}
	void printC()
	{
		cout << "���Ƕ���" << endl;
	}
	~Child6()
	{
		cout << "��������" << endl;
	}
protected:
private:
	int c;
};

void runParent6()
{
	///Parent6 p(1, 2);
	Child6 c(10, 20, 30);
}

void maind67()
{
	/*
	���н����
	Parent���캯��
	Child6���캯��
	��������
	Parent��������
	*/
	runParent6();
	
	cout << "hello..." << endl;

	system("pause");
	return;
}