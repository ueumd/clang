#include<iostream>
using namespace std;

/*
����ģ��
template<typename ��������1, ��������2...>  ����ֵ����  ������(�β��б�){
    //�ں������п���ʹ�����Ͳ���
}
���Ͳ��������ж��������֮���Զ���,�ָ������Ͳ����б���< >��Χ����ʽ�����б���( )��Χ��
*/

#if 0
// ����
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void swap(char *a, char *b) {
	char tmp = *a;
	*a = *b;
	*b = tmp;
}
#endif

//���Ʒ���

//������������ѹ���� ����ģ�� template<typename T>����Ϊģ��ͷ��
template<typename T> void swap(T *a, T*b) { //ָ��
	T tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
��ͨ�������ã����Խ�����ʽ������ת��
ģ�溯�����ص��ã����ʣ������������������ϸ�İ����ͽ���ƥ�䣬��������Զ�����ת��
*/
template<class  T> void pSwap(T &a, T &b) { //����
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T> void pSwap(T a[], T b[], int len) { //���أ�������������
	T temp;
	for (int i = 0; i<len; i++) {
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}



void printArray(int arr[], int len) {
	for (int i = 0; i<len; i++) {
		if (i == len - 1) {
			cout << arr[i] << endl;
		}
		else {
			cout << arr[i] << ", ";
		}
	}
}

void test1() {
	int a = 100, b = 200;
	swap(&a, &b);
	cout << a << ", " << b << endl;  // 200 100

	char a1 = 'Z', b1 = 'A';
	pSwap(a1, b1);
	cout << a1 << ", " << b1 << endl; // A Z

	char a2 = 'x', b2 = 'y';
	pSwap(a2, b2);
	cout << a2 << ", " << b2 << endl; // y x
}

//����ģ������
void test2() {

	char a3 = 'Y', b3 = 'X';
	pSwap(a3, b3);
	cout << a3 << ", " << b3 << endl; // A Z

	cout << "----------------------------------------" << endl;

	//������������
	int a[5] = { 1, 2, 3, 4, 5 };
	int b[5] = { 10, 20, 30, 40, 50 };

	int len = sizeof(a) / sizeof(int);  //���鳤��
	
	//
	int *c = a; //cָ������a�׵�ַ 
	cout << "c=" << c << endl;
	printArray(c, len); // 1, 2, 3, 4, 5

	

	pSwap(a, b, len);									  //ƥ��ģ���
	printArray(a, len);
	printArray(b, len);

	/*
	X, Y
	----------------------------------------
	10, 20, 30, 40, 50
	1, 2, 3, 4, 5
	*/

}

// ��������Ҳ��T
template<typename T> T max(T a, T b, T c) {
	T max_num = a;
	if (b > max_num) max_num = b;
	if (c > max_num) max_num = c;
	return max_num;
}

void test3() {
	int a = 1, b = 5, c = 100;
	int max_num = max(a, b, c);
	cout << max_num << endl;
}

/*
���Ӻ����뺯��ģ������(����������ʱ ��ͨ��������ѡ��)������ʾʹ�ú���ģ��<>  mySwap<>(a, b);
��ͨ�������ã����Խ�����ʽ������ת��
ģ�溯�����ص��ã����ʣ������������������ϸ�İ����ͽ���ƥ�䣬��������Զ�����ת��
*/
template<typename T> void mySwap(T &a, T &b) {
	T c = 0;
	c = a;
	a = b;
	b = c;
}

void mySwap(int a, int c) {
	cout << "a: " << a << "c:" << c << endl;
}

int main111() {
//	test2();

	int a = 10;
	int b = 10;
	char c = 'A';

	mySwap(a, c); //��ͨ���� ��ʽ������ת��

	mySwap(a, b);//����ģ��

	system("pause");
	return 0;
}

