#include<stdio.h>
#include<math.h>
int main1() {
	int i, j;
	// ������
	for (i = 1; i <= 9; i++) {
		// ������
		for (j = 1; j <= i; j++) {
			printf("%d * %d = %-4d", j, i, i*j);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}

int main2() {
/*
����(I)���ڻ����10��Ԫʱ���������10%��
�������10��Ԫ������20��Ԫʱ������10��Ԫ�Ĳ��ְ�10%��ɣ�����10��Ԫ�Ĳ��֣������7.5%��
20��40��֮��ʱ������20��Ԫ�Ĳ��֣������5%��
40��60��֮��ʱ����40��Ԫ�Ĳ��֣������3%��
60��100��֮��ʱ������60��Ԫ�Ĳ��֣������1.5%��
����100��Ԫʱ������100��Ԫ�Ĳ��ְ�1%��ɡ�
*/
	long int profit;
	// 
	int bonus1, bonus2, bonus4, bonus6, bonus10;
	int bonus;
	
	while (1)
	{
		printf("please input the profit:");
		scanf("%ld", &profit); // ������Ҫ��ld

		bonus1 = 100000 * 0.1;
		bonus2 = bonus1 + 100000 * 0.075;  //����20W
		bonus4 = bonus2 + 200000 * 0.05;	 //����40W
		bonus6 = bonus4 + 200000 * 0.03;
		bonus10 = bonus6 + 400000 * 0.015;

		if (profit <= 100000) {
			bonus = profit * 0.1;
		}
		else if(profit <= 200000){
			bonus = bonus1 + (profit - 100000)* 0.075;
		} 
		else if (profit <= 400000) {
			bonus = bonus2 + (profit - 200000) * 0.05;
		}
		else if (profit <= 600000) {
			bonus = bonus4 + (profit - 400000) * 0.03;
		}
		else if(profit <=1000000) {
			bonus = bonus6 + (profit - 1000000) * 0.015;
		}
		else {
			bonus = bonus10 + (profit - 1000000) * 0.001;
		}

		printf("bonus is %d\n", bonus);
	}


	system("pause");
	return 0;
}

int main3() {
	/*
	һ��������������100 ����һ����ȫƽ�������ټ���168 ����һ����ȫƽ���������ʸ����Ƕ��٣�
	˼·���ȿ��� ��ƽ��
	*/
	long int i, x, y;

	for (i = 1; i < 100000; i++) {
		x = sqrt(i + 100);
		y = sqrt(i + 268);

		if (x*x == i + 100 && y*y == i + 268) {
			printf("%d\t", i); // 21 261 1581
		}
	}

	system("pause");
	return 0;
}

int main4() {
/*
����ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿
1.�������⣺�����㷨Ϊ֮ǰ�·ݵ������ͼӵ�ǰ�죬����3��8�գ���Ҫ��1,2�·ݵ���������8��
��Ҫ���������������������꣬��ô2�²�����28�죬����29�죬��ʱ����·ݴ���2����ô֮ǰ�·ݵ���������Ӧ��1�Ŷԡ�
*/

	int year, month, day;
	int leap;
	int sum;

	while (1) {
		printf("Please input the date(Like 1990-10-22)!\n");
		scanf("%d-%d-%d", &year, &month, &day);

		switch (month)
		{
		case 1:
			sum = 0;
			break;
		case 2:
			sum = 31;
			break;
		case 3:
			sum = 59;
			break;
		case 4:
			sum = 90;
			break;
		case 5:
			sum = 120;
			break;
		case 6:
			sum = 151;
			break;
		case 7:
			sum = 181;
			break;
		case 8:
			sum = 212;
			break;
		case 9:
			sum = 243;
			break;
		case 10:
			sum = 273;
			break;
		case 11:
			sum = 304;
			break;
		case 12:
			sum = 334;
			break;
		default:
			printf("data errer \n");
			return 0;
			break;
		}

		sum = sum + day;

		//�ж��Ƿ�Ϊ���� ����һ��,���겻��; �İ�������  
		leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? 1 : 0;

		//�������·ݴ���2 ��1��
		sum += leap == 1 && month > 2 ? 1 : 0; 
	/*	if (leap == 1 && month > 2) {
			sum = sum + 1;
		}*/

		printf("%d ���� %d ���еĵ� %d ��\n", day, year, sum);
	}

	system("pause");
	return 0;
}

int main5() {
	/*
	������������x, y, z���������������С���������
	*/
	int x, y, z, t;
	
	while (1) {
		printf("����������������");
		scanf("%d%d%d", &x, &y, &z);  //��4��-���ֹ������

		if (x > y) {
			t = x;
			x = y;
			y = t;
		}

		if (x > z) {
			t = x;
			x = z;
			z = t;
		}

		if (y > z) {
			t = y;
			y = z;
			z = t;
		}
		printf("�������������: %d %d %d\n", x, y, z);
	}

	system("pause");
	return 0;
}

//��������  
int main6()
/*
����һֻ����ÿ������һֻС���ӣ�һ���º�С����Ҳ��ʼ���������ֻ��һֻ���ӣ�һ���º������ֻ���ӣ������º�����ֻ���ӣ������º�����ֻ����,
�������Ӷ���������ÿ���µ���������Ϊ���٣�

1.����������Ĺؼ��ǽ�����ѧģ�ͣ���ÿ��������һ�����ӿ���ת��Ϊ쳲��������⡣���������ת��Ϊ쳲�����������أ�
���ӵĹ���Ϊ����1,1,2,3,5,8,13,21....
*/
{
	long f1, f2;
	int i;
	f1 = f2 = 1;
	for (i = 1; i < 20; i++) {
		printf("%12d%12d", f1, f2);
		if (i % 2 == 0) printf("\n");//ÿ������ĸ���  
		f1 = f1 + f2;   //����һ�ε�F1��ֵ  
		f2 = f1 + f2;   //����һ�ε�F2��ֵ  
	}

	system("pause");
	return 0;
}

//ö��
int main() {
	enum week{Mon = 1,Tues,Wed,Thurs,Fri,Sat,Sun} day;

	scanf("%d", &day);

	switch (day)
	{
	case Mon:
		puts("Monday");
		break;
	case Tues:
		puts("Tuesday");
		break;
	case Wed:
		puts("Wednesday");
		break;
	case Thurs:
		puts("Thursday");
		break;
	case Fri:
		puts("Friday");
		break;
	case Sat:
		puts("Saturday");
		break;
	case Sun:
		break;
		puts("Sunday");
	default:
		puts("error");
		break;
	}

	system("pause");
	return 0;

}