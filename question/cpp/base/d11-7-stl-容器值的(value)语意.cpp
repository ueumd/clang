#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

class Teacher117
{
public:
	Teacher117(char *name, int age)
	{
		m_pname = new char[strlen(name) + 1];
		strcpy(m_pname, name);
		m_age = age;
	}
	//Teacher117 t2=t1;
	Teacher117(const Teacher117 &obj)
	{
		m_pname = new char[strlen(obj.m_pname)+1];
		strcpy(m_pname, obj.m_pname);
		m_age = obj.m_age;
	}

	//���� =�Ų�����
	Teacher117& operator=(const Teacher117 &obj)
	{
		//�Ȱ�T2�ľ��ڴ��ͷŵ� ����t1�Ĵ�С�����ڴ� copy t1������
		if (m_pname != NULL)
		{
			delete[] m_pname;
			m_pname = NULL;
			m_age = 0;
		}

		m_pname = new char[strlen(obj.m_pname) + 1];
		strcpy(m_pname, obj.m_pname);
		m_age = obj.m_age;
		return *this;
	}

	~Teacher117()
	{
		if (m_pname != NULL)
		{
			delete[] m_pname;
			m_pname = NULL;
			m_age = 0;
		}
	}
	void printT()
	{
		cout << m_pname << "\t" << m_age << endl;
	}

private:
	char *m_pname;
	int  m_age;
};

int main1171()
{

	Teacher117 t1("t1", 18);
	t1.printT();

	vector<Teacher117> v1;
	v1.push_back(t1);//��t1������һ�� �浽��������... �����Ұָ�룬������� 
	
	/*
	�������
	ʵ���޲ι��캯
	ʵ�ֿ������캯��
	����=������
	*/

	cout << "hello..." << endl;

	system("pause");
	return 0;
}