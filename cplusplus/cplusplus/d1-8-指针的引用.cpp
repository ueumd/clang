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

	// p��ʵ�εĵ�ַ *ʵ�εĵ�ַ ȥ����޸�ʵ�ε�ֵ
	*p = tmp;
}

//c++ָ������
int getTeacher2(Teacher * &myp)
{
	//��myp��ֵ �൱�ڸ�main �����е�pT1��ֵ
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

	getTeacher(&pT1); //������ pT1��ָ������ĵ�ַ

	cout <<"age:"<< pT1->age << endl;

	getTeacher2(pT1);
	cout << "age:" << pT1->age << endl;

	cout << "hello..." << endl;

	system("pause");
	return;
}