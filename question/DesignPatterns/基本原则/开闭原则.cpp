#include<iostream>
using namespace std;
/*
���ŷ��ԭ��  (OCP,Open For Extension, Closed For Modification Principle)
��ĸĶ���ͨ�����Ӵ�����еģ��������޸�Դ���롣����չ
ʵ�ֶ�̬����������
��̬�Ĺ������壬����չ���ɵ��ú�����д�Ĵ��룩
*/
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

/*
����ԭ��
*/
class SaveBanker :public AbBankWorker {
public:
	virtual void doting() {
		cout << "���" << endl;
	}
};

class JiaofeiBanker :public AbBankWorker {
public:
	virtual void doting() {
		cout << "����" << endl;
	}
};

class MoveBanker :public AbBankWorker {
public:
	virtual void doting() {
		cout << "ת��" << endl;
	}
};

//������д�Ĵ���
class AdvMoveBanker :public AbBankWorker {
public:
	virtual void doting() {
		cout << "����ת��" << endl;
	}
};

class AdvAdvMoveBanker :public AbBankWorker {
public:
	virtual void doting() {
		cout << "�Զ�������ת��" << endl;
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
��̬�Ĺ������壬����չ���ɵ��ú�����д�Ĵ��룩
*/
void howdo(AbBankWorker *bw) {
	bw->doting();
}

void testAvBankWorker() {
	AbBankWorker *bw = NULL;
	bw = new SaveBanker();
	bw->doting();  //�ж�̬����

	bw = new MoveBanker();
	bw->doting();

	//������д�Ĵ���
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