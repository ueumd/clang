#include<stdio.h>
#include<stdlib.h>
void binDis2(int data) {
	int i = 8;
	while (i--)
	{
		if (data & (1 << i)) {
			printf("1");
		}
		else {
			printf("0");
		}

		if (i % 4 == 0) {
			printf(" ");
		}
	}
	printf("\n");
}
//Ҫ�����λ����mask

// �鿴ĳһλ��ֵ    if((flag & mask)) 
void viewSomeBitValue() {
	int a = 0x55aa;    // 0101 0101 1010 1010
	int mask = 1 << 6; // 0000 0000 0100 0000

	// &  ����λ��Ϊ1ʱ�������Ϊ1
	if (a & mask) { // ����6λ����������Կ���&��ʱ����0������7λ ��1
		printf("leds is on");
	}
	else {
		printf("leds is off");
	}
}

void bitSetNegate() { // ȡ��
	int a = 0x55aa;    // 0101 0101 1010 1010      0101 0101 0101 0101
										 //	0000 0000 1111 1111
										 // 0101 0101 0101 0101

						// 1<<7     0000 0000 1000 0000	                	
	int mask = 1 << 7 | 1 << 6 | 1 << 5 | 1 << 4 | 1 << 3 | 1 << 2 | 1 << 1 | 1 << 0;
	binDis(a);

	//^����λ��ͬΪ0������Ϊ1
	a ^= mask;
	binDis(a);
}

void bitSetOne() { //��1 ��0x55aa ������11λ��1
	int a = 0x55aa;      // 0101 0101 1010 1010      0101 1101 0101 0101
	int mask = 1 << 11; //  0000 1000 0000 0000 
	a = a | mask;
	binDis(a);
}


void bitSetZero() { //��0101 0101 1010 1010������3λ��0 
	int a = 0x55aa;      // 0101 0101 1010 1010      0101 0101 1010 1010   
	int mask = 1 << 3;  //  0000 0000 0000 1000     ~1111 1111 1111 0111
											// ���                      &0101 0101 1010 0010

	binDis(a);
	a = a & (~mask);
	binDis(mask);
	binDis(~mask);
	binDis(a);
}

int main����() {
	int mask = 0;
	/*
	int mask = (1<<6) | (1<<5) | (1<<4) | (1<<3) | (1<<2)
	0100 0000
	0110 0000
	0111 0000
	0111 1000
	0111 1100
  ---------
  0111 1100
	*/
	for (int i = 6; i >= 2; i--) {
		mask |= (1 << i);
		//binDis2(mask);
	}

	//viewSomeBitValue();

	//bitSetOne();

	bitSetZero();
	system("pause");
	return 0;
}