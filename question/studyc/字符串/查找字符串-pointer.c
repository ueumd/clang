#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
http://c.biancheng.net/cpp/u/string_h/
�����ַ���
�ַ������Ӻ��� strcat() 
	strcat(arrayName1, arrayName2);
	strcat() ���� arrayName2 ���ӵ� arrayName1 ���棬��ɾ��ԭ�� arrayName1 ���Ľ�����־'\0'��
	����ζ�ţ�arrayName1 �����㹻����Ҫ�ܹ�ͬʱ���� arrayName1 �� arrayName2�������Խ�磨������Χ����

strncat()���ڽ�n���ַ�׷�ӵ��ַ����Ľ�β����ԭ��Ϊ��
	char * strncat(char *dest, const char *src, size_t n);
	������˵����destΪĿ���ַ�����srcΪԴ�ַ�����nΪҪ׷�ӵ��ַ�����Ŀ
	strncat()������ַ���src�Ŀ�ͷ����n ���ַ���dest�ַ���β����destҪ���㹻�Ŀռ�������Ҫ�������ַ��������n�����ַ���src�ĳ��ȣ���ô����srcȫ��׷�ӵ�dest��β����
	strncat()�Ὣdest�ַ�������'\0'���ǵ����ַ�׷����ɺ���׷��'\0'��
 ������ֵ�������ַ���dest��

�ַ������ƺ��� strcpy() 
	strcpy(arrayName1, arrayName2);
	strcpy() ��� arrayName2 �е��ַ��������� arrayName1 �У��ַ���������־'\0'Ҳһͬ������
	arrayName2����ȫ����arrayName1

�ַ����ȽϺ��� strcmp()
	strcmp(arrayName1, arrayName2);
	�ַ�����û�д�С֮�֣�strcmp() �Ը����ַ���Ӧ�� ASCII ��ֵ���бȽϡ�
	strcmp() �������ַ����ĵ� 0 ���ַ���ʼ�Ƚϣ����������ȣ��ͼ����Ƚ���һ���ַ���ֱ��������ͬ���ַ������ߵ��ַ�����ĩβ��
	����ֵ��
	�� arrayName1 �� arrayName2 ��ͬ���򷵻�0��
	�� arrayName1 ���� arrayName2���򷵻ش��� 0 ��ֵ��
	�� arrayName1 С�� arrayName2���򷵻�С��0 ��ֵ��

strstr()�������������Ӵ����ַ������״γ��ֵ�λ�ã���ԭ��Ϊ��
	char *strstr( char *str, char * substr );
������˵����strΪҪ�������ַ�����substrΪҪ�������Ӵ���
������ֵ�������ַ���str�е�һ�γ����Ӵ�substr�ĵ�ַ�����û�м������Ӵ����򷵻�NULL��

�������ƣ� strrchr
������ԭ�ͣ�char *strrchr(char *str, char c);
	�������ܣ�����һ���ַ�c����һ���ַ���str��ĩ�γ��ֵ�λ�ã�Ҳ���Ǵ�str���Ҳ࿪ʼ�����ַ�c�״γ��ֵ�λ�ã��������ش��ַ����е����λ����һֱ���ַ��������������ַ���
	���δ���ҵ�ָ���ַ�����ô����������NULL��

atoi()����
https://blog.csdn.net/lanzhihui_10086/article/details/39995869
atoi():int atoi(const char *str );
���ܣ����ַ���ת������������
str��Ҫ����ת�����ַ���
����ֵ��ÿ���������� int ֵ����ֵ�ɽ������ַ���Ϊ���ֽ��������ɡ� ����������޷�ת��Ϊ�����͵�ֵ����atoi�ķ���ֵΪ 0��
˵��������һ���ַ�����ʶ��Ϊ����ʱ��������ֹͣ���������ַ�����
char cs[]="8848"
int num = atoi(cs); //��0��λ�ÿ�ʼ

char cs[]="e8848"
int num = atoi(cs+1); //��1��λ�ÿ�ʼ

strrev()�������ַ������ã���ԭ��Ϊ��
	char *strrev(char *str);
������˵����strΪҪ���õ��ַ�����
 strrev()��str��ָ���ַ������á�

������ֵ������ָ�����ú���ַ�����ָ�롣
 strrev()�����������ַ����������޸�ԭ���ַ����������ֻ�������ַ����飬�����������ַ���ָ��ָ����ַ�������Ϊ�ַ���ָ��ָ������ַ����������������ܱ��޸ġ�
 har str1[] = "abcxyz";
 char *ret1 = strrev(str1); //zyxcba

 �ڴ溯��
 memcpy()	�����ڴ�����(����\0)
 memmove()	�����ڴ����ݣ����Դ����ص����ڴ�飩
 memset()	���ڴ��ǰn���ֽ�����Ϊ�ض���ֵ
*/

void stringPointerd()
{
	char *str = "ABCDE";
	int len = strlen(str), i;

	printf("str[0] = %c \n", str[0]);
	printf("&str = %p \n", str);
	printf("str = %s \n", str);

	//ʹ��*(str+i)
	for (i = 0; i<len; i++) {
			printf("%c", *(str + i));
	}
}

