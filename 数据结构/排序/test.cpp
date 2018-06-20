#include <iostream>

using namespace std;

#include "Sort.h"

int main()
{
	int init[15] = { 1, 3, 5, 7, 4, 2, 8, 0, 6, 9, 29, 13, 25, 11, 32 };
	DataList<int> data(init, 15);
	Sort<int> sort;
	data.Print();
	cout << endl << endl << endl;
	sort.InsertSort(data);
	sort.BinaryInsertSort(data);
	sort.ShellSort(data);
	sort.BubbleSort(data);
	sort.QuickSort(data);
	sort.SelectSort(data);
	sort.HeapSort(data);
	sort.MergeSort(data);
	sort.RadixSort(data, 2, 10);
	data.Print();
	cin.get();

	return 0;
}
