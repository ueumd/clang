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

	int getA() {
		return this->a;
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

void testClass(MyClass mc)
{
	cout << "age is:" << mc.getA() << endl;
}

/*
返回是一个元素对象，类型是MyClass(复杂类型)
返回的是一个新的匿名对象，所以会调用匿名对象的copy构造函数
匿名对象的去和留 :
	如果用匿名对象 初始化 另外一个同类的对象 匿名对象 转成有名对象
	如果用匿名对象 赋值给 另外一个同类的对象 匿名对象 被析构
*/
MyClass g()
{
	MyClass MY(300, 300);
	return MY;
}

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

	testClass(mc4);//调的是copy构造函数

	printf("---------------mc5---------------\n");

	//用匿名对象初始化m 此时c++编译器 直接把匿名对象转成 mc5 ，从匿名转成有名 mc5
	MyClass mc5=g(); //匿名对象不会被析构掉
	mc5.print();

	//MyClass mc5 (20,1); 
	//mc5=g();//匿名对象赋值给 mc5会被析构掉 再析构mc5

	printf("---------------xg---------------\n");
}

void maind31()
{
	runMyClass();

	cout << "hello..." << endl;

	system("pause");
	return;
}