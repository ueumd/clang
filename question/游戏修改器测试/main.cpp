#include <stdio.h>
#include<stdlib.h>

int main(void) {
	int x = 520;
	for (int i = 0; i < 100; i++) {
		printf("x = %d\n", x);
		getchar();
		x++;
	}
}