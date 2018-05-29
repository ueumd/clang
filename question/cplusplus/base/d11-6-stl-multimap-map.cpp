#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "map"
#include "string"

#include<functional>
using namespace std;

void map1()
{
	map<int, string> map1;
	//1
	map1.insert(pair<int, string>(1, "tea1"));
	map1.insert(pair<int, string>(2, "tea2"));

	//2
	map1.insert(make_pair<int, string>(3, "tea3"));
	map1.insert(make_pair<int, string>(4, "tea4"));

	//3
	map1.insert(map<int, string>::value_type(5,"tea5"));

	pair<map<int, string>::iterator,bool> mypair5=map1.insert(map<int, string>::value_type(10, "tea5"));

	if (mypair5.second != true)
	{
		cout << "key 5 ����ʧ��" << endl;
	}
	else
	{
		cout << mypair5.first->first << endl;
	}

	//4
	map1[6] = "tea6";
	map1[7] = "tea7";

	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); it++)
	{
		cout << it->first << "\t" << it->second << endl;
	}


	map<int, string>::iterator it2 = map1.find(7);

	cout << "��ʼ����" << endl;
	if (it2 == map1.end())
	{
		cout << "key 100��ֵ������" << endl;
	}
	else
	{
		cout << it2->first << "\t" << it2->second << endl;
	}

	//equal_range
	//�쳣����
	pair<map<int, string>::iterator, map<int, string>::iterator> mypair = map1.equal_range(11);//�������������� �γ�һ��pair 
	//��һ��������>=5�� λ��  �ڶ���=5�� λ��

	if (mypair.first == map1.end())
	{
		cout << "��һ��������>=5������" << endl;
	}
	else
	{
		cout << mypair.first->first << "\t" << mypair.first->second << endl;
	}

}

class Person116
{
public :
	string name;
	int age;
	string tel;
	double saly;
};
void mutilmap()
{
	Person116 p1, p2, p3, p4, p5;
	p1.name = "��1";
	p1.age = 18;

	p2.name = "��2";
	p2.age = 19;

	p3.name = "��3";
	p3.age = 20;

	p4.name = "��4";
	p4.age = 21;

	p5.name = "��5";
	p5.age = 22;


	multimap<string, Person116> map2;

	//sale����
	map2.insert(make_pair("sale", p1));
	map2.insert(make_pair("sale", p2));

	//development
	map2.insert(make_pair("development", p3));
	map2.insert(make_pair("development", p4));

	//Finanical����
	map2.insert(make_pair("finanical", p5));

	for (multimap<string, Person116>::iterator it = map2.begin(); it != map2.end(); it++)
	{
		cout << it->first << "\t" << it->second.name << endl;
	}

	cout << endl;

	//��������ʾ 

	cout << "development����������" << map2.count("development") << endl;

	multimap<string, Person116>::iterator it2 = map2.find("development");
	int tag = 0;
	int num2 = map2.count("development");

	while (it2 != map2.end() && tag < num2)
	{
		cout << it2->first << "\t" << it2->second.name << endl;
		it2++;
		tag++;
	}

}

int main1161()
{
	//map1();

	mutilmap();

	cout << "hello..." << endl;

	system("pause");
	return 0;
}