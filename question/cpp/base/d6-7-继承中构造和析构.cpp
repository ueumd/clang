#include "iostream"

using namespace std;

class Parent6
{
public:
	void printP(int a, int b)
	{
		this->a = a;
		this->b = b;
		cout << "我是爹" << endl;
	}
	Parent6(int a, int b)
	{
		this->a = a;
		this->b = b;
		cout << "Parent构造函数" << endl;
	}
	Parent6(const Parent6 &obj)
	{
		cout << "Parent copy构造函数" << endl;
	}
	~Parent6()
	{
		cout << "Parent析构函数" << endl;
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
		cout << "Child6构造函数" << endl;
	}
	void printC()
	{
		cout << "我是儿子" << endl;
	}
	~Child6()
	{
		cout << "子类析构" << endl;
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
	运行结果：
	Parent构造函数
	Child6构造函数
	子类析构
	Parent析构函数
	*/
	runParent6();
	
	cout << "hello..." << endl;

	system("pause");
	return;
}