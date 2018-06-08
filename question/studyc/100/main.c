#include<stdio.h>
#include<math.h>
int main1() {
	int i, j;
	// 控制行
	for (i = 1; i <= 9; i++) {
		// 控制列
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
利润(I)低于或等于10万元时，奖金可提10%；
利润高于10万元，低于20万元时，低于10万元的部分按10%提成，高于10万元的部分，可提成7.5%；
20万到40万之间时，高于20万元的部分，可提成5%；
40万到60万之间时高于40万元的部分，可提成3%；
60万到100万之间时，高于60万元的部分，可提成1.5%；
高于100万元时，超过100万元的部分按1%提成。
*/
	long int profit;
	// 
	int bonus1, bonus2, bonus4, bonus6, bonus10;
	int bonus;
	
	while (1)
	{
		printf("please input the profit:");
		scanf("%ld", &profit); // 长整型要用ld

		bonus1 = 100000 * 0.1;
		bonus2 = bonus1 + 100000 * 0.075;  //低于20W
		bonus4 = bonus2 + 200000 * 0.05;	 //低于40W
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
	一个整数，它加上100 后是一个完全平方数，再加上168 又是一个完全平方数，请问该数是多少？
	思路：先开方 再平方
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
输入某年某月某日，判断这一天是这一年的第几天？
1.分析问题：基本算法为之前月份的天数和加当前天，例如3月8日，需要用1,2月份的总天数加8。
但要考虑特殊情况，如果是闰年，那么2月不再是28天，而是29天，此时如果月份大于2，那么之前月份的天数和则应加1才对。
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

		//判断是否为闰年 四年一闰,百年不闰; 四百年再闰  
		leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? 1 : 0;

		//润年且月份大于2 加1天
		sum += leap == 1 && month > 2 ? 1 : 0; 
	/*	if (leap == 1 && month > 2) {
			sum = sum + 1;
		}*/

		printf("%d 号是 %d 年中的第 %d 天\n", day, year, sum);
	}

	system("pause");
	return 0;
}

int main5() {
	/*
	输入三个整数x, y, z，请把这三个数由小到大输出。
	*/
	int x, y, z, t;
	
	while (1) {
		printf("请输入三个整数：");
		scanf("%d%d%d", &x, &y, &z);  //第4题-是手工输入的

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
		printf("三个整数排序后: %d %d %d\n", x, y, z);
	}

	system("pause");
	return 0;
}

//兔子问题  
int main6()
/*
若有一只免子每个月生一只小免子，一个月后小免子也开始生产。起初只有一只免子，一个月后就有两只免子，二个月后有三只免子，三个月后有五只免子,
假如兔子都不死，问每个月的兔子总数为多少？

1.分析：问题的关键是建立数学模型，而每三个月生一对兔子可以转化为斐波那契问题。究竟是如何转化为斐波那契问题的呢？
兔子的规律为数列1,1,2,3,5,8,13,21....
*/
{
	long f1, f2;
	int i;
	f1 = f2 = 1;
	for (i = 1; i < 20; i++) {
		printf("%12d%12d", f1, f2);
		if (i % 2 == 0) printf("\n");//每行输出四个数  
		f1 = f1 + f2;   //给下一次的F1赋值  
		f2 = f1 + f2;   //给下一次的F2赋值  
	}

	system("pause");
	return 0;
}

//枚举
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