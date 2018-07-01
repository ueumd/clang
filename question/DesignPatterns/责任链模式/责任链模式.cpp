#if 0
责任链优缺点
优点：
1。责任的分担。每个类只需要处理自己该处理的工作（不该处理的传递给下一个对象完成），明确各类的责任范围，符合类的最小封装原则。
2。可以根据需要自由组合工作流程。如工作流程发生变化，可以通过重新分配对象链便可适应新的工作流程。
3。类与类之间可以以松耦合的形式加以组织。
缺点：
因为处理时以链的形式在对象间传递消息，根据实现方式不同，有可能会影响处理的速度。
适用于：
链条式处理事情。工作流程化、消息处理流程化、事物流程化；

#endif

#include<iostream>
using namespace std;
class CarHandle {
public:
	virtual void HandleCar() = 0;

public:
	/*
	责任链模式 任务处理完，传递下去
	*/
	CarHandle *setNextHandle(CarHandle *carhandle){
		this->carhandle = carhandle;
		return this->carhandle;
	}

protected:
	CarHandle *carhandle;
};

class CarHandleHead :public CarHandle {
public:
	virtual void HandleCar() {
		cout << "处理车头" << endl;

		//造 完车头后 把任务 传递交给 下一个处理者
		if (this->carhandle != NULL) {
			carhandle->HandleCar();
		}
	}
};

class CarHandleBody:public CarHandle {
public:
	virtual void HandleCar() {
		cout << "处理车身" << endl;

		if (this->carhandle != NULL) {
			carhandle->HandleCar();
		}
	}
};

class CarHandleTail :public CarHandle {
public:
	virtual void HandleCar() {
		cout << "处理车尾" << endl;

		if (this->carhandle != NULL) {
			carhandle->HandleCar();
		}
	}
};

void main() {
#if 0
	CarHandleHead *head = new CarHandleHead;
	CarHandleBody *body = new CarHandleBody;
	CarHandleTail *tail = new CarHandleTail;

	//业务逻辑 写死在客户端 不是责任链
	head->HandleCar();
	body->HandleCar();
	tail->HandleCar();
#endif

	CarHandleHead *head = new CarHandleHead;
	CarHandleBody *body = new CarHandleBody;
	CarHandleTail *tail = new CarHandleTail;

	head->setNextHandle(body);
	body->setNextHandle(tail);
	tail->setNextHandle(NULL);

	//处理
	head->HandleCar();
	/*
	处理车头
  处理车身
  处理车尾
	*/

	cin.get();
}