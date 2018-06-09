#include<iostream>
using namespace std;

//��������֮��ת��
void basetype() {

	int c = (int)2.5;							 //C���	
	int a = 1.2;									 //�Զ�ת��
	int b = static_cast<int>(2.3); //cpp��ʾת��

	//cppָ��ת��
	int *p1 = nullptr;
	char *p2 = reinterpret_cast<char *>(p1);
}


//����������������
class MyClass {
public:
	int x;
	int y;
	MyClass() {}
	explicit MyClass(int a) :x(a), y(a) {
		cout << "����" << endl;
	}
	void operator = (int num) {
		cout << "��ֵ����" << endl;
		x = y = num;
	}
	
	//������ת��Ϊint
	operator int() { 
		return (x + y) / 2;
	}
	operator double();
};

//�������ͣ��������ת����
MyClass::operator double() {
	return x + y; //ת��Ϊdobule����
}

#if 0
x::operator T()
{
	...
	return T ���Ͷ���
}
#endif


// 4�ַ�ʽ���캯����ʼ��,��������ת��(�� explicit�ؼ���)
void test() {
	//MyClass mc1 = 5;  //��explicit�ᱨ��
	MyClass mc2 (5);
	MyClass mc3 = MyClass(5);
	MyClass mc4 = (MyClass)5;
}

// exlicit
void test2() {
	// 4�ַ�ʽ���캯����ʼ��,��������ת��
	MyClass mc1 = static_cast<MyClass>(5); //ǿ��ת��
	MyClass mc2(5);
	MyClass mc3 = MyClass(5);
	MyClass mc4 = (MyClass)5;
}

void test3() {
	MyClass mc;
	mc.x = 4;
	mc.y = 3;
	int a = mc;  // (4+3)/2 = 3ȡ��
	double db = mc; // 4+3=7
	cout << a << endl;
	cout << db << endl;
}

void m() {
//	test();
	test3();
	cin.get();
}