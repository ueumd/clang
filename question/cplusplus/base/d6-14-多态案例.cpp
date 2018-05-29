#include "iostream"

using namespace std;

class HeroFighter
{
public:
	virtual int power()
	{
		return 10;
	}
};

class EnemyFigther
{
public:
	int attack()
	{
		return 15;
	}
};

class AdvHeroFighter : public HeroFighter
{
public:
	virtual int power()
	{
		return 20;
	}
};



//多态场景
void playFighter(HeroFighter *hf, EnemyFigther *ef)
{
	//多态的理论
	//不写virtual关键字 就是静态联编 c++编译器根据	HeroFighter类型去执行 这个类型的power函数,在编译器编译阶段就已经决定了函数的调用
	 
	//写了就是动态联编： 迟邦定 //在运行的时候 根据具体对象（具体的类型），执行不同对象的函数调用，表现成多态。
	if (hf->power() > ef->attack())
	{
		cout << "主角win" << endl;
	}
	else
	{
		cout << "主角挂掉" << endl;
	}
	
}

//原始方式场景
void maind6142()
{

	HeroFighter hf;
	AdvHeroFighter Advhf;
	EnemyFigther ef;

	if (hf.power() > ef.attack())
	{
		cout << "主角win" << endl;
	}
	else
	{
		cout << "主角挂掉" << endl;
	}
	if (Advhf.power() > ef.attack())
	{
		cout << "Advhf主角win" << endl;
	}
	else
	{
		cout << "Advhf主角挂掉" << endl;
	}



	cout << "hello..." << endl;

	system("pause");
	return;
}

void maind614()
{

	/*
	实现多态的三个条件：
	1.  要有继承
	2、 要有虚函数重写
	3、 用父类指针（父类引用） 指向子类对象
	*/
	HeroFighter hf;
	AdvHeroFighter Advhf;
	EnemyFigther ef;


	playFighter(&hf, &ef);

	//传的是子类 执行的是子类的opwer()
	playFighter(&Advhf, &ef);

	cout << "hello..." << endl;

	system("pause");
	return;
}