#include <stdio.h>
#include <stdbool.h>

int main() {
	
	_Bool bl = true; // 0 false ·Ç0 true

	printf("\n%d", bl);			// 1
	printf("\n%d", sizeof(bl)); // 1

	bl ? printf("\nHello") : printf("\nLove");
	system("pause");
	return 0;
}