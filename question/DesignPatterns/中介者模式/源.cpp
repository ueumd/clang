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
	int		m_sex; //1男  2女
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
			cout << "No No No 我不是同性恋" << endl;
		}
		if (this->getCondit() == p->getCondit())
		{
			cout << this->getName() << " 和 " << p->getName() << "绝配" << endl;
		}
		else
		{
			cout << this->getName() << " 和 " << p->getName() << "不配" << endl;
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
			cout << "No No No 我不是同性恋" << endl;
		}
		if (this->getCondit() == p->getCondit())
		{
			cout << this->getName() << " 和 " << p->getName() << "绝配" << endl;
		}
		else
		{
			cout << this->getName() << " 和 " << p->getName() << "不配" << endl;
		}
	}
protected:

};

//以上  Woman  Man类的太紧密需要解耦合
void main1901()
{

	Woman *w1 = new Woman("小芳", 2, 4);
	Man *m1 = new Man("张三", 1, 3);
	Man *m2 = new Man("李四", 1, 4);

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
	int		m_sex; //1男  2女
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
			cout << "No No No 我不是同性恋" << endl;
		}
		if (pMan->getCondit() == pWoman->getCondit())
		{
			cout << pMan->getName() << " 和 " << pWoman->getName() << "绝配" << endl;
		}
		else
		{
			cout << pMan->getName() << " 和 " << pWoman->getName() << "不配" << endl;
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
	Woman2 *w1 = new Woman2("小芳", 2, 4, mediator);
	Man2 *m1 = new Man2("张三", 1, 3, mediator);
	Man2 *m2 = new Man2("李四", 1, 4, mediator);

	w1->getParter(m1);
	w1->getParter(m2);

	delete w1;
	delete m1;
	delete m2;
	delete mediator;
}
void main()
{
	//main1901(); //问题的引出
	main1902(); //用中介者模式进行优化
	system("pause");
}
