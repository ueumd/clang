int stringPointer()
{
	
	char str[] = "nodejs"; //存在常在量区 只读
	int i, len = strlen(str);

	printf("str=%s\n", str); //str=nodejs  %s输出字符串

	for (i = 0;i < len;i++) {
		printf("%c", str[i]);//nodejs %c输出一个字符
	}

	return 0;
}

int stringp()
{
	char ch[] = { 'n','o', 'd', 'e', 'j', 's' };//存储在全局数据区或栈区
	char str[] = "nodejs";

	int len = strlen(str); //6
	int chlength = sizeof(ch)/sizeof(char); //6
	str[1] = 'c';//ncdejs
	printf("%s---length:%d\n", str,len);
	printf("chlength:%d\n", chlength);

	//这种方式叫字符串常量
	char *pstr = "hello world!"; //存储在常在量区 只读
	//pstr[1] = 'c'; 错误的
	pstr = "I Love C";//正确的

	printf("%s\n", pstr); //I Love C
	return 0;

}

//指针函数
int *strlong(char *str1,char *str2)
{
	if (strlen(str1) > strlen(str2)) {
		return str1;
	}
	else {
		return str2;
	}
}