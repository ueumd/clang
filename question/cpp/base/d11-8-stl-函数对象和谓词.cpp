#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "vector"
#include "string"
#include "set"
#include "algorithm"
using namespace std;

template <typename T>
//一元函数对（一个参数）
class ShowElment
{
public:
	ShowElment()
	{
		n = 0;
	}
	void operator()(T &t)
	{
		n++;
		cout << t << " ";
	}
	void printN()
	{
		cout << "n: " << n << endl;
	}
private:
	int n;
};

//函数模版 
template <typename T>
void FuncShowElement(T &t)
{
	cout << t << endl;
}

//普通函数
void FuncShowElement2(int &t)
{
	cout << t << endl;
}


void func1()
{
	int a = 10;
	ShowElment<int> showElement;
	showElement(a); //函对象的()执行 很像一个函数 //仿函数 

	FuncShowElement<int>(a);

	FuncShowElement2(a);
}

//函数对象是属于类对象，能突破函数的概念，能保持调用状态信息
//函数对象的好处
void func2()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	//遍历
	for_each(v1.begin(), v1.end(), ShowElment<int>()); //匿名仿函数对象
	cout << endl;
	for_each(v1.begin(), v1.end(), FuncShowElement2);//通过回调函数 

	ShowElment<int> show1;
	//for_each(v1.begin(), v1.end(), show1);//值传递 不是引用传递 
	//show1.printN();//0

	show1 = for_each(v1.begin(), v1.end(), show1);//能过for_eachr 返回值看n
	show1.printN();//3 

	//结论： 要分清楚stl算法返回的值是迭代器 还是是函数对象（谓词）
}

struct CompareNoCase
{
	bool operator()(const string &str1, const string &str2)
	{
		string str1_;
		str1_.resize(str1.size() );
		transform(str1.begin(), str1.end(), str1_.begin(), tolower);

		string str2_;
		str2_.resize(str2.size());
		transform(str2.begin(), str2.end(), str2_.begin(), tolower);

		return (str1_ < str2_);
	}
};

void func3()
{
	set<string> set1;
	set1.insert("aaa");
	set1.insert("bbb");
	set1.insert("ccc");

	set<string>::iterator it = set1.find("AAA");
	if (it == set1.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << *it << endl;
	}

	//二元谓词在SET集合中的应用
	set<string, CompareNoCase> set2;
	set2.insert("aaa");
	set2.insert("bbb");
	set2.insert("ccc");
	set<string, CompareNoCase>::iterator it2 = set2.find("AAA");

	if (it2 == set2.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout <<"不区分大小写查找："<< *it2 << endl;
	}

}

int maind118stl()
{
	//func1();
	func2();

	func3();

	cout << "hello..." << endl;

	system("pause");
	return 0;
}