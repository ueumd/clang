#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#include "string.h"

MyString::MyString()
{
	m_len = 0;
	m_p = new char[m_len + 1];
	strcpy(m_p, "");
}

MyString::MyString(const char *p)
{
	if (p == NULL)
	{
		m_len = 0;
		m_p = new char[m_len + 1];
		strcpy(m_p, "");
	} 
	else
	{
		m_len = strlen(p);
		m_p = new char[m_len + 1];
		strcpy(m_p, "");
	}
}

MyString::MyString(const MyString& s)
{
	m_len = s.m_len;
	m_p = new char[m_len + 1];
	strcpy(m_p, s.m_p);
}



MyString::~MyString()
{
	if (m_p != NULL)
	{
		delete [] m_p;
		m_p = NULL;
		m_len = 0;
	}
}
