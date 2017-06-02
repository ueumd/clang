#include "iostream"

using namespace std;

void maind11()
{
	cout << "hello..." << endl;
	system("pause");
}

//<< >> 标准输入cin和标准输出cout 始终写在操作符的左边

void maind12()
{
	//面向过程
	
	double r = 0;
	double s = 0;

	cout << "请输入圆的半径:";
	cin >> r; //cin代表标准输入
	cout << "r:" << r << endl;
	s = 3.14*r*r;

	cout << "圆形的面积是：" << s << endl;

	
	cout << "hello..." << endl;
	system("pause");
}

//c++中定义了一个自定义数据类型
struct Circle
{
	double m_s; //圆形面积
	double m_r; 
};

//c++中定义了一个自定义数据类型 MyCircle

/*
1 类的抽象：成员变理 成员函数
2 实例化 类的对象
*/
//类是一个数据类型 （固定大小内存块的别名）；定义一个类，是一个抽象的概念，不会给你分配内存
//用数据类型定义变量的时候才会分配内存
class MyCircle
{
public:
	double m_s; //圆形面积  成员变量
	double m_r;

public:
	void setR(double r) //成员函数
	{
		m_r = r;
	}

	double getR()
	{
		return m_r;
	}

	double getS()
	{
		m_s = 3.14*m_r*m_r;
		return m_s;
	}

protected:

};

void maind13()
{
	MyCircle c1, c2, c3;//用类 定义 变量（对象）
	double r;
	cout << "请输入c1圆形的半径：";
	cin >> r;

	c1.setR(r);
	cout << "c1圆形的面积是：" << c1.getS() << endl;

	system("pause");
}