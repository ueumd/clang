#include "iostream"

using namespace std;


/*
new ִ��������͹��캯�� delete ִ������

malloc free ����c ��������Զ�����Ĺ��������

*/
class NewTest
{
	
public :
	NewTest(int _a)
	{
		a = _a;
		cout << "����" << endl;
	}
	~NewTest()
	{
		cout << "����" << endl;
	}
	void getC()
	{
		cout << c << endl;
	}
	void addC()
	{
		c=c+1;
	}
	static void getC2()
	{
		//ע�⾲̬����ֻ�ܵ��þ�̬��Ա���� �����a����
		cout << c << endl;
	}
private:
	int a;
	static int c; //��̬��Ա���� 
};

int NewTest::c = 200;
void testnew()
{
	int *p = (int *)malloc(sizeof(int));
	*p = 10;
	printf("p:%d\n",*p); //10
	free(p);

	int *p3 = new int(30);
	printf("*p3:%d\n", *p3); //30
	delete p3;

	//c�����з�������
	int *pArr = (int *)malloc(sizeof(int) * 10); //int array[10]
	pArr[0] = 1;

	int *pArr2 = new int[10];
	pArr2[1] = 2;
	delete[] pArr2; //����Ҫ��[]

	//�������
	NewTest *pT1 = (NewTest *)malloc(sizeof(NewTest));//c����
	free(pT1);

	NewTest *p2 = new NewTest(100);
	delete p2;
}

void teststatic()
{
	NewTest nt(10);
	NewTest nt2(10);
	nt.getC(); //200
	nt2.addC();
	nt.getC(); // 201

	nt2.getC2(); //�ö����

	NewTest::getC2(); //���

	//nt nt2���� c
}

void maind34()
{
	//testnew();
	teststatic();

	cout << "hello..." << endl;

	system("pause");
	return;
}