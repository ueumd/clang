#include <stdio.h>
#include <stdlib.h>
/*
关键技术：
通过一次异或运算，生成密文，密文没有可读性，与原文风马牛不相及，这就是加密；
密文再经过一次异或运算，就会还原成原文，这就是解密的过程；
加密和解密需要相同的密钥，如果密钥不对，是无法成功解密的。

上面的加密算法称为对称加密算法，加密和解密使用同一个密钥。

如果加密和解密的密钥不同，则称为非对称加密算法。在非对称算法中，加密的密钥称为公钥，解密的密钥称为私钥，只知道公钥是无法解密的，还必须知道私钥。
*/
int main() {
	char plaintext = 'a'; // 明文
	char secretkey = '!'; // 密钥
	char ciphertext = plaintext ^ secretkey; // 密文
	char decodetext = ciphertext ^ secretkey; // 解密后的字符
	char buffer[9];
	printf(" char ASCII\n");

	// itoa()用来将数字转换为字符串，可以设定转换时的进制（基数） http://c.biancheng.net/cpp/html/792.html
	// 这里将字符对应的ascii码转换为二进制

	printf(" plaintext %c %7s\n", plaintext, itoa(plaintext, buffer, 2));
	printf(" secretkey %c %7s\n", secretkey, itoa(secretkey, buffer, 2));
	printf("ciphertext %c %7s\n", ciphertext, itoa(ciphertext, buffer, 2));
	printf("decodetext %c %7s\n", decodetext, itoa(decodetext, buffer, 2));
	return 0;
}