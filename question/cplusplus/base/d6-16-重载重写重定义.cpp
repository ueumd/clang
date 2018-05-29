#include "iostream"

using namespace std;
/*
函数重载：
	必须在同一个类中进行
	子类无法重载父类的函数，父类同名函数将被名称覆盖 如要访问加.:: 域访符 显示调用  B.AA::.c
	重载是在编译期间根据参数类型和个数决定函数调用

函数重写：
	必须发生于父类和子类之间
	并且父类与子类的函数必须有完相同的原型
	使用 virtual声明之后能够产生多态（如果不使用 那叫 重定义）
	多态是在运行期间根据具体对象的类型决定函数调用

*/
class Parent1616
{
public:
	int abc()
	{
		printf("parent abc");
		return 0;
	}
	//这三个函数是重载关系
	virtual void func()
	{
		cout << "func() do.." << endl;
	}
	virtual void func(int i)
	{
		cout << "func() do.." << i << endl;
	}
	virtual void func(int i, int j)
	{
		cout << "func() do.." << i << j <<endl;
	}

};

class Child1616 : public Parent1616
{
public:
	//非虚数重写 叫重定义
	int abc()
	{
		printf("child abc");
		return 0;
	}

	int abc(int i)
	{

		printf("child abc");
		return 0;
	}

	//虚函数重写父类的func 将发生多态
	virtual void func(int i)
	{
		cout << "func() do.." << i << endl;
	}
	virtual void func(int i, int j)
	{
		cout << "func() do.." << i << j << endl;
	}

	virtual void func(int i, int j, int k)
	{
		cout << "func() do.." << i << j << k << endl;
	}

};


void maind616()
{

	Child1616 c1;
	c1.Parent1616::func(); //子类的func把父类的func无参函数给覆盖了，所以要显示调用
	c1.func(100);

	//vs2015能正常访问？
	c1.func(100, 200, 300);

	cout << "hello..." << endl;

	system("pause");
	return;
}