
#include "iostream"
using namespace std; //iostreamû�������׼�� std ��Ҫ�ֹ�д



//�����������

namespace namesapceA
{
	int a = 10;
}

namespace namesapceB
{
	int a = 20;
	namespace namespaceC
	{
		struct Teacher
		{
			char name[32];
			int age;
		};
	}
}

void maind12()
{
	cout << "namespace test" << endl;

	//�������û��д using namespace std;��Ҫ��ʾ������std
	//std::cout << "namespace test" << std::endl; 


	//ʹ�������ռ�

	using namespace namesapceA;
	using namespace namesapceB;

	cout << namesapceA::a << endl;//10
	cout << namesapceB::a << endl;//20

	using namesapceB::namespaceC::Teacher;

	Teacher t1;
	t1.age = 100;

	cout << t1.age << endl;

	system("pause");
	return;
}