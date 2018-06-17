#include "iostream"
using namespace std;

/*
�������Ա(Programmer)����
1 Ҫ���ܼ���� ������Ա(JuniorProgramer) �м�����Ա��MidProgramer�� �߼�����Ա��AdvProgramer���Ĺ���
2 Ҫ�����ó�����ͳһ���棬����������չ�� ���磺���� �ܹ�ʦ(Architect)�Ĺ���
*/

//����Ա
class Programmer
{
public:
	virtual void getSal() = 0;
};

// ��������Ա
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

//�м�����Ա
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

//�߼�����Ա
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

//�ܹ�ʦ
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

// ��̬
void CalProgSal(Programmer *base)
{
	base->getSal();
}

void maind74()
{

	JuniorProgramer jp("С��", "����", 8000);
	MidProgramer    mp("С��", "�м�", 1000);
	AdvProgramer    ap("С��", "�м�", 2000);

	//ϵͳ��չ
	Architect       ar("ɨ��ɮ", "�ܹ�ʦ", 30000);

	CalProgSal(&jp);
	CalProgSal(&mp);
	CalProgSal(&ap);
	CalProgSal(&ar);

	cout << "hello..." << endl;

	system("pause");
	return;
}