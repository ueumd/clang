#include "iostream"
#include "deque"
#include "stack"
#include "list"
#include "algorithm"
using namespace std;


void deque123()
{
	deque<int> v1;

	cout << "length:" << v1.size() << endl;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	cout << "length:" << v1.size() << endl;

	cout << v1.front() << endl;

}

void stack123()
{
	stack<int> s; //先进后出
	for (int i = 0; i < 10; i++)
	{
		s.push(i + 1);
	}

	//出栈
	while (!s.empty())
	{
		int tmp = s.top();//获取栈顶元素
		cout << tmp << " ";
		s.pop();	//弹出栈顶元素
	}
}

class StatckTeacher
{
public:
	int age;
	char name[32];
	void printT()
	{
		cout << "age: " << age << endl;
	}

};

void statckTeacherTest()
{
	StatckTeacher t1, t2, t3;
	t1.age = 10;
	t2.age = 18;
	t3.age = 20;

	stack<StatckTeacher> s;
	s.push(t1);
	s.push(t2);
	s.push(t3);

	while (!s.empty())
	{
		StatckTeacher tmp = s.top();
		tmp.printT();
		s.pop();
	}
}

void list1()
{
	list<int> l;
	cout << l.size() << endl;
	for (int i = 0; i < 10; i++)
	{
		l.push_back(i++);
	}
	cout << l.size() << endl;

	list<int>::iterator it = l.begin();
	while(it != l.end())
	{
		cout << *it << " ";
		it ++;
	}

}

int main1141()
{

	//deque123();
	//stack123();
	//statckTeacherTest();

	list1();

	cout << "hello..." << endl;

	system("pause");
	return 0;
}