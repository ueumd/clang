#include<iostream>
#include<list>
using namespace std;

/*
创建了
一个主题（滴滴）
两个观察者（Jack Ma & Pony），

通过 attach() 将他们加入至司机行列。调用 setPrice(12.5)，
通知他们起步价为 12.5 元。
后来呢，司机XX由于种种原因离职了 - detach() 注销。。。
价格再次上调，涨、涨、涨 setPrice(15.0)。。。
*/

// 抽象观察者 提供一个 Update() 接口，用于更新价格：
class IObserver {
public:
	virtual void Update(float price) = 0; //更新价格
};

// 抽象主题
class ISubject
{
public:
	virtual void Attach(IObserver *) = 0;	//注册观察者
	virtual void Detach(IObserver *) = 0; //注消观察者
	virtual void Notify() = 0;						//通知观察者
};


//抽象主题的具体实现，用于管理所有的观察者：
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

	//通知所有注册的观察者
	virtual void Notify() {
		list<IObserver *>::iterator it = m_observers.begin();
		while (it != m_observers.end()) {
			(*it)->Update(m_fPrice);
			++it;
		}
	}

private:
	list<IObserver *> m_observers;	//观察者列表
	float m_fPrice;									//价格
};


// 具体观察者
class ConcreteObserver : public IObserver{
public:
	ConcreteObserver(char *name) :m_strName(name) {}

	void Update(float price) {
		cout << m_strName << " - price: " << price << "\n";
	}

private:
	char *m_strName;  // 名字
};

//创建主题以及对应的观察者，并添加观察者并更新价格：

void main() {
	//创建主题
	ConcreteSubject *pSubject = new ConcreteSubject();

	//创建观察者
	IObserver *p1 = new ConcreteObserver("Jack Ma");
	IObserver *p2 = new ConcreteObserver("Pony");

	pSubject->Attach(p1);
	pSubject->Attach(p2);


	// 更改价格，并通知观察者
	pSubject->SetPrice(12.5);
	pSubject->Notify();

	/*
	Jack Ma - price: 12.5
	Pony - price: 12.5
	*/

	// 注销观察者
	pSubject->Detach(p2);

	pSubject->SetPrice(15.0);
	pSubject->Notify(); //Jack Ma  - price: 15


	delete p1;
	delete p2;
	delete pSubject;

	cin.get();


}