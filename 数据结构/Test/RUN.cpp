#include <iostream>
using namespace std;
class A
{
	virtual void g()
	{
		cout << "A::g" << endl;
	}
private:
	virtual void f()
	{
		cout << "A::f" << endl;
	}
};
class B : public A
{
	void g()
	{
		cout << "B::g" << endl;
	}
	virtual void h()
	{
		cout << "B::h" << endl;
	}
};
typedef void(*Fun)(void);
void main()
{

	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;



	B b;
	Fun pFun;

	for (int i = 0; i < 3; i++)
	{
		pFun = (Fun)*((int*)* (int*)(&b) + i);
		
		pFun();
	}




	cin.get();
}