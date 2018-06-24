#include "Coordinate.h"
#include<iostream>
Coordinate::Coordinate(int x, int y):m_iX(x), m_iY(y){}
void Coordinate::print()
{
	std::cout << "x: " << m_iX << " y:" << m_iY << std::endl;
}
