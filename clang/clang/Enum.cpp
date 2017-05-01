#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
int main()
{
	//enum week { Mon, Tues, Wed, Thurs, Fri, Sat, Sun };
	enum week { Mon = 1, Tues = 2, Wed = 3, Thurs = 4, Fri = 5, Sat = 6, Sun = 7 };
	assert(10 > 2);
	int i = 0;
	for (; ; )
	{
		assert(i++ <= 100);
		printf("我是第%d行\n", i);
	}
	system("pause");
	return 0;
}