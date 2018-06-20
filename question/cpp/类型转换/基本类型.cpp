#include<iostream>
using namespace std;

/*
static_cast				静态类型转换
reinterpret_cast  重新解释类型
dynamic_cast			命名上理解是动态类型转换，如子类和父类之间的多态类型转换
const_cast				字面上理就是去const属性
*/
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

//dynamic_cast
class Animal {
public:
	virtual void cry()=0;
};

class Dog:public Animal {
public:
	virtual void cry() {
		
	}
	void doHome() {}
};

class Cat :public Animal {
public:
	virtual void cry() {}
	void doThing() {}
};

//dynamic_cast
void playObj(Animal *base) {
	base->cry();

	//dynamic_cast 运行时类型识别 RIIT
	Dog *pDog = dynamic_cast<Dog *>(base);
	if (NULL != pDog) {
		pDog->doHome();
	}

	Cat *pCat = dynamic_cast<Cat *>(base); //父类转子类 向下转型
	if (NULL != pCat) {
		pCat->doThing();
	}

}

//const_cast
void printBuf(const char *p) {
	//p[0] ='Z' //complie error
	char *p1 = NULL;
	//要知道 变量转换之前是什么类型 转换之后是什么类型
	//const char * === char *
	p1 = const_cast<char *>(p);
	p1[0] = 'Z'; //通过p1修改了内存空间
	cout << p << endl; //Zaaabbbff
}

void main() {
//	test();
	//test3();

	char buf[] = "aaaabbbff";
	printBuf(buf);
	cin.get();
}