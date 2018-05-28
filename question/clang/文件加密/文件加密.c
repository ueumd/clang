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
	char * oriPath = "D:\\picLibrary\\xiaoHuangTu.png";//ԭ�ļ������ܺ��ɾ��������ֹ���˲鿴
	char * showOthersPath = "D:\\picLibrary\\xiaoHuangEncode.png";//��ż��ܵ��ļ��������˿�������Ҳ�����˵��ļ�
	char * newPath = "D:\\picLibrary\\xiaoHuangDecode.png";//�����ܵ��ļ����ܳ������ļ��������Լ�͵͵�Ĳ鿴

																												 //����
	myEncodeAnDecode(oriPath, showOthersPath, 100);//���������100
																								 //����
	myEncodeAnDecode(showOthersPath, newPath, 100);
	system("pause");
	return 0;
}