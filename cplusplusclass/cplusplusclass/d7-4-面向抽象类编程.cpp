#include "iostream"

using namespace std;

class Programmer
{
public:
	virtual void getSal() = 0;
};

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

//中级
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

//高级
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

//新增架构师
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

void CalProgSal(Programmer *base) 
{
	base->getSal();
}

void main()
{

	JuniorProgramer jp("小王", "初级", 8000);
	MidProgramer mp("小张", "中级", 1000);
	AdvProgramer ap("小李", "中级", 2000);

	//系统扩展
	Architect ar("扫地僧", "架构师", 30000);

	CalProgSal(&jp);
	CalProgSal(&mp);
	CalProgSal(&ap);
	CalProgSal(&ar);

	cout << "hello..." << endl;

	system("pause");
	return;
}