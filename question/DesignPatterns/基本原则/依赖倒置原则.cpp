#include<iostream>
using namespace std;

/*
�����
*/
class HardDisk {
public:
	virtual void work() = 0;
};

class Cpu {
public:
	virtual void work() = 0;
};

class Memory {
public:
	virtual void work() = 0;
};

/*
����ĳ���
*/

class XSDisk :public HardDisk
{
public:
	void work() {
		cout << "���ǵ�����Ӳ�� ��������" << endl;
	}
};

class InterCpu :public Cpu
{
public:
	void work() {
		cout << "���ǵ�Inter cpu ��������" << endl;
	}
};


class JSDMem :public Memory
{
public:
	void work() {
		cout << "���ǵ�JSDMem ��������" << endl;
	}
};


/*
�߲��ҵ���߼�
*/
class Computer {
public:
	Computer(HardDisk *hardDisk,Cpu *cpu,Memory *memory) {
		m_hardDisk = hardDisk;
		m_cpu = cpu;
		m_memory = memory;
	}

	void work() {
		m_hardDisk->work();
		m_cpu->work();
		m_memory->work();
	}
private:
	HardDisk *m_hardDisk;
	Cpu *m_cpu;
	Memory *m_memory;
};


void main() {
	HardDisk *hardDisk = NULL;
	Cpu *cpu = NULL;
	Memory *memory = NULL;

	hardDisk = new XSDisk();
	cpu = new InterCpu();
	memory = new JSDMem();

	//��װ����
	Computer *pc = new Computer(hardDisk, cpu, memory);
	pc->work();
	
	delete pc;
	delete hardDisk;
	delete cpu;
	delete memory;


	cin.get();
}