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

//�м�
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

//�߼�
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

//�����ܹ�ʦ
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

	JuniorProgramer jp("С��", "����", 8000);
	MidProgramer mp("С��", "�м�", 1000);
	AdvProgramer ap("С��", "�м�", 2000);

	//ϵͳ��չ
	Architect ar("ɨ��ɮ", "�ܹ�ʦ", 30000);

	CalProgSal(&jp);
	CalProgSal(&mp);
	CalProgSal(&ap);
	CalProgSal(&ar);

	cout << "hello..." << endl;

	system("pause");
	return;
}