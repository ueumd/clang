#include<stdio.h>
#include<stdlib.h>
//http://tool.oschina.net/commons?type=4  ���ö��ձ�

void main() {

	printf("\n-------------------�ַ�-------------------\n");
	/**
	�ַ� putchar  printf ��Ӧ�ĸ�ʽ���Ʒ���%c��
	*/
	int one = 1;
	char first = '1';
	char code = 'A';
	char b = 70;
	int c = 71;
	//char x = '��';  //char ���Ͳ��ܰ��� ASCII ����֮����ַ�
	putchar(one);
	putchar(first);
	putchar("\n");

	printf("%d\t %c\n", one, one);		// 1  	SOH %dASCII��ֵ1 %c ASCII������ַ�SOH  

	printf("%d\t %c\n", first, first);	// 49	1 %dASCII��ֵ49 %c ASCII������ַ�1 

	printf("%d\t %c\n", code, code);	// 65   A  %dASCII��ֵ65 %c ASCII������ַ�A   
	printf("%d\t %c\n", b, b);			// 70   F  %dASCII��ֵ65 %c ASCII������ַ�A   
	printf("%d\t %c\n", c, c);			// 71   G  %dASCII��ֵ65 %c ASCII������ַ�A   

	char p1, p2;
	p1 = 120;
	p2 = 121;
	printf("%c,%c\n", p1, p2);
	printf("%d,%d\n", p1, p2);



	printf("\n-------------------�ַ���-------------------\n");
	// �ַ���  puts ������ͨ�õ� printf ��Ӧ�ĸ�ʽ���Ʒ���%s��
	// ��C�����У��ַ���������'\0'��Ϊ���Ľ�������

	char web_url[] = "http://c.biancheng.net";
	char *web_name = "C����������";

	puts(web_url);							// http://c.biancheng.net
	puts(web_name);							//C����������
	printf("%s\n", web_url);    // http://c.biancheng.net
	printf("%s\n", web_name);   //C����������



	printf("\n-------------------�ַ�����-------------------\n");
	char arrCh[] = { 'A','B','1', '��' };
	for (int i = 0; i < 4; i++) {
		printf("i=%c\t", arrCh[i]); // i=A     i=B     i=1     i=?  '��'�Ǵ�ӡ�������� ASCII����ﲻ����
	}

	system("pause");
	return 0;
}