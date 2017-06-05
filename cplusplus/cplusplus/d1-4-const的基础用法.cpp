#include "iostream"

using namespace std;
struct Teacher {
	char name[64];
	int age;
};

//指针所指向的内存空间，不能被修改
int operatorTeacher01(const Teacher *pT)
{
	//pT->age=10; //error
	return 0;
}

//指针变量本身不能修改
int operatorTeacher02(Teacher * const pT)
{
	pT->age=10;
	//pT = NULL;//error
	return 0;
}

//指针变量本身不能修改,指向的内存空间也不能被修改
int operatorTeacher03(const Teacher * const pT)
{
	//pT->age = 10; //error
	//pT = NULL;//error

	printf("age:%d\n", pT->age); //可以读 age:100
	return 0;
}



void maind14()
{
	Teacher t1;
	t1.age = 100;

	operatorTeacher03(&t1);

	cout << "hello..." << endl;

	system("pause");
	return;
}

/*

2 const 和 define相同之处

不同 #define 在编译预处理阶段 处理   const 分配内存的时机 编译器编译期间

*/

#define xyzb 100
void maind143()
{
	int a;
	const int b = 10;

	int c;

	printf("&a:%d, &b:%d, &c:%d\n", &a, &b, &c);

	/*int x = 10;
	int y = 20;
	int array[x + y];*/
	//linux内核里是成立的 linux内核的gcc编译器支持  以c和c++编译器不支持 

	const int x = 10;
	const int y = 20;
	int array2[x + y + xyzb];


	system("pause");
	return;
}