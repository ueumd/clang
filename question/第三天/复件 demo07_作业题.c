#include "stdio.h"
#include "stdlib.h"
#include "string.h"


//一般情况下不要修改输入的内存块的值
int trimSpace_ok2(char *mybuf, char *outbuf)
{
	int count = 0;
	int i = 0, j = 0;

	char *p = mybuf;
	j = strlen(p) -1;

	while (isspace(p[i]) && p[i] != '\0')
	{
		i++;
	}

	while (isspace(p[j]) && j>0)
	{
		j--;
	}
	count = j-i +1;

	//
	printf("count:%d", count);
	//void *  __cdecl memcpy(void *, const void *, size_t);
	memcpy(outbuf, mybuf+i, count);
	outbuf[count] = '\0';
	return 0;
	//system("pause");
}

int getKeyByValude(char *keyvaluebuf /*in*/,  char *keybuf  /*in*/,  
	char *valuebuf /*in out*/, int * valuebuflen /*in out*/)

{
	int rv = 0;
	char tmp[2048*10];
	char *p = NULL;
	//1 在大字符串里面查找有么有关键字

	p = strstr(keyvaluebuf, keybuf);
	if (p==NULL)
	{
		return 0;
	}
	p = p + strlen(keybuf);

	//2 在查找=号

	p = strstr(keyvaluebuf, "=");
	if (p==NULL)
	{
		return 0;
	}
	p = p + 1;
	//3 去掉左右空格

	rv = trimSpace_ok2(p, tmp);
	if (rv != 0)
	{
		printf("func trimSpace_ok2() err:%d\n", rv);
		return rv;
	}

	strcpy(valuebuf, tmp);
	*valuebuflen = strlen(tmp);
	return 0;
}

void main()
{
	int rv = 0;
	char keyvaluebuf[] = "ORACLE_name  =  itcast     ";

	char *keybuf = "ORACLE_name";
	char valuebuf[1024]; 
	int valuebuflen = 0;
	 
	//调用函数，要先判断是否出错
	rv = getKeyByValude(keyvaluebuf, keybuf, valuebuf, &valuebuflen);
	if (rv != 0) 
	{
		printf("func getKeyByValude() err:%d", rv);
		return ;
	}
	printf("valuebuf:%s\n", valuebuf);
	printf("valuebuflen:%d\n", valuebuflen);

	system("pause");
}