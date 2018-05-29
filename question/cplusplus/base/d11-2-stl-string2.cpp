#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
using namespace std;

void string1()
{
	string s1 = "aaaa";
	string s2("bbb");
	string s3 = s2;
	string s4(10, 'a');

	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;
	cout << "s4: " << s4 << endl;
}

//遍历
void stringbl()
{
	string s1 = "abcdefg";
	int i = 0, len = s1.length();
	for (i = 0; i < len; i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;
	for (string::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	try
	{
		for (i = 0; i < len + 3; i++)
		{
			//cout << s1[i] << " "; //程序直接会终止 不抛出异常
		}
	}
	catch (...)
	{
		cout << "发生异常\n";
	}
	cout << endl;
	try
	{
		for (i = 0; i < len+3; i++)
		{
			cout << s1.at(i) << " "; //at可以抛出异常
		}
	}
	catch (...)
	{
		cout << "发生异常\n";
	}
	
	
}

//字符指针和string的转换
void charPointerToString()
{
	string s1 = "abcd";

	//s1===>char *

	printf("s1:%s\n", s1.c_str());

	//char * ===>string

	//s1的内容copy buf中
	char buf1[128] = {0};
//	s1.copy(buf1, 3, 0); //从0位置开始拷贝3个字符 不会变成C风格字符串 没有"\0"

	cout << "buf1: " << buf1 << endl;


}


void stringConact()
{
	string s1 = "aaa";
	string s2 = "bbb";

	s1 = s1 + s2;
	cout <<"s1: " << s1 << endl; //aaabbb

	string s3 = "333";
	string s4 = "444";

	s3.append(s4);

	cout << "s3: " << s3 << endl; //333444
}

void stringFindAndRepalce()
{
	string s1 = "htts://www.hfjy.com//tt/hfjy";

	cout << s1 << endl;

	//求hfjy出现的次数
	int offindex = s1.find("hfjy", 0);
	while (offindex != string::npos) //!=-1
	{
		cout << "offindex: " << offindex << endl;
		offindex = offindex + 4;
		offindex = s1.find("hfjy", offindex);
	}

	offindex = s1.find("hfjy", 0);
	while (offindex != string::npos) //!=-1
	{
		cout << "offindex: " << offindex << endl;
		s1.replace(offindex, 4, "HFJY");
		offindex = offindex + 4;
		offindex = s1.find("hfjy", offindex);
	}

	cout << "s1替换后的结果: " << s1 << endl;//htts://www.HFJY.com//tt/HFJY

}

void stringRemoveAndIsert()
{
	string s1 = "hello world hello1 hello2 world2";
	string::iterator it = find(s1.begin(), s1.end(), 'w'); //找到w 删除
	if (it != s1.end())
	{
		s1.erase(it);
	}
	cout << s1 << endl;

	string s2 = "bbb";
	s2.insert(0, "AAA");
	s2.insert(s2.length(), "CCC");//尾部插入
	cout << s2 << endl; //AAABBB
}

void stringTransform()
{
	string s1 = "AAAbbb";
	//函数入口地址 toupper预定义的函数
	transform(s1.begin(), s1.end(), s1.begin(), toupper);
	cout << s1 << endl; //AAABBB

	string s2 = "AAAbbb";
	transform(s1.begin(), s1.end(), s2.begin(),tolower);
	cout << s2 << endl;//aaabbb
}

int main1112()
{
	//string1();
	//stringbl();

	//charPointerToString();

	///stringConact();

	//stringFindAndRepalce();

	//stringRemoveAndIsert();

	stringTransform();
	cout << "hello..." << endl;

	system("pause");
	return 0;
}