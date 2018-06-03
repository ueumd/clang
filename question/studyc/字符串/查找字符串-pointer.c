#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
http://c.biancheng.net/cpp/u/string_h/
常用字符串
字符串连接函数 strcat() 
	strcat(arrayName1, arrayName2);
	strcat() 将把 arrayName2 连接到 arrayName1 后面，并删除原来 arrayName1 最后的结束标志'\0'。
	这意味着，arrayName1 必须足够长，要能够同时容纳 arrayName1 和 arrayName2，否则会越界（超出范围）。

strncat()用于将n个字符追加到字符串的结尾，其原型为：
	char * strncat(char *dest, const char *src, size_t n);
	【参数说明】dest为目标字符串，src为源字符串，n为要追加的字符的数目
	strncat()将会从字符串src的开头拷贝n 个字符到dest字符串尾部，dest要有足够的空间来容纳要拷贝的字符串。如果n大于字符串src的长度，那么仅将src全部追加到dest的尾部。
	strncat()会将dest字符串最后的'\0'覆盖掉，字符追加完成后，再追加'\0'。
 【返回值】返回字符串dest。

字符串复制函数 strcpy() 
	strcpy(arrayName1, arrayName2);
	strcpy() 会把 arrayName2 中的字符串拷贝到 arrayName1 中，字符串结束标志'\0'也一同拷贝。
	arrayName2会完全覆盖arrayName1

字符串比较函数 strcmp()
	strcmp(arrayName1, arrayName2);
	字符本身没有大小之分，strcmp() 以各个字符对应的 ASCII 码值进行比较。
	strcmp() 从两个字符串的第 0 个字符开始比较，如果它们相等，就继续比较下一个字符，直到遇见不同的字符，或者到字符串的末尾。
	返回值：
	若 arrayName1 和 arrayName2 相同，则返回0；
	若 arrayName1 大于 arrayName2，则返回大于 0 的值；
	若 arrayName1 小于 arrayName2，则返回小于0 的值。

strstr()函数用来检索子串在字符串中首次出现的位置，其原型为：
	char *strstr( char *str, char * substr );
【参数说明】str为要检索的字符串，substr为要检索的子串。
【返回值】返回字符串str中第一次出现子串substr的地址；如果没有检索到子串，则返回NULL。

函数名称： strrchr
　函数原型：char *strrchr(char *str, char c);
	函数功能：查找一个字符c在另一个字符串str中末次出现的位置（也就是从str的右侧开始查找字符c首次出现的位置），并返回从字符串中的这个位置起，一直到字符串结束的所有字符。
	如果未能找到指定字符，那么函数将返回NULL。

atoi()函数
https://blog.csdn.net/lanzhihui_10086/article/details/39995869
atoi():int atoi(const char *str );
功能：把字符串转换成整型数。
str：要进行转换的字符串
返回值：每个函数返回 int 值，此值由将输入字符作为数字解析而生成。 如果该输入无法转换为该类型的值，则atoi的返回值为 0。
说明：当第一个字符不能识别为数字时，函数将停止读入输入字符串。
char cs[]="8848"
int num = atoi(cs); //从0个位置开始

char cs[]="e8848"
int num = atoi(cs+1); //从1个位置开始

strrev()函数将字符串逆置，其原型为：
	char *strrev(char *str);
【参数说明】str为要逆置的字符串。
 strrev()将str所指的字符串逆置。

【返回值】返回指向逆置后的字符串的指针。
 strrev()不会生成新字符串，而是修改原有字符串。因此它只能逆置字符数组，而不能逆置字符串指针指向的字符串，因为字符串指针指向的是字符串常量，常量不能被修改。
 har str1[] = "abcxyz";
 char *ret1 = strrev(str1); //zyxcba

 内存函数
 memcpy()	复制内存内容(忽略\0)
 memmove()	复制内存内容（可以处理重叠的内存块）
 memset()	将内存的前n个字节设置为特定的值
*/

void stringPointerd()
{
	char *str = "ABCDE";
	int len = strlen(str), i;

	printf("str[0] = %c \n", str[0]);
	printf("&str = %p \n", str);
	printf("str = %s \n", str);

	//使用*(str+i)
	for (i = 0; i<len; i++) {
			printf("%c", *(str + i));
	}
}

/*
反转字符串 abcdefg => gfedcba
*/
void reversestr() {
	//char *str = "abcdefg";

	char str[] = "abcdefg";
	char tmp;
	int len = strlen(str);

	char *p1 = str;
	char *p2 = str + len - 1;

	printf("str:%d\n", str);
	printf("len:%d\n", len);

	printf("p1:%c\n", *p1);//a
	printf("p2:%c\n", *p2);//g

	printf("%d\n", p1);//3341360
	printf("%d\n", p2);//3341366

	while (p1 < p2)
	{
		tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;

		p1++;
		p2--;

	}

	printf("str:%s\n", str);//gfedcba

}

