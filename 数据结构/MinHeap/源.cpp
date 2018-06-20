#include <iostream>

using namespace std;

#include "MinHeap.h"

int main(){
	int init[30] = { 17, 6, 22, 29, 14, 0, 21, 13, 27, 18, 2, 28, 8
		, 26, 3, 12, 20, 4, 9, 23, 15, 1, 11, 5, 19, 24, 16, 7, 10, 25 };
	MinHeap<int> heap(init, 30);
	heap.Print();
	cout << endl << endl << endl;

	heap.Insert(20);
	heap.Print();
	cout << endl << endl << endl;

	heap.Delete(20);
	heap.Print();
	cout << endl << endl << endl;

	cin.get();
	return 0;
}
