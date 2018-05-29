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

//����
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
			//cout << s1[i] << " "; //����ֱ�ӻ���ֹ ���׳��쳣
		}
	}
	catch (...)
	{
		cout << "�����쳣\n";
	}
	cout << endl;
	try
	{
		for (i = 0; i < len+3; i++)
		{
			cout << s1.at(i) << " "; //at�����׳��쳣
		}
	}
	catch (...)
	{
		cout << "�����쳣\n";
	}
	
	
}

//�ַ�ָ���string��ת��
void charPointerToString()
{
	string s1 = "abcd";

	//s1===>char *

	printf("s1:%s\n", s1.c_str());

	//char * ===>string

	//s1������copy buf��
	char buf1[128] = {0};
//	s1.copy(buf1, 3, 0); //��0λ�ÿ�ʼ����3���ַ� ������C����ַ��� û��"\0"

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

	//��hfjy���ֵĴ���
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

	cout << "s1�滻��Ľ��: " << s1 << endl;//htts://www.HFJY.com//tt/HFJY

}

void stringRemoveAndIsert()
{
	string s1 = "hello world hello1 hello2 world2";
	string::iterator it = find(s1.begin(), s1.end(), 'w'); //�ҵ�w ɾ��
	if (it != s1.end())
	{
		s1.erase(it);
	}
	cout << s1 << endl;

	string s2 = "bbb";
	s2.insert(0, "AAA");
	s2.insert(s2.length(), "CCC");//β������
	cout << s2 << endl; //AAABBB
}

void stringTransform()
{
	string s1 = "AAAbbb";
	//������ڵ�ַ toupperԤ����ĺ���
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