#include<iostream>
#include "List.h"

void main() {
	// 3572918
	int e0 = 3;
	int e1 = 5;
	int e2 = 7;
	int e3 = 2;
	int e4 = 9;
	int e5 = 1;
	int e6 = 8;
	int e7 = 8;

	List *list = new List(10);

	list->insert(0, &e0);
	list->insert(1, &e1);
	list->insert(2, &e2);
	list->insert(3, &e3);
	list->insert(4, &e4);
	list->insert(5, &e5);
	list->insert(6, &e6);

	list->insert(3, &e7); 
	list->traverse();		//3 5 7 8 2 9 1 8

	int temp = 0;

	list->remove(3, &temp);
	std::cout << "# " << temp << std::endl; // # 8

	list->traverse(); //3 5 7 2 9 1 8


	list->getElem(0, &temp);
	std::cout << "# " << temp << std::endl; // 3

	int l = list->locateElem(&e6);
	std::cout << "# " << l << std::endl; // 6

	delete list;

	std::cin.get();
}