// 求一段字符串中"abcd"子串出现的次数
//1 do while
void findStrDoWhile()
{
	char *p = "123cabcdXYZabcdYUKabcd456789qqabcd";
	int ncount = 0;
	do
	{	/*
		strstr(str1,str2) 函数用于判断字符串str2是否是str1的子串。
		如果是，则该函数返回str2在str1中首次出现的地址；否则，返回NULL。
		*/
		p = strstr(p, "abcd");
		if (p != NULL)
		{
			ncount++;
			p = p + strlen("abcd");
		}
		else
		{
			break;
		}
	} while (*p != "\0");
	printf("ncound:%d\n", ncount);

}

//2 while
void findStrWhile()
{
	char *p = "123cabcdXYZabcdYUKabcd456789qqabcd";
	int ncount = 0;
	while (p = strstr(p, "abcd"))
	{
		ncount++;
		p = p + strlen("abcd");
		if (*p == '\0')
		{
			break;
		}
	}
	printf("ncound:%d\n", ncount);//4
}

//3 pointer 推荐
int findStrPointer(char *mystr, char *sub, int *count)
{
	char *p = mystr;
	int ret = 0;
	int tmpcount = 0;

	if (mystr == NULL || sub == NULL || count == NULL)
	{
		ret = -1;
		printf("func findStr2Pointer() err:%d\n", ret);
		return ret;
	}

	do
	{	/*
		strstr(str1,str2) 函数用于判断字符串str2是否是str1的子串。
		如果是，则该函数返回str2在str1中首次出现的地址；否则，返回NULL。
		*/
		p = strstr(p, sub);
		if (p != NULL)
		{
			tmpcount++;
			p = p + strlen(sub); //步长加sub的长度
		}
		else
		{
			break;
		}
	} while (*p != "\0");

	//间接赋值是指针存在的最大意义
	*count = tmpcount;
	return ret;
}

//4 const pointer 推荐
size_t findStrConstPointer(const char * const str, char *ch) {
	/*
	使用 const 对形参加以限制，
	str[1] = 's';     // 如果不加以const 修饰 可以改变 实参里内存空间的数据 形参也会改变
	str = "I Love C"; //加两个const双重限制 str只能读
	*/

	int i, n = 0, len = strlen(str);
	for (i = 0; i<len; i++) {
		if (str[i] == *ch) {
			n++;
		}
	}
	return n;
}

void testFindStrPointer() {
	char *p = "123cabcdXYZabcdYUKabcd456789qqabcd";
	char sub[] = "abcd";
	int count = 0;
	int ret = 0;
	ret= findStrPointer(p,sub,&count);
	if (ret != 0) {
		printf("func findStr2Pointer() err:%d", ret);
		return ret;
	}
	printf("count:%d\n", count);
}

void testFindStrConstPointer() {
	char str[] = "http://c.biancheng.net";
	char ch[] = "t";
	int n = findStrConstPointer(str, ch); //查找t出现的次数
	printf("str = %s \t n = %d\n", str, n); //str = http://c.biancheng.net     n = 3
}

//小写转大写
void toUperCase(char *p) {
	while (*p != '\0') {
		if ((*p) >= 'a' && (*p) <= 'z') { //判断是否是小写字母
			*p = *p - 32; //小写转大写
			//a 97 A65 97-65=32
		}
		p++;
	}
}

void toLowerCase(char *p) {
	while (*p != '\0') {
		if ((*p) >= 'A' && (*p) <= 'Z') {
			*p = *p + 32;
		}
		p++;
	}
}

// 求字符串长度
int myStrlen(char *p) {
	int length = 0;
	while (*p != '\0') {
		length++;
		p++;
	}
	return length;
}

// mystrncat
void mystrncat(char *bc, char *c, int len) {
	if (NULL == bc || NULL == c) {
		return;
	}
	char *p = bc;
	while (*p != '\0') {
		p++;
	}
	// p指向字符串末端'\0'
	for (int i = 0; i < len; i++) {
		*p = c[i]; //赋值
		p++;
	}

	/*
		char str[30] ="task";
		char str2[20]="list8848";
		mystrncat(str, str2, 4);
	*/
}


void testUperCaseAndLowerCase() {
	char str[30] = "calc";
	toUperCase(str);
	printf("str =%s\n", str);

	char str2[30] = "CALC";
	toLowerCase(str2);
	printf("str2 =%s\n", str2);
}

