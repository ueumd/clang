#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void arrfn()
{
	int arr[] = { 99, 15, 100, 888, 252 };
	int len = sizeof(arr) / sizeof(int); //sizeof(arr) ��������������ռ�õ��ֽ���
	int i = 0;
	for (i;i < len;i++) {
		printf("%d ,", *(arr + i));//99, 15, 100, 888, 252  arr�������׸���ַ
		/*
		arr ����������ָ������ĵ� 0 ��Ԫ�أ���ʾ�����׵�ַ�� arr+i ָ������ĵ� i ��Ԫ�أ�
		*(arr+i)�ȼ��� arr[i]��
		*/
	}
}

void stringArr()
{
	//�����ַ����鸳��ֵ�ķ���
	char cArr[] = { 'Q','U','A','N','X','U','E' };
	//�����ַ�������ֵ�ķ���
	char sArr[] = "quanxue";

	//��sizeof()�󳤶�
	printf("cArr�ĳ���=%d\n", sizeof(cArr));   //����Ϊ7
	printf("sArr�ĳ���=%d\n", sizeof(sArr));   //����Ϊ8�����һλ��NULL

											//��printf��%s��ӡ����
//	printf("cArr������=%s\n", cArr);   //������ȷ��ʾ
	printf("sArr������=%s\n", sArr);   //������ȷ��ʾ

									//��strlen()�󳤶�
	//printf("cArr�ĳ���=%d\n", strlen(cArr));   //����ȷ�Ľ��
	printf("sArr�ĳ���=%d\n", strlen(sArr));   //NULL���ڼ��㷶Χ

	/*
	char sArr[] = "quanxue";���ַ�ʽ������ʱ���Զ���ĩβ����һ��NULL�ַ���
	NULL�ַ�Ҳ����'\0'����ASCII�������ڵ�һ������16���Ʊ�ʾΪ0x00��
	sizeof()�����������ַ�����ĳ��ȣ��������ַ������ȡ�
	strlen()����������ַ������ȣ��������ַ����顣�����������ַ�����������͡�
	char sArr[] = "quanxue";Ҳ����д��char sArr[8] = "quanxue";��ע�⣺��8������7��
	*/
}

void stringfn()
{
	char str[] = "http://c.biancheng.net";
	int i = 0;
	int len = strlen(str);
	char *p = str; //str���ַ����׸���ַ

	//ֱ�����
	printf("%s\n", str);
	//�������
	for (i = 0;i < len;i++) {
		printf("%c", str[i]);
	}
	
	printf("\n");
	//ָ�뷽ʽ
	for (i = 0;i < len;i++) {
		printf("%c", *(p+i));
	}
	printf("\n");
	for (i = 0;i < len;i++) {
		printf("%c", *(str + i));
	}
	
}

//�����ַ����飬C���Ի�֧������һ�ֱ�ʾ�ַ����ķ���������ֱ��ʹ��һ��ָ��ָ���ַ���
void stringPointer()
{
	/*
		char cArr[] = { 'Q','U','A','N','X','U','E' };    //�����ַ����鸳��ֵ�ķ���

	    char sArr[] = "quanxue";						  //�����ַ�������ֵ�ķ���                 ջ��
		char *str = "http://c.biancheng.net";             //ָ��ָ���ַ��� �ַ�����һ�ֶ��巽ʽ     str��ջ�� ֵ�ڳ����� ֻ�ж�ȡȨ�ޣ�û��д��Ȩ��

		char *str;
		str = "http://c.biancheng.net";
		�ַ����е������ַ����ڴ������������еģ�str ָ������ַ����ĵ� 0 ���ַ���
		����ͨ������ 0 ���ַ��ĵ�ַ��Ϊ�ַ������׵�ַ��
		�ַ�����ÿ���ַ������Ͷ���char������ str ������Ҳ������char *��
	*/
	
	char *str = "http://c.biancheng.net";
	int len = strlen(str), i;

	printf("%s\n", str);

	//ʹ��*(str+i)
	for (i = 0; i<len; i++) {
		printf("%c", *(str + i));
	}

}

//�ַ����Ķ��巽ʽ
void defineString()
{
	char cArr[] = { 'Q','U','A','N','X','U','E' };   //�����ַ����鸳��ֵ�ķ���

	char sArr[] = "quanxue";					 //�����ַ�������ֵ�ķ���  ջ��   
	
	char *str = "http://c.biancheng.net";         //ָ��ָ���ַ���  �ַ�������     str��ջ�� ֵ�ڳ����� ֻ�ж�ȡȨ�ޣ�û��д��Ȩ��
	char *pstr = NULL;

	int a = 300;
	int *pint = NULL;

	str = "A"; //str ָ���˳����� ABCDEF�ĵ�ַ

	printf("%s\n", str); //ABCDEF
	printf("%d\n", a); //100

	pstr = str;
	printf("%s\n", pstr);//A
	printf(" str:%p\n", str); //:010E8CD8
	printf("pstr:%p\n", pstr);//:010E8CD8

	

	//pint = a;
	//printf("%d\n", pint);//300  �������� ��ַ�ǵĲ�һ����
	

	pint = &a;
	printf("%d\n", *pint);//300

	printf("   a:%p\n", &a);    //0x003bfbe0
	printf("pint:%p\n", pint);  //0x003bfbe0
}
void main()
{
	//arrfn();
	//stringfn();
	//stringArr();
	//stringPointer();
	defineString();
	printf("\n");
	system("pause");
}