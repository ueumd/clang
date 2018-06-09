#include<iostream>
using namespace std;

//基本类型之间转换
void basetype() {

	int c = (int)2.5;							 //C风格	
	int a = 1.2;									 //自动转换
	int b = static_cast<int>(2.3); //cpp显示转换

	//cpp指针转换
	int *p1 = nullptr;
	char *p2 = reinterpret_cast<char *>(p1);
}


//基本类型与类类型
class MyClass {
public:
	int x;
	int y;
	MyClass() {}
	explicit MyClass(int a) :x(a), y(a) {
		cout << "构造" << endl;
	}
	void operator = (int num) {
		cout << "赋值重载" << endl;
		x = y = num;
	}
	
	//类类型转化为int
	operator int() { 
		return (x + y) / 2;
	}
	operator double();
};

//重载类型（完成类型转换）
MyClass::operator double() {
	return x + y; //转换为dobule类型
}

#if 0
x::operator T()
{
	...
	return T 类型对象
}
#endif


// 4种方式构造函数初始化,视作类型转换(无 explicit关键字)
void test() {
	//MyClass mc1 = 5;  //有explicit会报错
	MyClass mc2 (5);
	MyClass mc3 = MyClass(5);
	MyClass mc4 = (MyClass)5;
}

// exlicit
void test2() {
	// 4种方式构造函数初始化,视作类型转换
	MyClass mc1 = static_cast<MyClass>(5); //强制转换
	MyClass mc2(5);
	MyClass mc3 = MyClass(5);
	MyClass mc4 = (MyClass)5;
}

void test3() {
	MyClass mc;
	mc.x = 4;
	mc.y = 3;
	int a = mc;  // (4+3)/2 = 3取整
	double db = mc; // 4+3=7
	cout << a << endl;
	cout << db << endl;
}

void m() {
//	test();
	test3();
	cin.get();
}