#pragma once
class MyTeacher
{
private:
	int m_age;
	char m_name[32];


public:
	void setAge(int age);
	int getAge()
	{
		return m_age;
	}
	int equal(MyTeacher &tea);
};

