#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void teststring()
{
	int  i = 0;
	char *p = NULL;
	char buf[100] = "ABCDE";
	printf("%p\n", buf);
	/*
	0x0041F708  41  A
	0x0041F709  42  B
	0x0041F70A  43  C
	0x0041F70B  44  D
	0x0041F70C  45  E
	0x0041F70D  00  .
	*/
	// �����±���ʽ
	for (i = 0; i < strlen(buf); i++) {
		//printf("buf[%d]=%d\n", i, buf[i]);
		/*
		buf[0]=65
		buf[1]=66
		buf[2]=67
		buf[3]=68
		buf[4]=69
		*/
		printf("buf[%d]=%c\n", i, buf[i]);
		/*
		buf[0]=A
		buf[1]=B
		buf[2]=C
		buf[3]=D
		buf[4]=E
		*/
	}

	// ָ��
	p = buf; // buf����������Ԫ�صĵ�ַ
	for (i = 0; i < strlen(buf); i++) {
		printf("buf[%d]=%c\n", i, *p++); // �����ǲ���+1
																		 /*
																		 buf[0]=A
																		 buf[1]=B
																		 buf[2]=C
																		 buf[3]=D
																		 buf[4]=E
																		 */
	}

	// [] *���Ƶ�����
	// buf[i] ===>buf[0+i] ===> *(buf+i)
}

int main�ַ��ַ����ַ���������() {
	//�������� sizeof
	int intArr[10] = { 0 };

	//�ַ����� sizeof
	char charArr[] = { 'A','B','C','D' };

	//�ַ������� strlen
	char strArr[7] = "ABCDEF"; 		//��Ϊ��'\0' 7����6  �Ƽ� char strArr[] = "ABCDEF"; 

																//�ַ������� strlen
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

	getchar();
	return 0;
}

