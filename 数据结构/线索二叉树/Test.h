#include <iostream>

using namespace std;

#include "ThreadInorderIterator.h"

int main(){
	ThreadTree<int> tree;
	ThreadInorderIterator<int> threadtree(tree);
	int init[10] = { 3, 6, 0, 2, 8, 4, 9, 1, 5, 7 };
	for (int i = 0; i < 10;){
		threadtree.InsertLeft(new ThreadNode<int>(init[i++]));
		threadtree.InsertRight(new ThreadNode<int>(init[i++]));
	}
	threadtree.Print();
	cout << endl << endl;

	threadtree.InOrder();
	return 0;
}
