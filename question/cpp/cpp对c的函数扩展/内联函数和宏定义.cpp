#include<iostream>
using namespace std;
#define MYFUNC(a, b) ((a) < (b) ? (a) : (b))

inline int myfunc(int a, int b) {
	return a < b ? a : b;
}

void main111() {

	int a = 1;
	int b = 3;

	//int c = myfunc(++a, b); // a=2 b=3 c=2

	int c = MYFUNC(++a, b); //ºêÌæ»»²¢Õ¹ÖÐ ((++a) < (b) ? (++a) : (b))  a=3 b=3 c=3

	printf("a=%d, b=%d, c=%d\n", a, b, c);

	cin.get();
}