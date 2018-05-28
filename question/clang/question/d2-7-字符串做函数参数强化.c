#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//拷贝技术推演

void copystr()
{
	char a[] = "I am in Shanghai";
	char b[64];
	int i = 0;
	for (i = 0; *(a + i) != '\0'; i++) {
		*(b + i) = *(a + i);
	}

	//0没有拷贝到b中
	b[i] = '\0';
	printf("a:%s\n", a);
	printf("b:%s\n", b);
}

/*
	from和to 形参的值在不停的变化
	不断的修改from和to的指向
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
*操作 和++操作 ++优先级高
*/
void copystr22(char *from, char *to)
{
	for (; *from != '\0';) {
		*to++ = *from++;// *to=*from; from++;to++;
	}
	*to = '\0';
	return;
}

//不补0
void copystr23(char *from, char *to)
{
	while( (*to=*from)!='\0')
	{
		from ++;
		to ++;
	}
	return;
}

//再优化
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

//不轻易的改变形参的值 引入一个辅助变量，把形参给接过来...
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

	printf("原始值from:%s\n", from);
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
		//错误案例 正确要的分配内存
		char *myto = NULL; //向0的地址空间写入数据
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