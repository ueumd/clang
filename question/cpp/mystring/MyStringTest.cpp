#define _CRT_SECURE_NO_WARNINGS

#include "iostream"
#include "MyString.h"


using namespace std;

struct Work {
	int i = 1;
	Work(int _i) :i (_i) {}
	void operator() (int tt)
	{
		cout <<tt<< endl;
	}
	void operator+(int b)
	{
		cout << b << endl;
	}
};

void testWork()
{
	Work w(123);
	w(987);

}

void main1()
{
	MyString s1;
	MyString s2("s2");
	MyString S2_2 = NULL;
	MyString s3 = s2;
	MyString s4 = "s4444444444444";

	s4 = s2;
	s4 = "s22222";



	s4[1] = 'B';
	printf("%c\n", s4[1]); //����[]

	//	printf("%s\n", s4);
	cout<<s4<< endl; //����

	cout << "hello..." << endl;

	system("pause");
	return;
}

void main2()
{
	MyString s1;
	MyString s2("s2");
	MyString s3 = s2;

	

	if (s2 == "s2bbb")
	{
		printf("���\n");
	}
	else
	{
		printf("�����\n");
	}

	if (s3 == s2)
	{
		printf("���\n");
	}
	else
	{
		printf("�����\n");
	}
	
	cout << "hello..." << endl;
	system("pause");
	return;
}

void main3()
{

	MyString s1;
	MyString s2("s2");
	MyString s3 = s2;

	s3 = "aaa";

	int tag = (s3 < "bbb");

	if (tag<0)
	{
		printf("s3С��bbb\n");
	}
	else
	{
		printf("s3����bbb\n");
	}

	if (s3 < s2)
	{
		printf("s3С��s2\n");
	}
	else
	{
		printf("s3����s2\n");
	}


	MyString s4 = "aaaaffff";
	strcpy(s4.c_str(), "aaaa1111");

	cout << s4 << endl;

	system("pause");
	return;
}

void main()
{
	MyString s1(128);


	cout << "\n�������ַ���";
	cin >> s1; //���� >>
	cout << s1 << endl;

	system("pause");
	return;

}