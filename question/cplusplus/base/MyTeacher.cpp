#include "MyTeacher.h"
void MyTeacher::setAge(int age)
{
	this->m_age = age;
}

int MyTeacher::equal(MyTeacher &tea)
{
	if (this->m_age == tea.getAge())
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
