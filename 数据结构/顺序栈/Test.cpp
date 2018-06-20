#include<iostream>
#include <stdlib.h>
using namespace std;

#include "SeqStack.h"

int main(){
	SeqStack<int> stack(10);
	int init[10] = { 1, 2, 6, 9, 0, 3, 8, 7, 5, 4 };
	for (int i = 0; i < 10; i++)
	{
		stack.Push(init[i]);
	}
	stack.Print();

	stack.Push(88);

	cout << stack.Pop() << endl;
	stack.Print();

	stack.MakeEmpty();
	stack.Print();

	stack.Pop();

	system("pause");
	return 0;
}
