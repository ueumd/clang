
#include <iostream>
using namespace std;

#include "SingleList.h"


int main()
{
	SingleList<int> list;
	for (int i = 0; i < 20; i++){
		list.Insert(i * 3, i);
	}
	for (int i = 0; i < 5; i++){
		list.Insert(3, i * 3);
	}
	cout << "the Length of the list is " << list.Length() << endl;
	list.Print();

	list.Remove(5);
	cout << "the Length of the list is " << list.Length() << endl;
	list.Print();

	list.RemoveAll(3);
	cout << "the Length of the list is " << list.Length() << endl;
	list.Print();

	cout << "The third element is " << list.Get(3) << endl;

	cout << *list.Find(18, 1) << endl;

	list.Find(100);

	list.MakeEmpty();
	cout << "the Length of the list is " << list.Length() << endl;
	list.Print();
	cin.get();
	return 0;
}
