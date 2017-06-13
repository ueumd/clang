#include "iostream"

using namespace std;

class Figure //������(���д��麯��) ֻ�����̳� 
{
public:
	virtual void getArea() = 0; //���麯��
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
		cout << "Բ�ε������" << 3.14*a*a << endl;
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
		cout << "�����ε������" << a*b/2 << endl;
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
		cout << "�ı��ε������" << a*b << endl;
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

	//Figure f;//�����ܱ�ʵ����
	Figure *base = NULL;

	
	Circle c1(10, 20);
	c1.getArea();//����дû�ж�̬������

	Tri t1(20, 30);
	Square s1(50, 60);

	//��̬�ķ�ʽ
	playFigure(&c1);
	playFigure(&t1);
	playFigure(&s1);
	
	cout << "hello..." << endl;

	system("pause");
	return;
}