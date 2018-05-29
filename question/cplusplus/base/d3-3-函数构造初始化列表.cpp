#include "iostream"
using namespace std;
class A 
{
public:
	A(int _a)
	{
		a = _a;
		cout << "A的构造函数 a"<< a << endl;
	}
	~A()
	{
		cout << "A的析构函数: a" << a << endl;
	}
private:
	int a;
};

class B
{
public:
	B(int _b):a1(100),a2(200),c(20)
	{
		b = _b;
		cout << "B的构造函数 b" << b << endl;
	}

	B(int _b1,int m, int n) :a1(m),a2(n), c(200)
	{
		b = _b1;
		cout << "B的构造函数 b" << b << c << endl;
	}

	~B()
	{
		cout << "B的析构函数 b" << b << endl;
	}
private:
	int b;
	A a1;
	A a2;
	const int c; //构造时必须初始化
};

void TestA()
{
	B objB(1,3,5); // A ->B （构造） B-A（析构）
}

void maind33()
{
	TestA();
	cout << "hello..." << endl;

	system("pause");
	return;
}