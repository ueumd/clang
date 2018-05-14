#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

/*
https://www.cnblogs.com/melons/p/5791874.html
函数原型：
size_t   fread(   void   *buffer,   size_t   size,   size_t   count,   FILE   *stream   )
buffer   是读取的数据存放的内存的指针（可以是数组，也可以是新开辟的空间，buffer就是一个索引）
size       是每次读取的字节数
count     是读取次数
strean   是要读取的文件的指针
例如   从文件fp里读取100个字节   可用以下语句

fread(buffer,100,1,fp)
fread(buffer,50,2,fp)
fread(buffer,1,100,fp)
**************************************************************************************
对读出的二进制流是不能用strlen()或者sizeof()求其长度和大小的。
**************************************************************************************
*/
int copyFile(char *fileRead, char *fileWrite);

void maincopyfile() {
	char fileRead[100];
	char fileWrite[100];

	printf("要复制的文件:");
	scanf("%s", fileRead);

	printf("将文件复制到:");
	scanf("%s", fileWrite);

	if (copyFile(fileRead, fileWrite)) {
		printf("恭喜你，文件复制成功！\n");
	}
	else {
		printf("文件复制失败");
	}

	/*
	要复制的文件：d://1.mp4
	将文件复制到：d://2.mp4
	恭喜你，文件复制成功！
	*/

	system("pause");

}

int copyFile(char *fileRead, char *fileWrite) {
	FILE *fpRead;
	FILE *fpWrite;

	int buferlen = 1024 * 4; // 缓冲区长度

	char *buffer = (char *)malloc(buferlen);// 开辟缓存

	int readCount;// 实际读取的字节数

	if ((fpRead = fopen(fileRead, "rb")) == NULL || (fpWrite = fopen(fileWrite, "wb")) == NULL) {
		printf("Cannot open file, press any key to exit!\n");
		getch();
		exit(1);
	}
	// 不断从fileRead读取内容，放在缓冲区，再将缓冲区的内容写入fileWrite
	while ((readCount = fread(buffer, 1, buferlen, fpRead)) > 0) {
		fwrite(buffer, readCount, 1, fpWrite);
	}

	free(buffer);
	fclose(fpRead);
	fclose(fpWrite);
	
	return 1;

}