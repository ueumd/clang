/*
作为中国最佳的旅游胜地，西安有很多著名的景点：秦始皇兵马俑、大雁塔、大唐芙蓉园、华清池、钟/鼓楼、骊山、古城墙、历史博物馆。。。

在访问西安时，访问者会参观各个景点。对于景点来说，无论访问者是谁，它们都是不变的。而作为访问者，不同角色的访问方式也不尽相同，游客只负责旅游 - 吃喝玩乐，而清洁工则需要打扫卫生、清理垃圾。

这里，游客和清洁工是具体访问者，兵马俑、钟楼等景点是具体元素，西安这座城市是结构对象。
*/

class BellTower;
class TerracottaWarriors;

// 访问者
class IVisitor
{
public:
	virtual ~IVisitor() {}
	virtual void Visit(BellTower *) = 0;
	virtual void Visit(TerracottaWarriors *) = 0;
};
