#include <stdio.h>
#include <stdlib.h>
/*
�ؼ�������
ͨ��һ��������㣬�������ģ�����û�пɶ��ԣ���ԭ�ķ���ţ���༰������Ǽ��ܣ�
�����پ���һ��������㣬�ͻỹԭ��ԭ�ģ�����ǽ��ܵĹ��̣�
���ܺͽ�����Ҫ��ͬ����Կ�������Կ���ԣ����޷��ɹ����ܵġ�

����ļ����㷨��Ϊ�ԳƼ����㷨�����ܺͽ���ʹ��ͬһ����Կ��

������ܺͽ��ܵ���Կ��ͬ�����Ϊ�ǶԳƼ����㷨���ڷǶԳ��㷨�У����ܵ���Կ��Ϊ��Կ�����ܵ���Կ��Ϊ˽Կ��ֻ֪����Կ���޷����ܵģ�������֪��˽Կ��
*/
int main() {
	char plaintext = 'a'; // ����
	char secretkey = '!'; // ��Կ
	char ciphertext = plaintext ^ secretkey; // ����
	char decodetext = ciphertext ^ secretkey; // ���ܺ���ַ�
	char buffer[9];
	printf(" char ASCII\n");

	// itoa()����������ת��Ϊ�ַ����������趨ת��ʱ�Ľ��ƣ������� http://c.biancheng.net/cpp/html/792.html
	// ���ｫ�ַ���Ӧ��ascii��ת��Ϊ������

	printf(" plaintext %c %7s\n", plaintext, itoa(plaintext, buffer, 2));
	printf(" secretkey %c %7s\n", secretkey, itoa(secretkey, buffer, 2));
	printf("ciphertext %c %7s\n", ciphertext, itoa(ciphertext, buffer, 2));
	printf("decodetext %c %7s\n", decodetext, itoa(decodetext, buffer, 2));
	return 0;
}