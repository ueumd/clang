#include<iostream>
using namespace std;

class House {
public:
	void setFloor(string floor) {
		this->m_floor = floor;
	}

	string getFloor() const {
		return m_floor;
	}

	void setWall(string wall) {
		this->m_wall = wall;
	}

	string getWall() const {
		return m_wall;
	}

	void setDoor(string door) {
		this->m_door = door;
	}

	string getDoor() const {
		return m_door;
	}

	void getHouse() {
		//要转类型！！！
		cout << m_floor.c_str() << ", " << m_wall.c_str() << ", " << m_door.c_str()<< endl;
	}


private:
	string m_floor;
	string m_wall;
	string m_door;
};

/*
工程团
*/
class Builder {
public:
	virtual House *GetHouse() = 0;
	virtual void makeFloor() = 0;
	virtual void makeWall() = 0;
	virtual void makeDoor() = 0;
};

//公寓工程
class FlatBuild :public Builder {
public:
	FlatBuild() {
		pHouse = new House();
	}

	virtual House *GetHouse() {
		return pHouse;
	}

	virtual void makeFloor() {
		pHouse->setFloor("FlatFloor");
	}

	virtual void makeWall() {
		pHouse->setWall("FlatWall");
	}

	virtual void makeDoor() {
		pHouse->setDoor("FlatDoor");
	}

private:
	House *pHouse;
};

//别墅工程
class VillaBuild:public Builder {
public:
	VillaBuild() {
		pHouse = new House();
	}

	virtual House *GetHouse() {
		return pHouse;
	}

	virtual void makeFloor() {
		pHouse->setFloor("VillaFloor");
	}

	virtual void makeWall() {
		pHouse->setWall("VillaWall");
	}

	virtual void makeDoor() {
		pHouse->setDoor("VillaDoor");
	}

private:
	House *pHouse;
};

//设计师
class Director {
public:
	void Construct(Builder *builder) {
		builder->makeFloor();
		builder->makeWall ();
		builder->makeDoor();
	}
};

//客户直接造房子
void clientCreate() {
	House *house = new House();
	house->setFloor("client floor");
	house->setWall("client wall");
	house->setDoor("client door");
	house->getHouse();		//client floor, client wall, client door
	delete house;
}

//工程队直接造房子
void builderCreate() {
	Builder *builder = new FlatBuild;

	builder->makeFloor();
	builder->makeWall();
	builder->makeDoor();

	House *p = builder->GetHouse();
	p->getHouse();			//FlatFloor, FlatWall, FlatDoor

	delete builder;
	delete p;
}

//指挥者（设计师）指挥工程队和建房子
void directorCreate() {
	Director *d = new Director;

	//建公寓
	Builder *builder = new FlatBuild;
	d->Construct(builder);		//设计师指挥工程队干活
	House *p = builder->GetHouse();
	p->getHouse();						// FlatFloor, FlatWall, FlatDoor

	delete builder;
	delete p;

	//建别墅
	builder = new VillaBuild();
	d->Construct(builder);
	p = builder->GetHouse();
	p->getHouse();					//VillaFloor, VillaWall, VillaDoor

	delete builder;
	delete p;

	delete d;

}

void main() {
	clientCreate();
	builderCreate();
	directorCreate();

	cin.get();
}