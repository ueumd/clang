#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#include "string.h"

ostream& operator<<(ostream &out, MyString &s)
{
	out << s.m_p;
	return cout;
}

istream& operator>>(istream &in, MyString &s)
{
	cin >> s.m_p;
	return in;
}

MyString::MyString(int len)
{
	if (len == 0)
	{
		m_len = 0;
		m_p = new char[m_len + 1];
		strcpy(m_p, "");
	}
	else
	{
		m_len = len;
		m_p = new char[m_len + 1];
		memset(m_p, 0, m_len);
	}
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
		strcpy(m_p, p);
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
// sc="s2222"
MyString& MyString::operator=(const char *p)
{
	//���ڴ��ͷ�
	if (m_p != NULL)
	{
		delete[] m_p;
		m_len = 0;
	}

	//����P�����ڴ�
	if (p == NULL)
	{
		m_len = 0;
		m_p = new char[m_len + 1];
		strcpy(m_p, "");
	}
	else
	{
		m_len =strlen(p);
		m_p = new char[m_len + 1];
		strcpy(m_p, p);
	}

	return *this;//����
}

//s4=s2
MyString& MyString::operator=(const MyString &s)
{
	//���ڴ��ͷ�
	if (m_p != NULL)
	{
		delete[] m_p;
		m_len = 0;
	}

	//����s�����ڴ�
	m_len = s.m_len;
	m_p = new char[m_len + 1];
	strcpy(m_p, s.m_p);

	return *this;

}

char& MyString::operator[] (int index)
{
	return m_p[index];
}



//if (s2 == "s222222")
bool MyString::operator==(const char *p) const
{
	if (p == NULL)
	{
		if (m_len == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (m_len == strlen(p))
		{
			return !strcmp(m_p, p); //��ȷ��ص���0 ��0 true
		}
		else
		{
			return false;
		}
	}
}

bool MyString::operator!=(const char *p)  const
{
	return !(*this == p);
}

//s2=s3
bool MyString::operator==(const MyString& s) const
{
	if (m_len != s.m_len)
	{
		return false;
	}
	return  !strcmp(m_p, s.m_p);

}

bool MyString::operator!=(const MyString& s) const
{
	return !(*this == s);
}

//s3 < "bbb"
int MyString::operator<(const char *p)
{
	return strcmp(this->m_p, p);
}

int MyString::operator>(const char *p)
{
	return strcmp(p, this->m_p);
}

int MyString::operator<(const MyString& s)
{
	return strcmp(this->m_p, s.m_p);
}

int MyString::operator>(const MyString& s)
{
	return strcmp(s.m_p, m_p);
}
