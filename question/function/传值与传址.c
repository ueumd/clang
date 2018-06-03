#include<stdio.h>
#include<stdlib.h>

void mySwap(int i, int j)
{
	int t = i;
	i = j;
	j = t;
}

//´«Ö·
void mySwapP(int *pa, int *pb)
{
	int t = *pa;
	*pa = *pb;
	*pb = t;
}

int main() {
	
	int a = 4; int b = 5;
	printf("a = %d b = %d\n", a, b); // 4 5
	mySwap(a, b);
	printf("a = %d b = %d\n", a, b); // 4 5

	int x = 4; int y = 5;
	mySwapP(&x, &y);
	printf("x = %d y = %d\n", x, y); // 5 4

	getchar();
	return 0;
}
