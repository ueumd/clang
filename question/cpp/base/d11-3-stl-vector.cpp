#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;


void vectort1()
{
	vector<int> v1;

	cout << "length:" << v1.size() << endl;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	cout << "length:" << v1.size() << endl;

	cout << v1.front() << endl;

	//修改头部元素 函数返回值当左值 应该返回一个引用
	v1.front() = 20;

	while (v1.size() > 0)
	{
		cout << v1.back();//获取尾部元素
		v1.pop_back();//删除尾部元素
	}
	cout << endl;
	cout << "length:" << v1.size() << endl; //0

}

void vectorInit()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	vector<int> v2=v1;//对象初始化 vector提供了拷贝构造函数
	vector<int> v3(v1.begin(), v1.begin() + 2);
}

void printVecotr(vector<int> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}

//数组方式遍历 赋值 打印
void vectorfz()
{
	vector<int> v1(10); //用for循环赋值时 必须要内存空间准备好 (10)

	for (int i = 0; i < 10; i++)
	{
		v1[i] = i + 1;
	}
	for (int i = 0; i < 10; i++)
	{
		//cout << v1[i] << " ";
	}

	//迭代器方式打印
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//迭代器方式打印 逆序遍历
	for (vector<int>::reverse_iterator it = v1.rbegin(); it != v1.rend(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	printVecotr(v1);

	cout << endl;

	vector<int> v2(10);
	v2.push_back(100);
	v2.push_back(200);
	//前面初始化10个0 后面再插入100 200
	printVecotr(v2);//0 0 0 0 0 0 0 0 0 0 100 200
}

void vectorRemoveAndInser()
{
	vector<int> v1(10); //用for循环赋值时 必须要内存空间准备好 (10)

	for (int i = 0; i < 10; i++)
	{
		v1[i] = i + 1;
	}

	//区间删除
	v1.erase(v1.begin(), v1.begin() + 3);
	printVecotr(v1);//4 5 6 7 8 9 10

	cout << endl;
	//指定位置删除
	v1.erase(v1.begin());
	printVecotr(v1);//5 6 7 8 9 10
	cout << endl;

	//根据元素的值删除
	v1[1] = 2;
	v1[3] = 2;
	printVecotr(v1);
	cout << endl;
	for (vector<int>::iterator it = v1.begin(); it != v1.end();)
	{
		if (*it == 2) //等于2的全部删除
		{
			it = v1.erase(it);//当 删除迭代器所指向的元素的时候  erase删除函数会让it自动下移动
		}
		else 
		{
			it ++;
		}
	}
	printVecotr(v1);
}

void vectorInsert()
{

	vector<int> v1(10); //用for循环赋值时 必须要内存空间准备好 (10)

	for (int i = 0; i < 10; i++)
	{
		v1[i] = i + 1;
	}

	v1.insert(v1.begin(), 100);
	v1.insert(v1.end(), 200);
	printVecotr(v1);

	cout << endl;
}

int main1131()
{
	//vectort1();
	//vectorfz();

	//vectorRemoveAndInser();

	vectorInsert();
	cout << "hello..." << endl;

	system("pause");
	return 0;
}