/*
��ת�ַ��� abcdefg => gfedcba
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

// ��һ���ַ�����"abcd"�Ӵ����ֵĴ���
//1 do while
void findStrDoWhile()
{
	char *p = "123cabcdXYZabcdYUKabcd456789qqabcd";
	int ncount = 0;
	do
	{	/*
		strstr(str1,str2) ���������ж��ַ���str2�Ƿ���str1���Ӵ���
		����ǣ���ú�������str2��str1���״γ��ֵĵ�ַ�����򣬷���NULL��
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

//3 pointer �Ƽ�
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
		strstr(str1,str2) ���������ж��ַ���str2�Ƿ���str1���Ӵ���
		����ǣ���ú�������str2��str1���״γ��ֵĵ�ַ�����򣬷���NULL��
		*/
		p = strstr(p, sub);
		if (p != NULL)
		{
			tmpcount++;
			p = p + strlen(sub); //������sub�ĳ���
		}
		else
		{
			break;
		}
	} while (*p != "\0");

	//��Ӹ�ֵ��ָ����ڵ��������
	*count = tmpcount;
	return ret;
}

//4 const pointer �Ƽ�
size_t findStrConstPointer(const char * const str, char *ch) {
	/*
	ʹ�� const ���βμ������ƣ�
	str[1] = 's';     // ���������const ���� ���Ըı� ʵ�����ڴ�ռ������ �β�Ҳ��ı�
	str = "I Love C"; //������const˫������ strֻ�ܶ�
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
	int n = findStrConstPointer(str, ch); //����t���ֵĴ���
	printf("str = %s \t n = %d\n", str, n); //str = http://c.biancheng.net     n = 3
}

//Сдת��д
void toUperCase(char *p) {
	while (*p != '\0') {
		if ((*p) >= 'a' && (*p) <= 'z') { //�ж��Ƿ���Сд��ĸ
			*p = *p - 32; //Сдת��д
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

// ���ַ�������
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
	// pָ���ַ���ĩ��'\0'
	for (int i = 0; i < len; i++) {
		*p = c[i]; //��ֵ
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
���ַ������뵽ĳ��λ��
ԭ���ַ��� hello world hello cpp hello linux
����cpp,�ҵ�����cpp�������ִ�hello c
���� ƴ�� ����
*/

void inertChar() {
	char sourceStr[50]= "hello world hello cpp hello linux";
	char findStr[5] = "cpp";
	char insertStr[10] = "hello c ";

	char *p = strstr(sourceStr, findStr); //����ַ���
	if (NULL == p) {
		printf("û���ҵ�\n");
	}
	else {
		char tmpstr[30];
		strcpy(tmpstr, p+4);							//��p+4��ʼ���ַ���ȫ��������tmpstr�� ����4 cpp hello linux
		printf("tmpstr = %s\n", tmpstr);  // tmpstr = hello linux
		printf("�ҵ� %c  %p\n", *p, p);		// c  0035F816

		*(p + 4) = '\0'; //����������ַ�
		strcat(sourceStr, insertStr);
		strcat(sourceStr, tmpstr);
		printf("sourceStr = %s\n", sourceStr);

	}

}

//ɾ���ַ������ַ�
void removeChar() {
	char str[50] = "hello world hello cpp hello c hello linux";
	char ch = 'c';
	char lastStr[50] = { 0 };
	int i = 0; //����lastStr�±�

	char *p = str; //ָ��洢str�׵�ַ
	while (*p != '\0') {
		if (*p != ch) {
			lastStr[i] = *p; // ��ֵ
			i++;						 // �±���ǰ�ƶ�
		}
		else {
			
		}
		p++;							// ָ����ǰ�ƶ�
	}

	printf("lastStr=%s\n", lastStr);
}

void limitPassword() {
	char relaPassword[30] = "password"; //��ʵ����
	int limit = 0;
	for (; limit < 3; limit++) {
		char strInput[30];
		gets(strInput);
		if (strcmp(relaPassword, strInput) == 0) {
			printf("��ϲ������������ȷ��");
			break;
		}
		else {
			printf("�����������, �㻹��%d�λ���", 2-limit);
			if (limit == 2) {
				printf("�����������Σ���ʧ�ܣ��ʻ���������!");
				break;
			}
		}
	}
}

void scanfAndGets() {
	//scanf �Ὣ�ո� �س� ���� ��ҳ�� �Ʊ�� ������ֹ��������
	//gets �����ո� Ҳ�ᱣ�������Ʊ�� �س������ս�
}

void charInt() {
	printf("%d %c\n", 1, 1);			// 1  Ц��
	printf("%d %c\n", '1', '1');  // 49 1
	printf("%d\n", '1'-1);			  // 48
}

// memset����ʵ��
/*
char str[] ="ammana_babi";
mymemset(str,'z',strlen(str));
*/
void *mymemset(void *dst, int val, int count) {
	void *p = dst; //����һ���ַ�ָ��ɽ��ܿ�ָ��ĵ�ַ
	while (count--)
	{
		*(char *)dst = (char)val;
		dst = (char *)dst + 1;
	}
	return p;
}

//�ַ�������
void sortString() {
	//10�ַ�������Ϊ20�Ķ�ά�ַ������飬����ʱ��0
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

	// ð������
	for (int i = 0; i < 10 - 1; i++) { //��1����ʼ��ֻʣ��һ���Ͳ���Ҫ�ˣ����� i<10-1
		for (int j = i + 1; j < 10; j++) {
			if (strcmp(str[i], str[j])> 0) {
				char temp[30];
				// �����ַ����������ø�ֵ�� 
				strcpy(temp, str[i]);
				strcpy(str[i], str[j]);
				strcpy(str[j], temp); 
			}
		}
	}
	printf("\n-----------�����------------\n");
	for (int i = 0; i < 10; i++) {
		printf("%s ", str[i]);;
	}

	/*
	apple google IBM Intel micorsoft facebook oracle cicso hp amd
	-----------�����------------
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