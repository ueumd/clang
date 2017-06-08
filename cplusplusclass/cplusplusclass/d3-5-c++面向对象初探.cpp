#include "iostream"

using namespace std;

class C1
{
public :
	int i; //4
	int j; //4 
	int k; //4
};//12

class C2
{
public:
	int i;
	int j;
	int k;
	static int m;
};//12

struct s1
{
	int i;
	int j;
	int k;
};//12

struct s2
{
	int i;
	int j;
	int k;
	static int m;
};//12

void maind35()
{
	printf("c1:%d\n", sizeof(C1));
	printf("c1:%d\n", sizeof(C2));
	printf("s1:%d\n", sizeof(s1));
	printf("s2:%d\n", sizeof(s2));
	cout << "hello..." << endl;

	system("pause");
	return;
}