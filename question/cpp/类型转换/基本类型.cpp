#include<iostream>
using namespace std;

/*
static_cast				��̬����ת��
reinterpret_cast  ���½�������
dynamic_cast			����������Ƕ�̬����ת����������͸���֮��Ķ�̬����ת��
const_cast				�����������ȥconst����
*/
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

//dynamic_cast
class Animal {
public:
	virtual void cry()=0;
};

class Dog:public Animal {
public:
	virtual void cry() {
		
	}
	void doHome() {}
};

class Cat :public Animal {
public:
	virtual void cry() {}
	void doThing() {}
};

//dynamic_cast
void playObj(Animal *base) {
	base->cry();

	//dynamic_cast ����ʱ����ʶ�� RIIT
	Dog *pDog = dynamic_cast<Dog *>(base);
	if (NULL != pDog) {
		pDog->doHome();
	}

	Cat *pCat = dynamic_cast<Cat *>(base); //����ת���� ����ת��
	if (NULL != pCat) {
		pCat->doThing();
	}

}

//const_cast
void printBuf(const char *p) {
	//p[0] ='Z' //complie error
	char *p1 = NULL;
	//Ҫ֪�� ����ת��֮ǰ��ʲô���� ת��֮����ʲô����
	//const char * === char *
	p1 = const_cast<char *>(p);
	p1[0] = 'Z'; //ͨ��p1�޸����ڴ�ռ�
	cout << p << endl; //Zaaabbbff
}

void main() {
//	test();
	//test3();

	char buf[] = "aaaabbbff";
	printBuf(buf);
	cin.get();
}