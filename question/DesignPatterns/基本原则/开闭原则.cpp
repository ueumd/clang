#include<iostream>
using namespace std;
/*
开放封闭原则  (OCP,Open For Extension, Closed For Modification Principle)
类的改动是通过增加代码进行的，而不是修改源代码。可扩展
实现多态的三个条件
多态的工程意义，可扩展（可调用后来人写的代码）
*/
/*
繁忙的业务员
*/
class BankWorkerBusy {
public:
	void save() {
		cout << "存款" << endl;
	}
	void moveM() {
		cout << "转帐" << endl;
	}
	void jiaofei() {
		cout << "交费用" << endl;
	}
};



/*
拆解 抽象类 多态
*/
class AbBankWorker
{
public:
	virtual void doting() = 0;
};

/*
开闭原则
*/
class SaveBanker :public AbBankWorker {
public:
	virtual void doting() {
		cout << "存款" << endl;
	}
};

class JiaofeiBanker :public AbBankWorker {
public:
	virtual void doting() {
		cout << "交费" << endl;
	}
};

class MoveBanker :public AbBankWorker {
public:
	virtual void doting() {
		cout << "转帐" << endl;
	}
};

//后来人写的代码
class AdvMoveBanker :public AbBankWorker {
public:
	virtual void doting() {
		cout << "批量转帐" << endl;
	}
};

class AdvAdvMoveBanker :public AbBankWorker {
public:
	virtual void doting() {
		cout << "自动化批量转帐" << endl;
	}
};


/*
耦合高 不利于扩展
*/
void testBankWorkerBusy() {
	BankWorkerBusy *bw = new BankWorkerBusy();
	bw->save();
	bw->moveM();
	bw->jiaofei();
}

/*
多态 
多态的工程意义，可扩展（可调用后来人写的代码）
*/
void howdo(AbBankWorker *bw) {
	bw->doting();
}

void testAvBankWorker() {
	AbBankWorker *bw = NULL;
	bw = new SaveBanker();
	bw->doting();  //有多态发生

	bw = new MoveBanker();
	bw->doting();

	//后来人写的代码
	bw = new AdvMoveBanker();
	bw->doting();

	bw = new AdvAdvMoveBanker();
	bw->doting();

	delete bw;
}


void main1() {
	testBankWorkerBusy();

	testAvBankWorker();
	cin.get();
}