#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void myEncodeAnDecode(char prePath[], char resultPath[], int password) {
	FILE * normal_fp = fopen(prePath, "rb");
	FILE * encode_fp = fopen(resultPath, "wb");

	int ch;
	while ((ch = fgetc(normal_fp)) != EOF) {
		fputc(ch ^ password, encode_fp);
	}
	fclose(normal_fp);
	fclose(encode_fp);
}

int main() {
	char * oriPath = "D:\\picLibrary\\xiaoHuangTu.png";//原文件，加密后可删除掉，防止别人查看
	char * showOthersPath = "D:\\picLibrary\\xiaoHuangEncode.png";//存放加密的文件，给别人看，别人也看不了的文件
	char * newPath = "D:\\picLibrary\\xiaoHuangDecode.png";//将加密的文件解密出来的文件，可以自己偷偷的查看

																												 //加密
	myEncodeAnDecode(oriPath, showOthersPath, 100);//密码随便搞个100
																								 //解密
	myEncodeAnDecode(showOthersPath, newPath, 100);
	system("pause");
	return 0;
}