#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define RADIUS 100  // �궨�� ����


int main��()
{
	defineconst();
	varibale();
	operator();
	system("pause");

	return 0;
}

int defineconst()
{
	const int RADIUS2 = 100; //const ���峣��

	printf("%d\n", RADIUS);


	printf("%d\n", RADIUS2);

	// RADIUS2 = 200;const�����ǲ����޸ĵ�
	return 0;
}

/*
type variable_list
type variable_list=value

��������Ҫע�����¼����棺
1. �������������һ�������͡�
2. ��������ʱ���Ը���ֵ��Ҳ���Բ�����ֵ��
3. ������������ͬʱ���塣
4. ��ͬ���͵ı�����ֵʱ��С���͵ı�������ֱ�Ӹ�����ģ������͵ı�������С���͵ı���ʱ����ǿ��ת��

��������
1��һ������Ҫ�����洢�ռ�ġ����磺int a ��������ʱ����Ѿ������˴洢�ռ䡣
2����һ���ǲ���Ҫ�����洢�ռ�ģ�ͨ��ʹ��extern�ؼ�������������������������
���磺extern int a ���б��� a �����ڱ���ļ��ж���ġ�
������extern�ؼ��֣������Ǳ����Ķ��塣
*/
extern int a, b;
extern int c;
extern float f;
int varibale()
{
	/* �������� */
	int a, b;
	int c;
	float f;

	int rmb = 1000000000;

	/* ��ʼ�� */
	a = 10;
	b = 20;

	c = a + b;
	printf("value of c : %d \n", c);

	f = 70.0 / 3.0;
	printf("value of f : %f \n", f);

	printf("rmb=%d\n", rmb);
	return 0;

}

int operator()
{
	int rmb = 100;
	rmb++; //rmb=rmb+1 rmb+=1
	printf("rmb=%d\n", rmb); //101

	int rmb2 = 100;
	++rmb2;
	printf("rmb=%d\n", rmb2);//101

													 //��������һ����
	int a = 10, b = 20;

	int a2 = a++; //a++�ȼ�����ʽ��ֵ����++ a2=a ;a++
	int b2 = ++b;  //++b��++�ټ������ֵ	  b=b+1; b2=b;

	printf("a2=%d\n", a2); //10
	printf("b2=%d\n", b2); //21

	int i = 5;
	int i2 = i++ + ++i;  //i2=5 i++=6 ++i=7   5+7=12
	printf("i2=%d\n", i2); //12
	printf("i=%d\n", i);//7

											//���ű��ʽ���󶺺���ߵ�ֵ��Ȼ�������ұߵ�ֵ����������ֵ�Ƕ����ұߵ�ֵ
	int h = 1, l = 2, j = 3, k = 4;
	int h2 = (h + l, j + k); //7

	int h3 = (h = j, h + k);//7 h=3 k=4
	printf("h2=%d\n", h2);
	printf("h3=%d\n", h3);

	//����������ȼ�Precedence
	/*
	C99���ṩ��һ��ͷ�ļ� <stdbool.h> ������bool����_Bool
	true����1��false����
	*/
	bool isTrue = 100 == 100; //����100==100

	printf("isTrue=%d\n", isTrue);//1

	double f = (double)3 / 2; //(double)3 �Ƚ�����ǿ��ת��Ϊdouble�� �ٳ���2 
	printf("f=%f\n", f);//1.500000
	return 0;
}
