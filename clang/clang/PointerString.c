int stringPointer()
{
	
	char str[] = "nodejs"; //���ڳ������� ֻ��
	int i, len = strlen(str);

	printf("str=%s\n", str); //str=nodejs  %s����ַ���

	for (i = 0;i < len;i++) {
		printf("%c", str[i]);//nodejs %c���һ���ַ�
	}

	return 0;
}

int stringp()
{
	char ch[] = { 'n','o', 'd', 'e', 'j', 's' };//�洢��ȫ����������ջ��
	char str[] = "nodejs";

	int len = strlen(str); //6
	int chlength = sizeof(ch)/sizeof(char); //6
	str[1] = 'c';//ncdejs
	printf("%s---length:%d\n", str,len);
	printf("chlength:%d\n", chlength);

	//���ַ�ʽ���ַ�������
	char *pstr = "hello world!"; //�洢�ڳ������� ֻ��
	//pstr[1] = 'c'; �����
	pstr = "I Love C";//��ȷ��

	printf("%s\n", pstr); //I Love C
	return 0;

}

//ָ�뺯��
int *strlong(char *str1,char *str2)
{
	if (strlen(str1) > strlen(str2)) {
		return str1;
	}
	else {
		return str2;
	}
}