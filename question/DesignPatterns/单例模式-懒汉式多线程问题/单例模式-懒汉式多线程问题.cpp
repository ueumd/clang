// ����ģʽ-����ʽ���߳�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<Windows.h>
#include "winbase.h"
#include <process.h>
using namespace std;

/*
1 "����"ģʽ��Ȼ���ŵ㣬����ÿ�ε���GetInstance()��̬����ʱ�������ж�NULL == m_instance��ʹ������Կ�������
2 ���߳��лᵼ�¶��ʵ���Ĳ������Ӷ��������д��벻��ȷ�Լ��ڴ��й¶��
3 �ṩ�ͷ���Դ�ĺ���
*/

class Singelton {
private:
	//���캯��˽�л�
	Singelton() {
			cout << "Singelton���캯��ִ��begin" << endl;
			Sleep(1000); //�߳�˯��
			cout << "Singelton���캯��ִ��end" << endl;
	}
public:
	/*
	����ʽ ֻ�е��ø÷���ʱ�Ż�new Singelton::getInstance()

	����ڶ��̵߳��õ����⣬������߳�ͬ��+����+����
	Singelton *p1 = Singelton::getInstance(); �߳�1
	Singelton *p2 = Singelton::getInstance(); �߳�2

	Singelton() {
	cout << "Singelton���캯��ִ��begin" << endl;
	sleep(1000);
	cout << "Singelton���캯��ִ��end" << endl;
	}
	*/
	static Singelton *getSingelton() {
		if (NULL == m_psl) {
			count++;
			m_psl = new Singelton();
		}
		return m_psl;
	}

	static void freeInstance() {
		if (NULL != m_psl) {
			delete m_psl;
			m_psl = NULL;
		}
	}
	void pirntS() //���Ժ���
	{
		printf("Singelton printS test count:%d \n", count);
	}

private:
	static Singelton *m_psl;
	static int count;
};

//��̬������ʼ��
Singelton* Singelton::m_psl = NULL;
int Singelton::count = 0;

void main11() {

	Singelton *p1 = Singelton::getSingelton();
	Singelton *p2 = Singelton::getSingelton();

	if (p1 == p2) {
		cout << "ͬһ������" << endl; //ͬһ������
	}
	else {
		cout << "����ͬһ������" << endl;
	}

	Singelton::freeInstance();
}


void MyThreadFunc(void *) {
	// cout << "�����߳���..." << endl;
	cout << "�����߳���...\n";

	int id = GetCurrentThreadId();
	printf("\n threadfunc%d \n", id);

	Singelton::getSingelton()->pirntS();
	return;

}

int _tmain(int argc, _TCHAR argv[])
{
	//main11();
	HANDLE hThread[10];
	int threadnum = 3;

	for (int i = 0; i < 3; i++) {
		hThread[0] = (HANDLE)_beginthread(MyThreadFunc, 0, NULL);
	}

	//�ȴ����е����̶߳�������Ϻ�,��ִ���������
	for (int i = 0; i<threadnum; i++){
		WaitForSingleObject(hThread[i], INFINITE);
	}

	printf("�ȴ��߳̽���\n");

	for (int i = 0; i<threadnum; i++){
		CloseHandle( hThread[i] );
	}
	Singelton::freeInstance();

	cin.get();
	return 0;
}

