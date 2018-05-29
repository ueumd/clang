
#include "iostream"
using namespace std; //iostream没有引入标准的 std 需要手工写



//定义命名这间

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

	//如果上面没有写 using namespace std;需要显示的引入std
	//std::cout << "namespace test" << std::endl; 


	//使用命名空间

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