#ifndef COORDINATE_H
#define COORDINATE_H
class Coordinate
{
public:
	Coordinate(int x=0, int y=0); //参数初始化变成默认的构造函数
	void print();
private:
	int m_iX;
	int m_iY;
};

#endif