#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main1()
{
	int size = 0;
	int len = 0;
	// buf��Ϊ�ַ������� Ӧ����5���ֽ� ��Ϊ�ַ���4���ֽ�
	char buf[] = "abcd";
	char buf3[100] = "ABCDEFG123"; //�Զ�����0
	
	len = strlen(buf);		 // 4
	size = sizeof(buf);    // 5

	printf("len  = %d\n", len);   // 4
	printf("size = %d\n", size);  // 5

	printf("buf:      %s\n", buf);  // buf:abcd
	printf("buf3:		  %s\n", buf3); // buf3:ABCDEFG123
	printf("buf3[88]: %d\n", buf3[88]); // buf3[88]:0
	system("pause");
	return;
}

void main()
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

	system("pause");
	return;
}