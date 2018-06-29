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

//设计师
class Director {
public:
	void Construct(Builder *builder) {
		builder->makeFloor();
		builder->makeFloor();
		builder->makeDoor();
	}
};

void main() {

	cin.get();
}