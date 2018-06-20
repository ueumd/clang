
#include <iostream>

using namespace std;

#include "Huffman.h"

int main()
{
	BinaryTree<int> tree;
	int init[10] = { 3, 6, 0, 2, 8, 4, 9, 1, 5, 7 };
	Huffman(init, 10, tree);
	cout << tree;
	tree.Destroy();
	cin.get();
	return 0;
}
