#include "iostream"

using namespace std;


int myadd(int a, int b) // �������ʵ����
{
	printf("func add...a+b:%d\n",a+b);
	return a + b;
}
int myadd2(int a, int b) // �������ʵ����
{
	printf("func2 add...a+b:%d\n", a + b);
	return a + b;
}
int myadd3(int a, int b) // �������ʵ����
{
	printf("func3 add...a+b:%d\n", a + b);
	return a + b;
}
int myadd4(int a, int b) // �������ʵ����
{
	printf("func4 add...a+b:%d\n", a + b);
	return a + b;
}

//������һ������
typedef int(*MyTypeFuncAdd)(int a, int b);

//����ָ�� �� ��������
int MainOp(MyTypeFuncAdd myFuncAdd)
{
	int c = myFuncAdd(5, 6);
	return c;
}

int MainOp2(int (*MyPointerFuncAdd)(int a, int b)) //������һ��
{
	int c = MyPointerFuncAdd(10, 20);
	return c;
}

void maindw82()
{
	myadd(1, 2);//ֱ�ӵ���

	MyTypeFuncAdd myFuncAdd = NULL;
	myFuncAdd = myadd;
	myFuncAdd(3, 4); //��ӵ���

//����ĵ��� ������ı�д���Էֿ�

	//��mainop���û�з����κα仯�������..
	MainOp2(myadd);
	MainOp(myadd);

	MainOp2(myadd2);
	MainOp(myadd4);

	cout << "hello..." << endl;

	system("pause");
	return;
}