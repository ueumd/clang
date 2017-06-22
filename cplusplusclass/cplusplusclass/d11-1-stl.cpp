#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;


void vectorTest()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(-1);
	v1.push_back(2);

	//迭代器 相当于一个指针
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " "; //1 2 3
	}

	//算法 算法和迭代器无缝连接
	int num1 = count(v1.begin(), v1.end(), 2); //等于2 的有几个

	cout << "num1: " << num1 << endl;

}

class TeacherVec
{
public:
	void printT()
	{
		cout << "age: " << age << endl;
	}
	int age;
	char name[64];

};

void vectorTeacher()
{
	TeacherVec t1, t2, t3;
	t1.age = 10;
	t2.age = 18;
	t3.age = 20;

	vector<TeacherVec> v1;
	v1.push_back(t1);
	v1.push_back(t2);
	v1.push_back(t3);

	for (vector<TeacherVec>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << it->age << " ";
	}
}

void vectorTeacherPointer()
{
	TeacherVec t1, t2, t3;
	t1.age = 10;
	t2.age = 18;
	t3.age = 20;

	TeacherVec *p1, *p2, *p3;

	p1 = &t1;
	p2 = &t2;
	p3 = &t3;


	vector<TeacherVec *> v1; //容器：把t1 t2 t3内存首地址 放到容器
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);

	for (vector<TeacherVec *>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		//指针
		cout << (*it)->age << " ";
	}
}

int main1111()
{
	vectorTest();
	vectorTeacher();
	vectorTeacherPointer();
	cout << "hello..." << endl;

	system("pause");
	return 0;
}