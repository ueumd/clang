#include <iostream>
using namespace std;
/*
�̳еı��ʣ�����һ�ָ��࣬�����븸�෢����ͻ�����Ǹ���,�ƶ�����������ڴ����
*/

class Father {
public:
	int age = 30;
	void show() {
		cout << "father" << endl;
	}
};

class Son : public Father {
public:
	int age = 5;
	void show() {
		cout << "son" << endl;
	}
};

//��̳�
class MyClass : public Father, public Son
{
public:
	int age = 0;
	void show() {
		cout << "MyClass" << endl;
	}
};

void main2() {
	Son son;
	cout << son.age << endl;				//5

	cout << son.Father::age << endl;	//30

	son.show();	//son
	son.Father::show(); //father

	MyClass m;
	cout << m.age << endl;  // 0
	m.show();								//MyClass

	m.Father::show();	//father
	m.Son::show();    //son


	cin.get();
}