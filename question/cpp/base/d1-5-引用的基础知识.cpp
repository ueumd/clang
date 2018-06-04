#include "iostream"

using namespace std;

//1 引用的概念 
void refbase()
{
	int a = 10;
	//引用的语法 Type& name=var;
	int &b = a;
	//int &c; //普通引用必须要初始化 不然报错

	b = 100; //相当于把a修改成了100



	printf("a:%d, b:%d\n", a, b);//100 100 

	a = 200;

	printf("a:%d, b:%d\n", a, b);// 200 200
}

//2 用处
//引用作函数参数时不进行初始化 普通的必须
int myswap(int &a,int &b)
{
	int c = 0;

	c = a;
	a = b;
	b = c;
	
	return 0;
}

//复杂类型数据引用

struct MyTeacher
{
	char name[64];
	int age;
};
//指针方式
void printT(MyTeacher *pT)
{
	cout << pT->age << endl;
}

void printT2(MyTeacher &pT)
{
	cout << pT.age << endl; //别名要用.
	pT.age = 10; //会影向到t1
}

void printT3(MyTeacher pT)
{
	cout << pT.age << endl;//元素要用.
	pT.age = 1; //不会影向到实参里的t1
}

void maind15()
{
	int x = 100;
	int y = 10;
	refbase();

	//a就是x的别名 
	myswap(x,y);
	printf("x:%d, y:%d\n", x, y);// 10 100

	MyTeacher t1;
	t1.age = 100;

	printT(&t1); //100
	printT2(t1); //100 pT是t1的另名
	printT3(t1); //100 pT是形参，t1 拷贝一分数据给 pT 相当于 pT=t1;

	cout << t1.age << endl; //别名要用.
	cout << "hello..." << endl;

	system("pause");
	return;
}