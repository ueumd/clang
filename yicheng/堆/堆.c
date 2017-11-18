#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

void heapTest() {
	//�ڴ���䣬malloc calloc,realloc
	int *p = (int *)malloc(sizeof(int) * 10); //�����ڴ� ָ������
	printf("p=%p\n", p);

	int num = 0;
	for (int *px = p; px < p + 10; px++) { // �����ǲ���++ ÿ�β���4
		*px = num;
		printf("%p, %d\n", px, *px); //�˴���ϵ� ���Կ������ڴ������10����ַ
		num++;
	}

	free(p);

	/*
	���Կ������ڴ������10����ַ int����ָ��ռ4���ֽ�  �����ǲ���++ ÿ�β���4
	0x0071DDA8    +0   +0   +0   +0  ....
	0x0071DDAC    +1   +0   +0   +0  ....
	0x0071DDB0    +2   +0   +0   +0  ....
	0x0071DDB4    +3   +0   +0   +0  ....
	0x0071DDB8    +4   +0   +0   +0  ....
	0x0071DDBC    +5   +0   +0   +0  ....
	0x0071DDC0    +6   +0   +0   +0  ....
	0x0071DDC4    +7   +0   +0   +0  ....
	0x0071DDC8    +8   +0   +0   +0  ....
	0x0071DDCC    +9   +0   +0   +0  ....

	p=0071DDA8
	0071DDA8, 0
	0071DDAC, 1
	0071DDB0, 2
	0071DDB4, 3
	0071DDB8, 4
	0071DDBC, 5
	0071DDC0, 6
	0071DDC4, 7
	0071DDC8, 8
	0071DDCC, 9
	*/
}

int mainA() {

	/*
	��������������heapTest() ��һ�������ڴ沢û���ͷ� �ڶ��������ֿ������µĿռ�
	���ԶѲ����Զ��ͷ��ڴ棬ռ��é�Ӳ���S
	ֻ���ֹ��ͷ� free(p) ��ʱ������ʱ���ε��ڴ��ַ��һ���ġ���Ϊ��һ����������ͷţ��ڶ��ν����ϴ��ڴ�ĵ�ַ���¸�ֵ
	*/
	heapTest();

	//�˴���ϵ�

	heapTest();

	//�˴���ϵ�
	system("pause");
	return 0;
}

int mainB() {
	/*
	b  ��ʾ�������е�һ������λ��bit��
	B  ��ʾ�ֽڣ�byte����һ���ֽ����� 8 �� bit ��ɵģ�1B = 8b
	kB ��ʾǧ�ֽڣ�kilobyte����1kB = 1024B

	int a = 1; //4���ֽ� 4B ռ���ڴ棺 4/1024 = 0.00390625

	���㣺http://www.elecfans.com/tools/zijiehuansuan.html

	�ڼ�������浥λ����С����B���ֽڣ���һ��Ӣ���ַ���Ҫռ��1���ֽڵĿռ䣬һ��������Ҫռ��2���ֽڵĿռ䣬
	�䵥λ֮��Ļ������£�
	1KB=1024B 
	1MB=1024KB 
	1GB=1024MB
	1TB=1024GB 

	���µ�λ�����ã����ٱ��ἰ
	1PB=1024TB 
	1EB=1024PB 
	1ZB=1024EB 
	1YB=1024ZB
	*/
	int abc = 1;
	printf("abc = %d\n", sizeof(abc)); //abc = 4
	
	unsigned long long ULL = 1024 * 1024 * 1024;  //ll   2^64-1  ����
	/*
	1GB=1024MB		1MB=1024KB		1KB=1024B		1B=8bit
	1G = 1024��1024��1024B= 1024��1024KB
	*/
	ULL *= 1; //1G�ڴ� //
	void *p = malloc(ULL);
	if (NULL == p) {
		printf("�ڴ����ʧ��\n");
	}
	else {
		printf("�ڴ����ɹ�\n"); //��windows��������Կ���ռ1G�ڴ� 1051372K
	}

	system("pause");
	return 0;
}

int mainC(){
	// �����ĳ��ڴ�
	while (1)
	{
		//�ڴ�һ��Ҫ��ʱ�ͷ�
		void *p = malloc(1024 * 1024 * 100);//p, ջ    *(p+3)��ַָ�������
		Sleep(3000);
		free(p);//�ͷ��ڴ�
		Sleep(3000);

	}
	system("pause");
	return 0;
}