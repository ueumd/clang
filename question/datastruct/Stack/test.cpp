#include<iostream>
#include<string>
#include "Stack.h"
#include "Coordinate.h"
using namespace std;

void testStack() {
	Stack<int> *s = new Stack<int>(3);
	s->push(10);
	s->push(20);
	s->push(30);

	cout << s->length() << endl;
	s->traverse(true);
}

void testStackString() {
	Stack<string> s(3);
	s.push("Hello");
	s.push("World");

	cout << s.length() << endl;
	s.traverse(true);
}

void testCoordinate() {
	Stack<Coordinate> *ps = new Stack<Coordinate>(4);
	Coordinate c1(10, 20);
	Coordinate c2(30, 40);
	Coordinate c3(50, 60);

	ps->push(c1);
	ps->push(c2);
	ps->push(c3);

	cout <<"Length: "<< ps->length() << endl;
	ps->print(true);

}

//����ת��
/*
���������ʮ����������N�� �ֱ������������N�Ķ����ơ��˽��ơ�ʮ�����Ƶ���
��ʽ��N=(N div d) * d + N mod d (div��ʾ����, mod��ʾ����)
��1348����ʮ���ƣ�=��2504�����˽��ƣ�=��544����ʮ�����ƣ�=��10101000100���������ƣ�

�̳���
	N        N div 8					N mod 8
1348				 168		           4
 168          21               0
  21           2               5
	 2           0               2

	 N        N div 16				N mod 8
1348				  84	             4
  84           5               4
	 5           0               5  
*/

#define BINARY          2
#define OCTONARY        8
#define HEXADECIMAL    16

void test() {
	Stack<int> *ps = new Stack<int>(30);

	int N = 1348;
	int mod = 0;

	while (N != 0) {
		mod = N % 8;
		ps->push(mod);
		N = N / 8;
	}

	ps->traverse(false);

}

void main() {
	// testStack();
	//testStackString();
	//testCoordinate();

	test();
	cin.get();
}