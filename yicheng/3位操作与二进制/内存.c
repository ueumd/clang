#include<stdio.h>
#include<stdlib.h>
int main�ڴ�() {

	int num = 1;
	printf("%d", sizeof(num));
	printf("\n%p", &num);
	/*
	32λ ռ4���ֽ� 1�� 16������ʾ
	0x0039FD78  01  .
	0x0039FD79  00  .
	0x0039FD7A  00  .
	0x0039FD7B  00  .

	0000
	0000
	0000
	0001
	*/

	int x = 0x12345678; //16��������
	printf("%d", sizeof(x));
	printf("\n%p", &x);
	//��λ�ڵ��ֽ� ��λ�ڸ��ֽ�
	/*
	0x0033F9A8  78  x
	0x0033F9A9  56  V
	0x0033F9AA  34  4
	0x0033F9AB  12  .
	*/
	system("pause");
	return 0;
}
