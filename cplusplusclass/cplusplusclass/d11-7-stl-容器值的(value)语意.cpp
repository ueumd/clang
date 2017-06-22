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

	//重载 =号操作符
	Teacher117& operator=(const Teacher117 &obj)
	{
		//先把T2的旧内存释放掉 根据t1的大小分配内存 copy t1的数据
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
	v1.push_back(t1);//把t1拷贝了一份 存到容器中了... 会存在野指针，解决方法 
	
	/*
	解决方法
	实现无参构造函
	实现拷贝构造函数
	重载=操作符
	*/

	cout << "hello..." << endl;

	system("pause");
	return 0;
}