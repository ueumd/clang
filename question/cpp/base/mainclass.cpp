#include "iostream"

using namespace std;

#include "MyTeacher.h"

void mainclass()
{

	MyTeacher t1, t2;

	t1.setAge(100);
	t2.setAge(99);

	cout <<"t1 age:" << t1.getAge() << endl;
	cout <<"t2 age:" << t2.getAge() << endl;

	cout << "equal:" << t1.equal(t2) << endl;

	cout << "hello..." << endl;

	system("pause");
	return;
}