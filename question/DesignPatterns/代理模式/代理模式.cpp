#include<iostream>
using namespace std;
/*
Proxy模式又叫做代理模式，是构造型的设计模式之一，它可以为其他对象提供一种代理（Proxy）以控制对这个对象的访问。
所谓代理，是指具有与代理元（被代理的对象）具有相同的接口的类，客户端必须通过代理与被代理的目标类交互，而代理一般在交互的过程中（交互前后），进行某些特别的处理。

提示：a中包含b类；a、b类实现协议类protocol
*/

//协义类
class Subject {
public:
	virtual void sailbook() = 0;
};

//b类
class RealSubjectBook :public Subject {
public:
	virtual void sailbook() {
		cout << "sail book" << endl;
	}
};

//a类
class TaobaoProxy:public Subject {
public:
	virtual void sailbook() {
		m_realSubjectBook = new RealSubjectBook();
		dazhe();
		m_realSubjectBook->sailbook();
		delete m_realSubjectBook;
	}

	void dazhe() {
		cout << "双十一打折" << endl;
	}

private:
	RealSubjectBook *m_realSubjectBook;
};

void main() {
	//直接卖书
	Subject *s = new RealSubjectBook;
	s->sailbook();

	//Taobao代理卖书 
	s = new TaobaoProxy;
	s->sailbook();

	delete s;

	cin.get();
}