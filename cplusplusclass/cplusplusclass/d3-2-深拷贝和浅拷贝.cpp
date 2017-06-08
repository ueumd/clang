#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
using namespace std;

class Name
{
public :
	Name(const char *myp)
	{
		len = strlen(myp);
		p = (char *)malloc(len + 1);
		strcpy(p, myp);
	}
	//������� ���ֹ���д�������캯�� ʹ�����
	Name(const Name& obj)
	{
		len = obj.len;
		p = (char *)malloc(len + 1);
		strcpy(p, obj.p);
	}

	~Name()
	{
		if (p != NULL)
		{
			free(p);
			p = NULL;
			len = 0;
		}
	}
private:
	char *p;
	int len;
};

//
void testName()
{
	Name obj1("abcefg");
	Name obj2 = obj1;//Ĭ�ϵ�copy���캯��  c++�������ṩ ����������ʱ�� ������

	Name obj3("aaa");
	obj3 = obj1; // = �ȺŲ��� ͬ������ ǳ����  obj1������ʱ obj3��ָ�������ռ� ���Ұָ��

	Name("adddd"); //�����һ���������� �����������û�ж��������
}

void maind32()
{
	
	testName();
	cout << "hello..." << endl;

	system("pause");
	return;
}