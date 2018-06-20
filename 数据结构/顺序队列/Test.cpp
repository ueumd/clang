#include <iostream>
using namespace std;

#include "SeqQueue.h"

int main(){
	SeqQueue<int> queue(10);
	int init[10] = { 1, 6, 9, 0, 2, 5, 8, 3, 7, 4 };
	for (int i = 0; i < 5; i++){
		queue.Append(init[i]);
	}
	queue.Print();

	cout << queue.Delete() << endl;
	queue.Print();

	for (int i = 5; i < 10; i++){
		queue.Append(init[i]);
	}
	queue.Print();

	cout << queue.Get() << endl;

	queue.MakeEmpty();
	queue.Print();

	queue.Append(1);
	queue.Print();
	cin.get();

	return 0;
}
