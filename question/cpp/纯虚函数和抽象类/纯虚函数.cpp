#include "iostream"
using namespace std;
#if 0
在C++中，可以将虚函数声明为纯虚函数，语法格式为：

virtual 返回值类型 函数名 (函数参数) = 0;

纯虚函数没有函数体，只有函数声明，在虚函数声明的结尾加上=0，表明此函数为纯虚函数。

最后的=0并不表示函数返回值为0，它只起形式上的作用，告诉编译系统“这是纯虚函数”。

包含纯虚函数的类称为抽象类（Abstract Class）。
之所以说它抽象，是因为它无法实例化，也就是无法创建对象。
原因很明显，纯虚函数没有函数体，不是完整的函数，无法调用，也无法为其分配内存空间。

抽象类通常是作为基类，让派生类去实现纯虚函数。派生类必须实现纯虚函数才能被实例化。
#endif

/*
抽象类(含有纯虚函数) 只能做继承 相当于JAVA中接口类
*/
class Figure	
{
public:
	virtual void getArea() = 0; // 纯虚函数 只能声明，不能有方法体
};

class Circle : public Figure
{
public:
	Circle(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual void getArea()
	{
		cout << "圆形的面积：" << 3.14*a*a << endl;
	}
private:
	int a;
	int b;
};

class Tri : public Figure
{
public:
	Tri(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual void getArea()
	{
		cout << "三角形的面积：" << a*b / 2 << endl;
	}
private:
	int a;
	int b;
};

class Square : public Figure
{
public:
	Square(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual void getArea()
	{
		cout << "四边形的面积：" << a*b << endl;
	}
private:
	int a;
	int b;
};

void playFigure(Figure *base)
{
	base->getArea();
}

void maind73()
{

	//Figure f;//抽象不能被实例化
	Figure *base = NULL;


	Circle c1(10, 20);
	c1.getArea();//这样写没有多态的威力

	Tri t1(20, 30);
	Square s1(50, 60);

	//多态的方式
	playFigure(&c1);
	playFigure(&t1);
	playFigure(&s1);

	cout << "hello..." << endl;

	system("pause");
	return;
}