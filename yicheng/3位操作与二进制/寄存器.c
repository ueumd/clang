#include<stdio.h>
#include<stdlib.h>


int main¼Ä´æÆ÷() {
	int x = 3;
	int y = 4;
	int sum = x + y;

	int a = -15, b = 15;
	printf("%d %d\n", a >> 2, b >> 2);

	for(int i = 0; i < 100; i++) {
		if (i & 1) {
			printf("i = %d\n", i);
		}
	}

	char *s1 = "Hello";
	char *s2 = "World";
	printf("%s %s\n", s1, s2);
	Swap(&s1, &s2);
	printf("%s %s\n", s1, s2);


	int aa = 7, bb = -12345;
	printf("%d  %d\n", SignReversal(aa), SignReversal(bb));

	printf("%d\n", my_abs(5));
	system("pause");
	return 0;
}