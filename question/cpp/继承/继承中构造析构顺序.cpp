#include<iostream>
using namespace std;
/*
�̳У����಻�������࣬���������ڸ���

����: ���� => ���� => ����;���������ڸ��๹��
���������� => ���� => ����; ���������ڸ���
*/

class Animal {
	int x;
	int y;
public:
	//Animal() {
	//	cout << "Animal����" << endl;
	//}

	Animal(int a, int b) :x(a), y(b) {
		cout << "Animal�вι���" << endl;
	}
	~Animal() {
		cout << "Animal����" << endl;
	}
};

class People : public Animal {
	int z;
public:
	/*People() {
		cout << "People����" << endl;
	}*/

	//���ι���̳�
	People(int a, int b, int c) :Animal(a, b),z(c) 
	{
		cout << "People�вι���" << endl;
	}

	~People()
	{
		cout << "People����" << endl;
	}
};


class Student : public People {
	int l;
public:
	/*Student() {
		cout << "Student����" << endl;
	}*/
	Student(int a, int b, int c, int d): People(a,b,c),l(d) 
	{
		cout << "Student�вι���" << endl;
	}
	~Student() {
		cout << "Student����" << endl;
	}
};

void testAnimal() {
	/*
	 testAnimal() �������������ʧ�� �ͻ�������
	 ֱ����main�����У�main����û����ʧ��ֻ�н������̲Ż�
	*/
	//	People p(10, 20, 30);
	Student s(100, 200, 300, 400);
	/*
	Animal�вι���
	People�вι���
	Student�вι���
	Student����
	People����
	Animal����
	*/
}

void main() {
	testAnimal();
	cin.get();
}
