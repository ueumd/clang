#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void mySwap(int i, int j)
{
	int t = i;
	i = j;
	j = t;
}

void mySwapP(int *pa, int *pb)
{
	int t = *pa;
	*pa = *pb;
	*pb = t;
}

int main() {
	int intArr[10] = {0};
	char charArr[] = { 'A','B','C','D' };
	char strArr[7] = "ABCDEF"; 		//��Ϊ��'\0' 7����6  �Ƽ� char strArr[] = "ABCDEF"; 
	char *pStr = "ABCDEF";

	strArr[1] = 'H';
	printf("%s\n", strArr);   //AHCDEF

	// pStr[1] = 'H'; ֻ�ܶ������ܸ�д
	pStr = "HELLO";					//ָ�����ָ���µ�����
	printf("%s\n", pStr);   //HELLO

	int len = sizeof(intArr) / sizeof(int);
	printf("intArr = %d\n", len);               //10
	printf("charArr = %d\n", sizeof(charArr));	//4
  printf("strArr = %ld\n", strlen(strArr));		//6
	printf("pStr = %ld\n", strlen(pStr));				//6



	int a = 4; int b = 5;
	printf("a = %d b = %d\n", a, b);
	mySwap(a, b);
	printf("a = %d b = %d\n", a, b);

	int x = 4; int y = 5;
	mySwapP(&x, &y);
	printf("x = %d y = %d\n", x, y);

	getchar();
	return 0;


}


