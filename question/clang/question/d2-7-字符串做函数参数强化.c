#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//������������

void copystr()
{
	char a[] = "I am in Shanghai";
	char b[64];
	int i = 0;
	for (i = 0; *(a + i) != '\0'; i++) {
		*(b + i) = *(a + i);
	}

	//0û�п�����b��
	b[i] = '\0';
	printf("a:%s\n", a);
	printf("b:%s\n", b);
}

/*
	from��to �βε�ֵ�ڲ�ͣ�ı仯
	���ϵ��޸�from��to��ָ��
*/
void copystr2(char *from, char *to)
{
	for (; *from != '\0'; from++, to++) {
		*to = *from;
	}
	*to = '\0';
	return;
}

/*
*���� ��++���� ++���ȼ���
*/
void copystr22(char *from, char *to)
{
	for (; *from != '\0';) {
		*to++ = *from++;// *to=*from; from++;to++;
	}
	*to = '\0';
	return;
}

//����0
void copystr23(char *from, char *to)
{
	while( (*to=*from)!='\0')
	{
		from ++;
		to ++;
	}
	return;
}

//���Ż�
void copystr24(char *from, char *to)
{
	while ((*to++ = *from++) != '\0')
	{
		
	}
	return;
}

void copystr25(char *from, char *to)
{
	while (*to++ = *from++)
	{

	}
	return;
}

int copystr26(char *from, char *to)
{
	//*(0)='a';
	if (from == NULL || to == NULL)
	{
		return -1;
	}
	while (*to++ = *from++)
	{

	}

	return 0;
}

//�����׵ĸı��βε�ֵ ����һ���������������βθ��ӹ���...
int copystr27(char *from, char *to)
{
	//*(0)='a';
	
	char *fromtmp = from;
	char *totmp = to;

	if (fromtmp == NULL || totmp == NULL)
	{
		return -1;
	}
	while (*totmp++ = *fromtmp++)
	{

	}

	printf("ԭʼֵfrom:%s\n", from);
	printf("fromtmp:%s\n", fromtmp);

	return 0;
}

void maind27()
{
	copystr();

	char *from = "abcd";
	char buf2[100];

	//copystr2(from,buf2);
	copystr27(from, buf2);
	printf("buf2:%s\n", buf2);

	{
		//������ ��ȷҪ�ķ����ڴ�
		char *myto = NULL; //��0�ĵ�ַ�ռ�д������
	//	copystr25(from, myto);
	}
	{
		int ret = 0;
		char *myto = NULL;
		//ret= copystr26(from, myto);
		if (ret != 0)
		{
			printf("");
		}
	}
	system("pause");
	return;
}