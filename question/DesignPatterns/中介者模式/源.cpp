#include <iostream>
using namespace std;
#include "string"

class Person
{
public:
	Person(string name, int sex, int condit)
	{
		m_name = name;
		m_sex = sex;
		m_condition = condit;
	}

	string getName()
	{
		return m_name;
	}

	int getSex()
	{
		return m_sex;
	}

	int getCondit()
	{
		return m_condition;
	}

	virtual void getParter(Person *p) = 0;

protected:
	string	m_name;	//
	int		m_sex; //1��  2Ů
	int		m_condition; //123456789;
};


class Man : public Person
{
public:
	Man(string name, int sex, int condit) :Person(name, sex, condit)
	{
		;
	}
	virtual void getParter(Person *p)
	{
		if (this->getSex() == p->getSex())
		{
			cout << "No No No �Ҳ���ͬ����" << endl;
		}
		if (this->getCondit() == p->getCondit())
		{
			cout << this->getName() << " �� " << p->getName() << "����" << endl;
		}
		else
		{
			cout << this->getName() << " �� " << p->getName() << "����" << endl;
		}
	}
protected:

};

class Woman : public Person
{
public:
	Woman(string name, int sex, int condit) :Person(name, sex, condit)
	{
		;
	}
	virtual void getParter(Person *p)
	{
		if (this->getSex() == p->getSex())
		{
			cout << "No No No �Ҳ���ͬ����" << endl;
		}
		if (this->getCondit() == p->getCondit())
		{
			cout << this->getName() << " �� " << p->getName() << "����" << endl;
		}
		else
		{
			cout << this->getName() << " �� " << p->getName() << "����" << endl;
		}
	}
protected:

};

//����  Woman  Man���̫������Ҫ�����
void main1901()
{

	Woman *w1 = new Woman("С��", 2, 4);
	Man *m1 = new Man("����", 1, 3);
	Man *m2 = new Man("����", 1, 4);

	w1->getParter(m1);
	w1->getParter(m2);

	delete w1;
	delete m1;
	delete m2;

	return;
}

class Mediator;
class Person2
{
public:
	Person2(string name, int sex, int condition, Mediator *m){
		m_name = name;
		m_sex = sex;
		m_condition = condition;
		m_m = m;
	}

	string getName(){
		return m_name;
	}

	int getSex(){
		return m_sex;
	}

	int getCondit(){
		return m_condition;
	}

	Mediator *getMediator(){
		return m_m;
	}

public:
	virtual void getParter(Person2 *p) = 0;

protected:
	string	m_name;	//
	int		m_sex; //1��  2Ů
	int		m_condition; //123456789;
	Mediator *m_m;
};


class Mediator
{
public:
	Mediator()
	{
		pMan = NULL;
		pWoman = NULL;
	}
	void setWoman(Person2 *p)
	{
		pWoman = p;
	}
	void setMan(Person2 *p)
	{
		pMan = p;
	}

	void getPartner(){
		if (pMan->getSex() == pWoman->getSex())
		{
			cout << "No No No �Ҳ���ͬ����" << endl;
		}
		if (pMan->getCondit() == pWoman->getCondit())
		{
			cout << pMan->getName() << " �� " << pWoman->getName() << "����" << endl;
		}
		else
		{
			cout << pMan->getName() << " �� " << pWoman->getName() << "����" << endl;
		}
	}

protected:
private:
	Person2	*pMan;
	Person2	*pWoman;
};

class Woman2 : public Person2
{
public:
	Woman2(string name, int sex, int condition, Mediator *m) : Person2(name, sex, condition, m)
	{
		;
	}
	virtual void getParter(Person2 *p)
	{
		this->getMediator()->setWoman(this);
		this->getMediator()->setMan(p);
		this->getMediator()->getPartner();
	}
private:
};

class Man2 : public Person2
{
public:
	Man2(string name, int sex, int condition, Mediator *m) : Person2(name, sex, condition, m)
	{
		;
	}
	virtual void getParter(Person2 *p)
	{
		this->getMediator()->setMan(this);
		this->getMediator()->setWoman(p);
		this->getMediator()->getPartner();
	}
private:
};

void main1902()
{
	Mediator *mediator = new Mediator;
	Woman2 *w1 = new Woman2("С��", 2, 4, mediator);
	Man2 *m1 = new Man2("����", 1, 3, mediator);
	Man2 *m2 = new Man2("����", 1, 4, mediator);

	w1->getParter(m1);
	w1->getParter(m2);

	delete w1;
	delete m1;
	delete m2;
	delete mediator;
}
void main()
{
	//main1901(); //���������
	main1902(); //���н���ģʽ�����Ż�
	system("pause");
}
