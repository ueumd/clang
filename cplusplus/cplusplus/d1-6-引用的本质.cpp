#include "iostream"

using namespace std;

void refone()
{
	int a = 10;
	int &b = a;

	printf("&a:%d\n", &a);
	printf("&b:%d\n", &b); //打印是一样的 a和b就是同一块内存空间的门牌号
	return;
}

//普通引用有自己的空间吗？有
struct MyStruct
{
	char name[64]; //64
	int age;//4	
	int &a;//4 0 很像指针所占的内存空间
	int &b;//4 0
};

//引用的本质
//引用在c++中内部实现是一个常指针 Type& name <-> Type * const name

int modifyA(int &a1) 
{
	a1 = 100;
	return 0;
}

int modifyA2(int * const a1)
{
	*a1 = 101;
	return 0;
}

void main()
{
	refone();
	printf("MyStruct:%d\n", sizeof(MyStruct)); //76

	int a = 10000;
	modifyA(a);
	cout << a << endl; //100

	modifyA2(&a);//如果是指针，需要我们自己手工取实参的地址

	cout << a << endl; //101

	cout << "hello..." << endl;

	system("pause");
	return;
}