/*
将字符串插入到某个位置
原来字符串 hello world hello cpp hello linux
查找cpp,找到后在cpp后插入符字串hello c
检索 拼接 拷贝
*/

void inertChar() {
	char sourceStr[50]= "hello world hello cpp hello linux";
	char findStr[5] = "cpp";
	char insertStr[10] = "hello c ";

	char *p = strstr(sourceStr, findStr); //检查字符串
	if (NULL == p) {
		printf("没有找到\n");
	}
	else {
		char tmpstr[30];
		strcpy(tmpstr, p+4);							//从p+4开始的字符串全部拷贝到tmpstr， 不加4 cpp hello linux
		printf("tmpstr = %s\n", tmpstr);  // tmpstr = hello linux
		printf("找到 %c  %p\n", *p, p);		// c  0035F816

		*(p + 4) = '\0'; //放弃后面的字符
		strcat(sourceStr, insertStr);
		strcat(sourceStr, tmpstr);
		printf("sourceStr = %s\n", sourceStr);

	}

}

//删除字符串的字符
void removeChar() {
	char str[50] = "hello world hello cpp hello c hello linux";
	char ch = 'c';
	char lastStr[50] = { 0 };
	int i = 0; //保存lastStr下标

	char *p = str; //指针存储str首地址
	while (*p != '\0') {
		if (*p != ch) {
			lastStr[i] = *p; // 赋值
			i++;						 // 下标向前移动
		}
		else {
			
		}
		p++;							// 指针向前移动
	}

	printf("lastStr=%s\n", lastStr);
}

void limitPassword() {
	char relaPassword[30] = "password"; //真实密码
	int limit = 0;
	for (; limit < 3; limit++) {
		char strInput[30];
		gets(strInput);
		if (strcmp(relaPassword, strInput) == 0) {
			printf("恭喜你密码输入正确！");
			break;
		}
		else {
			printf("密码输入错误, 你还有%d次机会", 2-limit);
			if (limit == 2) {
				printf("密码输入三次，都失败，帐户将被锁定!");
				break;
			}
		}
	}
}

void scanfAndGets() {
	//scanf 会将空格 回车 换行 换页符 制表符 当作终止数据输入
	//gets 保留空格 也会保留其他制表符 回车当作终结
}

void charInt() {
	printf("%d %c\n", 1, 1);			// 1  笑脸
	printf("%d %c\n", '1', '1');  // 49 1
	printf("%d\n", '1'-1);			  // 48
}

// memset函数实现
/*
char str[] ="ammana_babi";
mymemset(str,'z',strlen(str));
*/
void *mymemset(void *dst, int val, int count) {
	void *p = dst; //创建一个字符指针可接受空指针的地址
	while (count--)
	{
		*(char *)dst = (char)val;
		dst = (char *)dst + 1;
	}
	return p;
}

//字符串排序
void sortString() {
	//10字符串长度为20的二维字符串数组，不足时补0
	char str[10][20] = {"apple","google","IBM","Intel", "micorsoft","facebook","oracle","cicso","hp","amd"};

	printf("%s\n", str[1]); //google

	/*
	a[0][0], a[0][1], a[0][2], a[0][3]
  a[1][0], a[1][1], a[1][2], a[1][3]
  a[2][0], a[2][1], a[2][2], a[2][3]
	*/
	int a[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10, 11, 12} };
	printf("%d\n", a[2][3]); //12


	for (int i = 0; i < 10; i++) {
		printf("%s ", str[i]);;
	}

	// 冒泡排序
	for (int i = 0; i < 10 - 1; i++) { //从1个开始，只剩下一个就不需要了，所以 i<10-1
		for (int j = i + 1; j < 10; j++) {
			if (strcmp(str[i], str[j])> 0) {
				char temp[30];
				// 交换字符串不可以用赋值号 
				strcpy(temp, str[i]);
				strcpy(str[i], str[j]);
				strcpy(str[j], temp); 
			}
		}
	}
	printf("\n-----------排序后------------\n");
	for (int i = 0; i < 10; i++) {
		printf("%s ", str[i]);;
	}

	/*
	apple google IBM Intel micorsoft facebook oracle cicso hp amd
	-----------排序后------------
	IBM Intel amd apple cicso facebook google hp micorsoft oracle

	*/
}

void main3333()
{
	
	 
	//findStrDoWhile();
	//findStrWhile();
	// testFindStrConstPointer();

	// testUperCaseAndLowerCase();

	//inertChar();
	// removeChar();
	//charInt();

	// limitPassword();

	sortString();

	system("pause");
	return;
}