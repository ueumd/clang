#pragma once 

/*
#pragma once  只包含一次
如果A里包含B，B也包含A，没有#pragma once，成死锁
*/

#include "Bclass.h"

class Aclass
{
public:
	Aclass();
	~Aclass();
	void show(Bclass *b);
};

