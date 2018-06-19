#include<iostream>
using namespace std;
#include"MyVector.cpp"

void test1() {
	MyVector<int> myv1(10);
	for (int i = 0; i < myv1.getLen(); i++) {
		myv1[i] = i + 1;
		cout << myv1[i] << " ";
	}
	cout << endl;

	MyVector<int> myv2 = myv1;
	for (int i = 0; i < myv2.getLen(); i++) {
		cout << myv2[i] << " ";
	}
	cout << endl;
}

void test2() {
	MyVector<char> myv1(10);
	myv1[0] = 'a';
	myv1[1] = 'b';
	myv1[2] = 'c';
	myv1[3] = 'd';

	cout << myv1;

}

void main() {
	test1();
	test2();
	cin.get();
}