#include <iostream>
#include "CircularList.h"

using namespace std;

int main()
{
	CircularList<int> list;
	for (int i = 0; i < 20; i++){
		list.Insert(i * 3, i);
	}
	cout << "the Length of the list is " << list.Length() << endl;
	list.Print();
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

	list.MakeEmpty();
	cout << "the Length of the list is " << list.Length() << endl;
	list.Print();

	cin.get();
	return 0;
}
