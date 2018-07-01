#include<iostream>
using namespace std;

/*
Strategy:
策略（算法）抽象。

ConcreteStrategy
各种策略（算法）的具体实现。

Context
策略的外部封装类，或者说策略的容器类。根据不同策略执行不同的行为。策略由外部环境决定。

适用于：
准备一组算法，并将每一个算法封装起来，使得它们可以互换。

*/

//策略（算法）抽象。
class Strategy
{
public:
	virtual void SymEncrypt() = 0;
};

/*
对称加密    速度快      加密大数块文件      特点： 加密密钥和解密密钥是一样的
非对称加密  加密速度慢  加密强度高 安全性高  特点： 加密密钥和解密密钥不一样，密钥分（公钥和私钥）
*/

//各种策略（算法）的具体实现。
class Des : public Strategy
{
public:
	virtual void SymEncrypt()
	{
		cout << "Des 加密" << endl;
	}
};

class AES : public Strategy
{
public:
	virtual void SymEncrypt()
	{
		cout << "AES 加密" << endl;
	}
};

/*
策略的外部封装类，或者说策略的容器类 执行场景
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
算法的实现和客户端的使用解耦合
使得算法变化，不会影响客户端
*/
void main() {
	
	#if 0
	//不符合开闭原则
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