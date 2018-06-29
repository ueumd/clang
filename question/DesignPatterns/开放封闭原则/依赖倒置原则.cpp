#include<iostream>
using namespace std;

/*
抽象层
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
具体的厂商
*/

class XSDisk :public HardDisk
{
public:
	void work() {
		cout << "我是的西数硬盘 工作良好" << endl;
	}
};

class InterCpu :public Cpu
{
public:
	void work() {
		cout << "我是的Inter cpu 工作良好" << endl;
	}
};


class JSDMem :public Memory
{
public:
	void work() {
		cout << "我是的JSDMem 工作良好" << endl;
	}
};


/*
高层的业务逻辑
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

	//组装电脑
	Computer *pc = new Computer(hardDisk, cpu, memory);
	pc->work();
	
	delete pc;
	delete hardDisk;
	delete cpu;
	delete memory;


	cin.get();
}