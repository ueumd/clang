#include <stdio.h>
/**
ֻҪ�ں����ڲ� int num �ȼ��� auto int num
*/
void go() {
	auto int num = 10; //�Զ����� �Զ��ͷ�
	printf("%p", &num);
}

int main() {
	go();
	printf("AAAAAAAAA\n");
	go();
	printf("AAAAAAAAA\n");
	return 0;
}