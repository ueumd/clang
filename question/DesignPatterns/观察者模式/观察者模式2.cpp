#include<iostream>
#include<list>
using namespace std;

/*
������
һ�����⣨�εΣ�
�����۲��ߣ�Jack Ma & Pony����

ͨ�� attach() �����Ǽ�����˾�����С����� setPrice(12.5)��
֪ͨ�����𲽼�Ϊ 12.5 Ԫ��
�����أ�˾��XX��������ԭ����ְ�� - detach() ע��������
�۸��ٴ��ϵ����ǡ��ǡ��� setPrice(15.0)������
*/

// ����۲��� �ṩһ�� Update() �ӿڣ����ڸ��¼۸�
class IObserver {
public:
	virtual void Update(float price) = 0; //���¼۸�
};

// ��������
class ISubject
{
public:
	virtual void Attach(IObserver *) = 0;	//ע��۲���
	virtual void Detach(IObserver *) = 0; //ע���۲���
	virtual void Notify() = 0;						//֪ͨ�۲���
};


//��������ľ���ʵ�֣����ڹ������еĹ۲��ߣ�
class ConcreteSubject :public ISubject {
public:
	ConcreteSubject() {
		m_fPrice = 10.0;
	}

	void SetPrice(float price) {
		m_fPrice = price;
	}

	virtual void Attach(IObserver *observer) {
		m_observers.push_back(observer);
	}
	virtual void Detach(IObserver *observer) {
		m_observers.remove(observer);
	}

	//֪ͨ����ע��Ĺ۲���
	virtual void Notify() {
		list<IObserver *>::iterator it = m_observers.begin();
		while (it != m_observers.end()) {
			(*it)->Update(m_fPrice);
			++it;
		}
	}

private:
	list<IObserver *> m_observers;	//�۲����б�
	float m_fPrice;									//�۸�
};


// ����۲���
class ConcreteObserver : public IObserver{
public:
	ConcreteObserver(char *name) :m_strName(name) {}

	void Update(float price) {
		cout << m_strName << " - price: " << price << "\n";
	}

private:
	char *m_strName;  // ����
};

//���������Լ���Ӧ�Ĺ۲��ߣ�����ӹ۲��߲����¼۸�

void main() {
	//��������
	ConcreteSubject *pSubject = new ConcreteSubject();

	//�����۲���
	IObserver *p1 = new ConcreteObserver("Jack Ma");
	IObserver *p2 = new ConcreteObserver("Pony");

	pSubject->Attach(p1);
	pSubject->Attach(p2);


	// ���ļ۸񣬲�֪ͨ�۲���
	pSubject->SetPrice(12.5);
	pSubject->Notify();

	/*
	Jack Ma - price: 12.5
	Pony - price: 12.5
	*/

	// ע���۲���
	pSubject->Detach(p2);

	pSubject->SetPrice(15.0);
	pSubject->Notify(); //Jack Ma  - price: 15


	delete p1;
	delete p2;
	delete pSubject;

	cin.get();


}