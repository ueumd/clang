#include "iostream"

using namespace std;


/*
new 执行类的类型构造函数 delete 执行析构

malloc free 函数c 不会调用自定义类的构造和析构

*/
class NewTest
{
	
public :
	NewTest(int _a)
	{
		a = _a;
		cout << "构造" << endl;
	}
	~NewTest()
	{
		cout << "析构" << endl;
	}
	void getC()
	{
		cout << c << endl;
	}
	void addC()
	{
		c=c+1;
	}
	static void getC2()
	{
		//注意静态函数只能调用静态成员变量 如调用a报错
		cout << c << endl;
	}
private:
	int a;
	static int c; //静态成员变量 
};

int NewTest::c = 200;
void testnew()
{
	int *p = (int *)malloc(sizeof(int));
	*p = 10;
	printf("p:%d\n",*p); //10
	free(p);

	int *p3 = new int(30);
	printf("*p3:%d\n", *p3); //30
	delete p3;

	//c语言中分配数组
	int *pArr = (int *)malloc(sizeof(int) * 10); //int array[10]
	pArr[0] = 1;

	int *pArr2 = new int[10];
	pArr2[1] = 2;
	delete[] pArr2; //数组要加[]

	//分配对象
	NewTest *pT1 = (NewTest *)malloc(sizeof(NewTest));//c语言
	free(pT1);

	NewTest *p2 = new NewTest(100);
	delete p2;
}

void teststatic()
{
	NewTest nt(10);
	NewTest nt2(10);
	nt.getC(); //200
	nt2.addC();
	nt.getC(); // 201

	nt2.getC2(); //用对象调

	NewTest::getC2(); //类调

	//nt nt2共用 c
}

void maind34()
{
	//testnew();
	teststatic();

	cout << "hello..." << endl;

	system("pause");
	return;
}