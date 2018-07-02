#include <iostream>
using namespace std;
#include "string"

class MememTo
{
public:
	MememTo(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	void setName(string name)
	{
		this->m_name = name;
	}
	string getName()
	{
		return m_name;
	}
	void setAge(int  age)
	{
		this->m_age = age;
	}
	int getAge()
	{
		return m_age;
	}
protected:
private:
	string	m_name;
	int		m_age;
};

class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	void setName(string name)
	{
		this->m_name = name;
	}
	string getName()
	{
		return m_name;
	}
	void setAge(int  age)
	{
		this->m_age = age;
	}
	int getAge()
	{
		return m_age;
	}
	void printT()
	{
		cout << "name: " << m_name << "age: " << m_age << endl;
	}

public:

	//��������
	MememTo *createMememTo()
	{
		return new MememTo(m_name, m_age);
	}

	//�ָ�����
	void SetMememTo(MememTo *memto)
	{
		m_name = memto->getName();
		m_age = memto->getAge();
	}

protected:
private:
	string	m_name;
	int		m_age;

};

//������
class Caretaker
{
public:
	Caretaker(MememTo *mem)
	{
		this->m_memto = mem;
	}
	MememTo *getMememTo()
	{
		return m_memto;
	}
	void setMememTo(MememTo *mem)
	{
		this->m_memto = mem;
	}
protected:
private:
	MememTo *m_memto;
};

void main23_01()
{
	Person *p = new Person("����", 18);
	p->printT();

	//��������
	Caretaker *ct = new Caretaker(p->createMememTo());

	p->setAge(28);
	p->printT();

	//�ָ���Ϣ
	p->SetMememTo(ct->getMememTo());
	p->printT();

	delete p;
	delete ct->getMememTo();

	return;
}

void main23_02()
{
	Person *p = new Person("����", 18);
	p->printT();

	//��������
	MememTo * membak = p->createMememTo();
	p->setAge(28);
	p->printT();

	//�ָ���Ϣ
	p->SetMememTo(membak);
	p->printT();

	delete p;
	delete membak;
}

void main()
{
	//main23_01();
	main23_02();
	system("pause");
}
