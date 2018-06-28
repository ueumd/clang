#include<iostream>
using namespace std;

/*
��æ��ҵ��Ա
*/
class BankWorkerBusy {
public:
	void save() {
		cout << "���" << endl;
	}
	void moveM() {
		cout << "ת��" << endl;
	}
	void jiaofei() {
		cout << "������" << endl;
	}
};



/*
��� ������ ��̬
*/
class AbBankWorker
{
public:
	virtual void doting() = 0;
};

class SaveBanker :public AbBankWorker {
public:
	virtual void doting() {
		cout << "���" << endl;
	}
};

class MoveBanker :public AbBankWorker {
public:
	virtual void doting() {
		cout << "ת��" << endl;
	}
};

class JiaofeiBanker :public AbBankWorker {
public:
	virtual void doting() {
		cout << "����" << endl;
	}
};


/*
��ϸ� ��������չ
*/
void testBankWorkerBusy() {
	BankWorkerBusy *bw = new BankWorkerBusy();
	bw->save();
	bw->moveM();
	bw->jiaofei();
}

/*
��̬
*/
void howdo(AbBankWorker *bw) {
	bw->doting(); //�ж�̬����
}

void testAvBankWorker() {
	AbBankWorker *bw = NULL;
	bw = new SaveBanker();
	bw->doting();  //�ж�̬����

	bw = new MoveBanker();
	bw->doting();


}



void main() {
	testBankWorkerBusy();

	testAvBankWorker();
	cin.get();
}