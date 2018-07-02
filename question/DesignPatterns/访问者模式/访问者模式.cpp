/*
作为中国最佳的旅游胜地，西安有很多著名的景点：秦始皇兵马俑、大雁塔、大唐芙蓉园、华清池、钟/鼓楼、骊山、古城墙、历史博物馆。。。

在访问西安时，访问者会参观各个景点。对于景点来说，无论访问者是谁，它们都是不变的。而作为访问者，不同角色的访问方式也不尽相同，游客只负责旅游 - 吃喝玩乐，而清洁工则需要打扫卫生、清理垃圾。

这里，游客和清洁工是具体访问者，兵马俑、钟楼等景点是具体元素，西安这座城市是结构对象。
*/

#include<iostream>
#include "list"
using namespace std;

/*
创建景点：钟楼、兵马俑，
*/
class BellTower;
class TerracottaWarriors;

// 访问者
class IVisitor
{
public:
	virtual ~IVisitor() {}

	//访问者需要为每个景点都提供一个访问方法：
	virtual void Visit(BellTower *) = 0;
	virtual void Visit(TerracottaWarriors *) = 0;
};

/*
创建具体访问者

具体访问者有两种 - 游客、清洁工，它们分别实现了不同的访问操作（游客只管吃喝玩乐，清洁工负责清理垃圾）：
*/

// 游客
class Tourist : public IVisitor {
public:
	virtual void Visit(BellTower *) override {
		cout << "游客参观钟楼！" << endl;
	}

	virtual void Visit(TerracottaWarriors  *) override {
		cout <<  "游客参观兵马俑！" << endl;
	}
};

// 清洁工
class Cleaner : public IVisitor
{
public:
	virtual void Visit(BellTower *) override {
		cout << "清洁工清理钟楼的垃圾！" << endl;
	}

	virtual void Visit(TerracottaWarriors *) override {
		cout << "清洁工清理兵马俑的垃圾！" << endl;
	}
};

/*
景点中定义了一个 Accept() 接口，用于接受访问者的访问：
*/
class IPlace {
public:
	virtual ~IPlace() {}
	virtual void Accept(IVisitor *visitor) = 0;
};

/*
创建具体元素

具体元素有两个 - 钟楼、兵马俑，它们实现了 Accept() 方法：
*/
// 钟楼
class BellTower : public IPlace
{
public:
	virtual void Accept(IVisitor *visitor) override {
		cout << "钟楼景点接待游客" << endl;
		visitor->Visit(this);
	}
};

// 兵马俑
class TerracottaWarriors : public IPlace
{
public:
	virtual void Accept(IVisitor *visitor) override {
		cout << "兵马俑景点接待游客" << endl;
		visitor->Visit(this);
	}
};

/*
创建对象结构
添加景点，并为每一个景点添加访问者：
*/

class City{
public:
	void Attach(IPlace *place) {
		m_places.push_back(place);
	}

	void Detach(IPlace *place) {
		m_places.remove(place);
	}

	void Accept(IVisitor *visitor) {
		// 为每一个 element 设置 visitor，进行对应的操作
		for (list<IPlace*>::iterator it = m_places.begin(); it != m_places.end(); ++it) {
			(*it)->Accept(visitor);
		}
	}

private:
	list<IPlace *> m_places;
};

int main()
{
	City *city = new City();

	// 景点 - 钟楼、兵马俑
	IPlace *bellTower = new BellTower();
	IPlace *warriors = new TerracottaWarriors();

	// 访问者 - 游客、清洁工
	IVisitor *tourist = new Tourist();
	IVisitor *cleaner = new Cleaner();

	// 添加景点
	city->Attach(bellTower);
	city->Attach(warriors);

	// 接受访问
	city->Accept(tourist);
	city->Accept(cleaner);

	delete cleaner;
	delete tourist;
	delete warriors;
	delete city;

	getchar();

	return 0;
}