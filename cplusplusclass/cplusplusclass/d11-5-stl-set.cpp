#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "deque"
#include "stack"
#include "list"
#include "algorithm"
#include "set"
using namespace std;

/*
默认从小到大 
元素唯一
*/
void set1()
{
	set<int> set1;
	for (int i = 0; i < 5; i++)
	{
		int tmp = rand();
		set1.insert(tmp);
	}

	set1.insert(100);
	set1.insert(100);

	for (set<int>::iterator it = set1.begin(); it != set1.end(); it++)
	{
		cout << *it << " ";
	}
}

//比较元素大小
void set2()
{
	set<int> set1;
	set<int, less<int>> set2; //从小大到

	//set<int, greater<int>> set3; //greater 仿函数

	for (int i = 0; i < 5; i++)
	{
		int tmp = rand();
		set1.insert(tmp);
	}

}

class StudentSet
{
public:
	char name[64];
	int age;

	StudentSet(char *name, int age)
	{
		strcpy(this->name,name);
		this->age = age;
	}
};

//仿函数
struct FuncStudent
{
	bool operator()(const StudentSet &left, const StudentSet &right)
	{
		if (left.age < right.age) //从小到大 按年龄进行排序
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

void set3()
{
	StudentSet s1("s1", 28);
	StudentSet s2("s2", 10);
	StudentSet s3("s3", 18);
	StudentSet s4("s4", 8);
	StudentSet s5("s5", 18); //如果两个18岁能插入成功吗？
	
	set<StudentSet, FuncStudent> set1;

	set1.insert(s1);
	set1.insert(s2);
	set1.insert(s3);
	set1.insert(s4);

	pair<set<StudentSet, FuncStudent>::iterator, bool> pair1 = set1.insert(s1);

	if (pair1.second == true)
	{
		cout << "插入s1成功" << endl;
	}
	else
	{
		cout << "插入s1失败" << endl;
	}



	pair<set<StudentSet, FuncStudent>::iterator, bool> pair5 = set1.insert(s5);

	if (pair5.second == true)
	{
		cout << "插入s5成功" << endl;
	}
	else
	{
		cout << "插入s5失败" << endl;
	}

	

	for (set<StudentSet, FuncStudent>::iterator it = set1.begin(); it != set1.end(); it++)
	{
		cout << it->age << "\t" << it->name << endl;
	}


}

int main()
{
	//set1();
	set3();

	cout << "hello..." << endl;

	system("pause");
	return 0;
}