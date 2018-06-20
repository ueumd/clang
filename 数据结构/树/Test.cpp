#include <iostream>

using namespace std;

#include "Tree.h"

int main()
{
	Tree<int> tree;
	int init[10] = { 3, 6, 0, 2, 8, 4, 9, 1, 5, 7 };
	for (int i = 0; i < 10; i++){
		tree.Insert(init[i]);
		if (1 == i % 2){
			tree.SetCurrent(tree.Parent(tree.GetCurrent()));
		}
	}
	tree.Print();
	cout << endl << endl << endl;

	tree.Remove(3);
	tree.Print();
	cout << endl << endl << endl;

	cout << tree.Find(5) << endl << tree.Find(11) << endl;

	tree.PreOrder();
	cout << endl;
	tree.PostOrder();
	cout << endl;
	tree.LevelOrder();
	cin.get();
	return 0;
}
