#include<iostream>
using namespace std;

/*
Strategy:
���ԣ��㷨������

ConcreteStrategy
���ֲ��ԣ��㷨���ľ���ʵ�֡�

Context
���Ե��ⲿ��װ�࣬����˵���Ե������ࡣ���ݲ�ͬ����ִ�в�ͬ����Ϊ���������ⲿ����������

�����ڣ�
׼��һ���㷨������ÿһ���㷨��װ������ʹ�����ǿ��Ի�����

*/

//���ԣ��㷨������
class Strategy
{
public:
	virtual void SymEncrypt() = 0;
};

/*
�ԳƼ���    �ٶȿ�      ���ܴ������ļ�      �ص㣺 ������Կ�ͽ�����Կ��һ����
�ǶԳƼ���  �����ٶ���  ����ǿ�ȸ� ��ȫ�Ը�  �ص㣺 ������Կ�ͽ�����Կ��һ������Կ�֣���Կ��˽Կ��
*/

//���ֲ��ԣ��㷨���ľ���ʵ�֡�
class Des : public Strategy
{
public:
	virtual void SymEncrypt()
	{
		cout << "Des ����" << endl;
	}
};

class AES : public Strategy
{
public:
	virtual void SymEncrypt()
	{
		cout << "AES ����" << endl;
	}
};

/*
���Ե��ⲿ��װ�࣬����˵���Ե������� ִ�г���
*/
class Context {
public:
	Context(Strategy *strategy) {
		p = strategy;
	}

	void Operator()
	{
		p->SymEncrypt();
	}

private:
	Strategy *p;
};

/*
�㷨��ʵ�ֺͿͻ��˵�ʹ�ý����
ʹ���㷨�仯������Ӱ��ͻ���
*/
void main() {
	
	#if 0
	//�����Ͽ���ԭ��
	Strategy *strategy = NULL;

	strategy = new AES;
	strategy->SymEncrypt();

	delete strategy;

	strategy = new Des;
	strategy->SymEncrypt();
	delete strategy;
	#endif


	Strategy *strategy = NULL;
	Context *ctx = NULL;

	strategy = new AES;

	ctx = new Context(strategy);
	ctx->Operator();

	delete strategy;
	delete ctx;



	cin.get();
}