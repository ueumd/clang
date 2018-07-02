/*
星际争霸里的坦克作为例子，它不架起来的时候可以攻击，可以移动。架起来的时候攻击增强，但是不能移动：
*/
#include <iostream>

class SiegeTank;
class ISiegeTankState
{
public:
	virtual void move(int x, int y) = 0;
	virtual void attack() = 0;
};

class SiegeState : public ISiegeTankState
{
public:
	SiegeState(SiegeTank* pTank) : m_pTank(pTank) {}

	virtual void move(int x, int y)
	{
		std::cout << "Can't move in siege mode." << std::endl;
	}

	virtual void attack()
	{
		std::cout << "Attacking for 40" << std::endl;
	}

private:
	SiegeTank* m_pTank;
};

class TankState : public ISiegeTankState
{
public:
	TankState(SiegeTank* pTank) : m_pTank(pTank) {}

	virtual void move(int x, int y)
	{
		std::cout << "Move to (" << x << ", " << y << ")" << std::endl;
	}

	virtual void attack()
	{
		std::cout << "Attacking for 20" << std::endl;
	}

private:
	SiegeTank* m_pTank;
};

class SiegeTank
{
public:
	SiegeTank()
	{
		m_pTankState = new TankState(this);
		m_pSiegeState = new SiegeState(this);
		m_pSiegeTankState = m_pTankState;
	}

	void enterTankMode()
	{
		m_pSiegeTankState = m_pTankState;
		std::cout << "Switch to tank mode" << std::endl;
	}

	void enterSiegeMode()
	{
		m_pSiegeTankState = m_pSiegeState;
		std::cout << "Switch to siege mode" << std::endl;
	}

public:
	void attack()
	{
		m_pSiegeTankState->attack();
	}

	void move(int x, int y)
	{
		m_pSiegeTankState->move(x, y);
	}

private:
	void setState(ISiegeTankState* pSiegeTankMode)
	{
		m_pSiegeTankState = pSiegeTankMode;
	}

private:
	TankState* m_pTankState;
	SiegeState* m_pSiegeState;
	ISiegeTankState* m_pSiegeTankState;
};

int main()
{
	SiegeTank tank;
	tank.enterTankMode();
	tank.attack();
	tank.move(1, 1);

	tank.enterSiegeMode();
	tank.attack();
	tank.move(2, 2);

	tank.enterTankMode();
	tank.attack();
	tank.move(3, 3);

	std::cin.get();
	return 0;
}