/*
适用于：
是将一个请求封装为一个对象，从而使你可用不同的请求对客户端进行参数化；对请求排队或记录请求日志，以及支持可撤销的操作。
*/

#include <iostream>  
#include <string>
#include <vector>
using namespace std;

#define SAFE_DELETE(p) if (p) { delete p; p = NULL; }

 /*烤肉师傅类，只负责烤串工作*/
class Barbecuer{
public:
	void BakeMutton() { 
		cout << "Bake mutton" << endl; 
	}
	void BakeChickenWing() { 
		cout << "Bake ChickenWing" << endl; }
};

/*抽象命令类：是执行具体操作的接口*/
class Command{
public:
	Command() {}
	Command(Barbecuer *receiver) :p_receiver(receiver) {
	}
	virtual void ExecuteCommand() = 0; //执行命令
protected:
	Barbecuer *p_receiver;
};

/*具体命令类:烤羊肉串命令*/
class BakeMuttonCommand :public Command
{
public:
	BakeMuttonCommand(Barbecuer *receiver) { 
		p_receiver = receiver; 
	}
	void ExecuteCommand() { 
		p_receiver->BakeMutton();
	}
};

/*具体命令类:烤鸡翅串命令*/
class BakeChickenWingCommand :public Command
{
public:
	BakeChickenWingCommand(Barbecuer *receiver) { 
		p_receiver = receiver; 
	}
	void ExecuteCommand()
	{
		p_receiver->BakeChickenWing();
	}
};

/*服务员类*/
class Waiter
{
public:
	void SetOrder(Command *command);
	void Notify();
private:
	vector<Command *>p_commandList; //这里相当于一个命令对象队列
};

void Waiter::SetOrder(Command *command)
{
	p_commandList.push_back(command);
	cout << "增加烤肉命令" << endl;
}

void Waiter::Notify()
{
	vector<Command*>::iterator i;
	for (i = p_commandList.begin(); i != p_commandList.end(); ++i)
		(*i)->ExecuteCommand();
}

int main(int argc, char *argv[])
{
	//生成烤肉师傅、服务员、订单对象
	Barbecuer *p_cook = new Barbecuer();
	Command *p_mutton = new BakeMuttonCommand(p_cook);
	Command *p_chickenwing = new BakeChickenWingCommand(p_cook);
	Waiter *p_waiter = new Waiter();

	//将订单对象推送到命令队列
	p_waiter->SetOrder(p_mutton);
	p_waiter->SetOrder(p_chickenwing);

	//服务员通知烤肉师傅具体订单
	p_waiter->Notify();

	SAFE_DELETE(p_cook);
	SAFE_DELETE(p_mutton);
	SAFE_DELETE(p_chickenwing);
	SAFE_DELETE(p_waiter);

	return 0;
}