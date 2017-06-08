#include "iostream"

using namespace std;

class TestConst
{
public:
	TestConst(int a, int b) //TestConst(TestConst *this, int a,int b)
	{
		this->a = a;
		this->b = b;
	}
	/*
		const 修饰的是属性this->a this->b
		const 修饰的是this指针所指向的内存空间 
	*/
	void opVar(int a,int b) const //void opVar(TestConst *const this, int a,int b)
	{
		a = 100;
	}

private:
	int a;
	int b;

};

void runTestConst()
{
	TestConst tt(10, 100);
}

void maind42()
{

	cout << "hello..." << endl;

	system("pause");
	return;
}