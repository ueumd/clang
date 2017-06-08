#pragma once
using namespace std;
/*
	c中没有字符串类 (c风格的字符串)
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

