/*
典型应用
- 侦听事件驱动程序设计中的外部事件
- 侦听/监视某个对象的状态变化
- 发布者/订阅者(publisher/subscriber)模型中，当一个外部事件（新的产品，消息的出现等等）被触发时，通知邮件列表中的订阅者
适用于：
定义对象间一种一对多的依赖关系，使得每一个对象改变状态，则所有依赖于他们的对象都会得到通知。

使用场景：定义了一种一对多的关系，让多个观察对象（公司员工）同时监听一个主题对象（秘书），主题对象状态发生变化时，会通知所有的观察者，使它们能够更新自己。
*/

#include <iostream>
#include "vector"
#include "string"
using namespace std;

class Secretary;

//玩游戏的同事类（观察者）
class PlayserObserver{
public:
	PlayserObserver(string name, Secretary *secretary){
		m_name = name;
		m_secretary = secretary;
	}
	void update(string action){
		cout << "观察者收到action:" << action << endl;
	}
private:
	string		m_name;
	Secretary	*m_secretary;
};

//秘书类（主题对象，通知者）
class Secretary {
public:
	void addObserver(PlayserObserver *o){
		v.push_back(o);
	}
	void Notify(string action){
		for (vector<PlayserObserver *>::iterator it = v.begin(); it != v.end(); it++){
			(*it)->update(action);
		}
	}
	void setAction(string action){
		m_action = action;
		Notify(m_action);
	}
private:
	string m_action;
	vector<PlayserObserver *> v;
};

void main1()
{
	//subject 被观察者
	Secretary *s1 = new Secretary;

	//具体的观察者被通知对象
	PlayserObserver *po1 = new PlayserObserver("小张", s1);

	//PlayserObserver *po2 = new PlayserObserver("小李", s1);

	s1->addObserver(po1);
	//s1->addObserver(po2);

	s1->setAction("老板来了");
	s1->setAction("老板走了");
	cout << "hello..." << endl;
	system("pause");
	return;
}
