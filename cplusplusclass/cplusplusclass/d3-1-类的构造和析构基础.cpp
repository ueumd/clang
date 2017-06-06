#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
using namespace std;

class MyClass
{
private:
	int a;
	int b;
	char *p;
public:
	MyClass()
	{
		a = 10;
		p = (char *)malloc(100);
		//p = "hello,world!";
		strcpy(p, "hello,world!");
		cout << "无参构造 被执行了 " << endl;
	}

	//有参
	MyClass(int a, int b)
	{
		this->a = a;
		this->b = b;
		this->p = (char *)malloc(100);
		strcpy(this->p, "hello,world!");
		cout << "有参构造 被执行了 " << endl;
	}

	//赋值构造函数（copy构造函数）
	MyClass(const MyClass& obj)
	{
		this->a = obj.a + 1000000;
		this->b = obj.b + 1000000;
		this->p = (char *)malloc(100);
		strcpy(this->p, "hello,world! copy");
		cout << "我也是构造函数" << endl;
	}

	void print()
	{
		cout << a << endl;
		cout << p << endl;
	}

	~MyClass()
	{
		if (p != NULL)
		{
			free(p);
		}
		cout << "析构函数 被执行了 " << endl;
	}
};

void runMyClass()
{
	printf("-------------mc1-----------------\n");
	//先创建的对象 后释放 
	MyClass mc; //直接调用无参构造函数
	mc.print();

	printf("-------------mc2-----------------\n");

	MyClass mc2(1000,4);
	mc2.print();

	printf("---------------mc4---------------\n");
	MyClass mc4 = mc2; //执行的是copy构造函数
	mc4.print();

	printf("---------------xg---------------\n");
}

void main()
{
	runMyClass();

	cout << "hello..." << endl;

	system("pause");
	return;
}