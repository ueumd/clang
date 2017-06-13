#include "iostream"

using namespace std;

class Figure //抽象类(含有纯虚函数) 只能做继承 
{
public:
	virtual void getArea() = 0; //纯虚函数
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
		cout << "三角形的面积：" << a*b/2 << endl;
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

void main()
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