#include<iostream>
using namespace std;

/*
��ģ��
template<typename ���Ͳ���1 , typename ���Ͳ���2 , ��> class ����{
	//TODO:
};
*/

template<typename T1, typename T2> class Point {
public:
	Point(T1 x, T2 y): m_x(x), m_y(y){ }
public:
	T1 getX() const;
	void setX(T1 x);
	T2 getY() const;
	void setY(T2 y);

private:
	T1 m_x;
	T2 m_y;
};

//ע����д��ʽ
template<typename T1, typename T2> T1 Point<T1, T2>::getX() const {
	return m_x;
}


template<typename T1, typename T2> void Point<T1, T2>::setX(T1 x) {
	m_x = x;
}

template<class  T1, class  T2> T2 Point<T1, T2>::getY() const {
	return m_y;
}

template<class  T1, class  T2> void Point<T1, T2>::setY(T2 y) {
	m_y = y;
}

void test() {
	Point<int, int> p1(10, 20);
	cout << "x=" << p1.getX() << ", y=" << p1.getY() << endl;

	Point<int, char*> p2(10, "����180��");
	cout << "x=" << p2.getX() << ", y=" << p2.getY() << endl;


	Point<char*, char*> *p3 = new Point<char*, char*>("����180��", "��γ210��");
	cout << "x=" << p3->getX() << ", y=" << p3->getY() << endl;
}

int main2() {
	test();
	system("pause");
	return 0;
}