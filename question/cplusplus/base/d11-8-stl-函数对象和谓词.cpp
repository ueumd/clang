#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "vector"
#include "string"
#include "set"
#include "algorithm"
using namespace std;

template <typename T>
//һԪ�����ԣ�һ��������
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

//����ģ�� 
template <typename T>
void FuncShowElement(T &t)
{
	cout << t << endl;
}

//��ͨ����
void FuncShowElement2(int &t)
{
	cout << t << endl;
}


void func1()
{
	int a = 10;
	ShowElment<int> showElement;
	showElement(a); //�������()ִ�� ����һ������ //�º��� 

	FuncShowElement<int>(a);

	FuncShowElement2(a);
}

//���������������������ͻ�ƺ����ĸ���ܱ��ֵ���״̬��Ϣ
//��������ĺô�
void func2()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	//����
	for_each(v1.begin(), v1.end(), ShowElment<int>()); //�����º�������
	cout << endl;
	for_each(v1.begin(), v1.end(), FuncShowElement2);//ͨ���ص����� 

	ShowElment<int> show1;
	//for_each(v1.begin(), v1.end(), show1);//ֵ���� �������ô��� 
	//show1.printN();//0

	show1 = for_each(v1.begin(), v1.end(), show1);//�ܹ�for_eachr ����ֵ��n
	show1.printN();//3 

	//���ۣ� Ҫ�����stl�㷨���ص�ֵ�ǵ����� �����Ǻ�������ν�ʣ�
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
		cout << "û���ҵ�" << endl;
	}
	else
	{
		cout << *it << endl;
	}

	//��Ԫν����SET�����е�Ӧ��
	set<string, CompareNoCase> set2;
	set2.insert("aaa");
	set2.insert("bbb");
	set2.insert("ccc");
	set<string, CompareNoCase>::iterator it2 = set2.find("AAA");

	if (it2 == set2.end())
	{
		cout << "û���ҵ�" << endl;
	}
	else
	{
		cout <<"�����ִ�Сд���ң�"<< *it2 << endl;
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