#include "iostream"

using namespace std;


int myadd(int a, int b) // 子任务的实现者
{
	printf("func add...a+b:%d\n",a+b);
	return a + b;
}
int myadd2(int a, int b) // 子任务的实现者
{
	printf("func2 add...a+b:%d\n", a + b);
	return a + b;
}
int myadd3(int a, int b) // 子任务的实现者
{
	printf("func3 add...a+b:%d\n", a + b);
	return a + b;
}
int myadd4(int a, int b) // 子任务的实现者
{
	printf("func4 add...a+b:%d\n", a + b);
	return a + b;
}

//定义了一个类型
typedef int(*MyTypeFuncAdd)(int a, int b);

//函数指针 做 函数参数
int MainOp(MyTypeFuncAdd myFuncAdd)
{
	int c = myFuncAdd(5, 6);
	return c;
}

int MainOp2(int (*MyPointerFuncAdd)(int a, int b)) //与上面一样
{
	int c = MyPointerFuncAdd(10, 20);
	return c;
}

void maindw82()
{
	myadd(1, 2);//直接调用

	MyTypeFuncAdd myFuncAdd = NULL;
	myFuncAdd = myadd;
	myFuncAdd(3, 4); //间接调用

//任务的调用 和任务的编写可以分开

	//在mainop框加没有发生任何变化的情况下..
	MainOp2(myadd);
	MainOp(myadd);

	MainOp2(myadd2);
	MainOp(myadd4);

	cout << "hello..." << endl;

	system("pause");
	return;
}