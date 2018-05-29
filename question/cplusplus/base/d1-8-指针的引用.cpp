#include "iostream"

using namespace std;

struct Teacher
{
	char name[64];
	int age;
};

int getTeacher(Teacher **p)
{
	Teacher *tmp = NULL;
	if (p == NULL)
	{
		return -1;
	}

	tmp = (Teacher *)malloc(sizeof(Teacher));
	if (tmp == NULL)
	{
		return -2;
	}
	tmp->age = 100;

	// p是实参的地址 *实参的地址 去间接修改实参的值
	*p = tmp;
}

//c++指针引用
int getTeacher2(Teacher * &myp)
{
	//给myp赋值 相当于给main 函数中的pT1赋值
	myp = (Teacher *)malloc(sizeof(Teacher));
	if (myp == NULL)
	{
		return -1;
	}

	myp->age = 10;

}
void maind18()
{

	Teacher *pT1 = NULL;

	getTeacher(&pT1); //传递是 pT1的指针变量的地址

	cout <<"age:"<< pT1->age << endl;

	getTeacher2(pT1);
	cout << "age:" << pT1->age << endl;

	cout << "hello..." << endl;

	system("pause");
	return;
}