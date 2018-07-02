/*
��Ϊ�й���ѵ�����ʤ�أ������кܶ������ľ��㣺��ʼ�ʱ���ٸ��������������ܽ��԰������ء���/��¥����ɽ���ų�ǽ����ʷ����ݡ�����

�ڷ�������ʱ�������߻�ι۸������㡣���ھ�����˵�����۷�������˭�����Ƕ��ǲ���ġ�����Ϊ�����ߣ���ͬ��ɫ�ķ��ʷ�ʽҲ������ͬ���ο�ֻ�������� - �Ժ����֣�����๤����Ҫ��ɨ����������������

����οͺ���๤�Ǿ�������ߣ�����ٸ����¥�Ⱦ����Ǿ���Ԫ�أ��������������ǽṹ����
*/

#include<iostream>
#include "list"
using namespace std;

/*
�������㣺��¥������ٸ��
*/
class BellTower;
class TerracottaWarriors;

// ������
class IVisitor
{
public:
	virtual ~IVisitor() {}

	//��������ҪΪÿ�����㶼�ṩһ�����ʷ�����
	virtual void Visit(BellTower *) = 0;
	virtual void Visit(TerracottaWarriors *) = 0;
};

/*
�������������

��������������� - �ο͡���๤�����Ƿֱ�ʵ���˲�ͬ�ķ��ʲ������ο�ֻ�ܳԺ����֣���๤����������������
*/

// �ο�
class Tourist : public IVisitor {
public:
	virtual void Visit(BellTower *) override {
		cout << "�οͲι���¥��" << endl;
	}

	virtual void Visit(TerracottaWarriors  *) override {
		cout <<  "�οͲι۱���ٸ��" << endl;
	}
};

// ��๤
class Cleaner : public IVisitor
{
public:
	virtual void Visit(BellTower *) override {
		cout << "��๤������¥��������" << endl;
	}

	virtual void Visit(TerracottaWarriors *) override {
		cout << "��๤�������ٸ��������" << endl;
	}
};

/*
�����ж�����һ�� Accept() �ӿڣ����ڽ��ܷ����ߵķ��ʣ�
*/
class IPlace {
public:
	virtual ~IPlace() {}
	virtual void Accept(IVisitor *visitor) = 0;
};

/*
��������Ԫ��

����Ԫ�������� - ��¥������ٸ������ʵ���� Accept() ������
*/
// ��¥
class BellTower : public IPlace
{
public:
	virtual void Accept(IVisitor *visitor) override {
		cout << "��¥����Ӵ��ο�" << endl;
		visitor->Visit(this);
	}
};

// ����ٸ
class TerracottaWarriors : public IPlace
{
public:
	virtual void Accept(IVisitor *visitor) override {
		cout << "����ٸ����Ӵ��ο�" << endl;
		visitor->Visit(this);
	}
};

/*
��������ṹ
��Ӿ��㣬��Ϊÿһ��������ӷ����ߣ�
*/

class City{
public:
	void Attach(IPlace *place) {
		m_places.push_back(place);
	}

	void Detach(IPlace *place) {
		m_places.remove(place);
	}

	void Accept(IVisitor *visitor) {
		// Ϊÿһ�� element ���� visitor�����ж�Ӧ�Ĳ���
		for (list<IPlace*>::iterator it = m_places.begin(); it != m_places.end(); ++it) {
			(*it)->Accept(visitor);
		}
	}

private:
	list<IPlace *> m_places;
};

int main()
{
	City *city = new City();

	// ���� - ��¥������ٸ
	IPlace *bellTower = new BellTower();
	IPlace *warriors = new TerracottaWarriors();

	// ������ - �ο͡���๤
	IVisitor *tourist = new Tourist();
	IVisitor *cleaner = new Cleaner();

	// ��Ӿ���
	city->Attach(bellTower);
	city->Attach(warriors);

	// ���ܷ���
	city->Accept(tourist);
	city->Accept(cleaner);

	delete cleaner;
	delete tourist;
	delete warriors;
	delete city;

	getchar();

	return 0;
}