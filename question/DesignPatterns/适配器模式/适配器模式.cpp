#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

/*
通过Adapter模式可以改变已有类（或外部类）的接口形式。

适用于：

是将一个类的接口转换成客户希望的另外一个接口。使得原本由于接口不兼容而不能一起工作的那些类可以一起工作。

*/


class Current18v {
public:
	void use18vCureent() {
		cout << "使用18v的交流电" << endl;
	}
};

class Current220v
{
public:
	void use220vCurrent()
	{
		cout << "使用220v的交流电" << endl;
	}
};

//
class Adapter :public Current18v {
public:
	Adapter(Current220v *p) {
		m_p220v = p;
	}
	void use18vCureent() {
		cout << "adapter中使用电流" << endl;
		m_p220v->use220vCurrent();
	}
private:
	Current220v * m_p220v;
};

void main() {
	Current220v *p220v = new Current220v;

	Adapter *padapter = new Adapter(p220v);
	padapter->use18vCureent();

	cin.get();
}