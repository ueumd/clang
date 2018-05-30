#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//12345  54321;
//12345= 10000+2000+300+40+5 =1*10^4 +2*10^3+3*10^2+4*10^1+5*10^0
//54321= 5*10^4+4*10^3+3*10^2+2*10^1+1

/*
getWei()
12345 求个数算法(5位)
12345/10 = 1234
 1234/10 = 123
  123/10 = 12
   12/10 = 1
    1/10 = 0

63456
63456/10 = 6345
 6345/10 = 634
  634/10 = 63
   63/10 = 6
    6/10 = 0
*/
int getWei(int num) {
	/*
		c:  1/10 = 0  c语言中会自动截取
		js: 1/10 = 0.1
	*/
	// printf("1/10=%d\n", 1 / 10); // 1/10=0

	int wei = 0;
	for (int inum = num; inum; inum /= 10) { //计算位数 终止条件是inum=0
		printf("%d\n", inum);//打印过程
		wei++;
	}
	return wei;
}

/*
10^2 = 10*10 = 100
*/
			
int get10(int n) {
	int res = 1;
	for (int i = 0; i < n; i++) {
		res *= 10;
	}
	return res;
}

int main() {

	int num;
	scanf("%d", &num);
	printf("num = %d\n", num);

	int wei = getWei(num);
	printf("wei=%d\n", wei);

	int result = 0;
	int inum = num;						// num = 12345    54321     123 321
	for (int i = 0; i < wei; i++) {
		int shu = inum % 10;			// 取出最小位 5
		inum /= 10;						// 递进去掉最后一个位 inum = 1234

		result += shu * get10(wei-1-i);  // 3*10^2

		printf("shu=%d,inum=%d，i=%d,wei-1-i=%d \n", shu, inum, i, wei - 1 - i);
	}

	printf("result=%d", result);

	system("pause");
	return 0;
}