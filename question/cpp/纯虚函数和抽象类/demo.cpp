#include "iostream"
using namespace std;

/*
计算程序员(Programmer)工资
1 要求能计算出 初程序员(JuniorProgramer) 中级程序员（MidProgramer） 高级程序员（AdvProgramer）的工资
2 要求利用抽像类统一界面，方便程序的扩展， 比如：新增 架构师(Architect)的工资
*/

//程序员
class Programmer
{
public:
	virtual void getSal() = 0;
};

// 初级程序员
class JuniorProgramer : public Programmer
{
public:
	JuniorProgramer(char *name, char *job, int sal)
	{
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void getSal()
	{
		cout << name << " " << job << " " << sal << endl;
	}
private:
	char *name;
	char *job;
	int sal;
};

//中级程序员
class MidProgramer : public Programmer
{
public:
	MidProgramer(char *name, char *job, int sal)
	{
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void getSal()
	{
		cout << name << " " << job << " " << sal << endl;
	}
private:
	char *name;
	char *job;
	int sal;
};

//高级程序员
class AdvProgramer : public Programmer
{
public:
	AdvProgramer(char *name, char *job, int sal)
	{
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void getSal()
	{
		cout << name << " " << job << " " << sal << endl;
	}
private:
	char *name;
	char *job;
	int sal;
};

//架构师
class Architect : public Programmer
{
public:
	Architect(char *name, char *job, int sal)
	{
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void getSal()
	{
		cout << name << " " << job << " " << sal << endl;
	}
private:
	char *name;
	char *job;
	int sal;
};

// 多态
void CalProgSal(Programmer *base)
{
	base->getSal();
}

void maind74()
{

	JuniorProgramer jp("小王", "初级", 8000);
	MidProgramer    mp("小张", "中级", 1000);
	AdvProgramer    ap("小李", "中级", 2000);

	//系统扩展
	Architect       ar("扫地僧", "架构师", 30000);

	CalProgSal(&jp);
	CalProgSal(&mp);
	CalProgSal(&ap);
	CalProgSal(&ar);

	cout << "hello..." << endl;

	system("pause");
	return;
}