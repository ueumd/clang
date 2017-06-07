#define _CRT_SECURE_NO_WARNINGS
#include "iostream"

using namespace std;

class Name
{
public :
	Name(const char *myp)
	{
		int len = strlen(myp);
		p = (char *)malloc(len + 1);
		strcpy(p, myp);
	}
	Name(const Name *myp)
	{
		int len = strlen(myp);
		p = (char *)malloc(len + 1);
		strcpy(p, myp);
	}
	~Name()
	{
		if (p != NULL)
		{
			free(p);
			p = NULL;
		}
	}
private:
	char *p;
	int len;
};

void testName()
{
	Name obj1("abcefg");
	Name obj2 = obj1;
}

void main()
{
	
	testName();
	cout << "hello..." << endl;

	system("pause");
	return;
}