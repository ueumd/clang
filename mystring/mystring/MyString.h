#pragma once
using namespace std;
/*
	c��û���ַ����� (c�����ַ���)
*/
class MyString
{
public:
	MyString();
	MyString(const char *p);
	MyString(const MyString& s);
	~MyString();
private:
	int m_len;
	char *m_p;
};

