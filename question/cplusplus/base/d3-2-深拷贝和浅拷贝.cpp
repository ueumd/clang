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
	//解决方案 ：手工编写拷贝构造函数 使用深拷贝
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
	Name obj2 = obj1;//默认的copy构造函数  c++编译器提供 对象析构的时候 出问题

	Name obj3("aaa");
	obj3 = obj1; // = 等号操作 同样问题 浅拷贝  obj1被析构时 obj3里指向垃圾空间 变成野指针

	Name("adddd"); //会产生一个匿名对象 这个对象外面没有对象接收它
}

void maind32()
{
	
	testName();
	cout << "hello..." << endl;

	system("pause");
	return;
}