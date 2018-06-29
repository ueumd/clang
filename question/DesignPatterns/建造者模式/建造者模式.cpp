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
		//Ҫת���ͣ�����
		cout << m_floor.c_str() << ", " << m_wall.c_str() << ", " << m_door.c_str()<< endl;
	}


private:
	string m_floor;
	string m_wall;
	string m_door;
};


/*
������
*/
class Builder {
public:
	virtual House *GetHouse() = 0;
	virtual void makeFloor() = 0;
	virtual void makeWall() = 0;
	virtual void makeDoor() = 0;
};

//��Ԣ����
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

//��������
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

//���ʦ
class Director {
public:
	void Construct(Builder *builder) {
		builder->makeFloor();
		builder->makeFloor();
		builder->makeDoor();
	}
};

//�ͻ�ֱ���췿��
void clientCreate() {
	House *house = new House();
	house->setFloor("client floor");
	house->setWall("client wall");
	house->setDoor("client door");
	house->getHouse();
	delete house;
}

//���̶�ֱ���췿��
void builderCreate() {
	Builder *builder = new FlatBuild;

	builder->makeFloor();
	builder->makeWall();
	builder->makeDoor();

}

void main() {
	
	clientCreate();
	cin.get();
}