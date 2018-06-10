#include <iostream>
using namespace std;
/*
static ��Ա���������࣬������ĳ������Ķ��󣬼�ʹ�����������ҲֻΪ num ����һ���ڴ棬���ж���ʹ�õĶ�������ڴ��е����ݡ�
��ĳ�������޸��� num��Ҳ��Ӱ�쵽��������

static ��Ա�������������������ⲿ��ʼ����������ʽΪ��type class::name = value;
int Hello::num = 0;
int Hello::count = 100;

����ľ�̬���� �� �����еĸ���������������ͳ��һ������������
�ࣨ���� �����ࣩ��ֱ�ӷ��ʣ� ���󣨸��� �����ࣩ������

��̬���� public �����������������󶼿��Է���
��̬���� private ������ڲ����Է���,�趨�����ӿ� get set
��̬���� protectd ���������������ڲ����Է��ʣ��ⲿ�����趨�ӿ�

��̬�����Ľӿڣ�ԭ���趨Ϊ��̬����������Ҫthisָ�룬��������һ������
*/

class Hello {
private:
	static int count; // �����̳�
		
public:
	static int num; //���������������Ĵ�С
	Hello() {
		num += 1;
	}
	~Hello() {
		num -= 1;
	}

public:
	static void setCount(int c) {
		count=c;
	}

	static int getCount() {
		return count;
	}

};

// static ��Ա�������������������ⲿ��ʼ����������ʽΪ��type class::name = value;
int Hello::num = 0;
int Hello::count = 100;

class World :public Hello {

};

void testHello() {
	cout << sizeof(Hello) << endl; //1
	cout << sizeof(World) << endl; //1
	cout << World::num << endl;		 //0
}

//��̬���� ������Ҳ���Է��ʲ��ۼ�
void testWord() {
	Hello h1, h2;
	World w1, w2;

	cout << sizeof(Hello) << endl; //1
	cout << sizeof(World) << endl; //1
	cout << World::num << endl;		 //4

	cout << h1.num << endl;	//	4
	cout << w1.num << endl;	//  4

	h1.setCount(10);
	cout << h1.getCount() << endl; // 10
	cout << w1.getCount() << endl; // 10

}

void mainstatic() {

	testWord();

	cin.get();
}