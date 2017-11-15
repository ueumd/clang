#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main1() {
	time_t  ts; //时间数据类型
	unsigned int num = time(&ts);
	srand(num); //初始化随机数种子 如果不初始化，下面每次创建的都是一样的
	int a[10];
	for (int i = 0; i < 10; i++) {
		a[i] = rand() % 10;
		printf("%d\n", a[i]);
	}

	for (int i = 0; i < 10; i++) {
		if (a[i] == 3) {
			printf("find");
			break;
		}
	}

	system("pause");
	return 0;
}
/**

二分查找法的缺陷
二分查找法的O(log n)让它成为十分高效的算法。不过它的缺陷却也是那么明显的。就在它的限定之上：

必须有序，我们很难保证我们的数组都是有序的。当然可以在构建数组的时候进行排序，可是又落到了第二个瓶颈上：它必须是数组。数组读取效率是O(1)，可是它的插入和删除某个元素的效率却是O(n)。因而导致构建有序数组变成低效的事情。

解决这些缺陷问题更好的方法应该是使用二叉查找树了，最好自然是自平衡二叉查找树了，高效的（O(n logn)）构建有序元素集合，又能如同二分查找法一样快速（O(log n)）的搜寻目标数。

二分查找又称折半查找，优点是比较次数少，查找速度快，平均性能好；其缺点是要求待查表为有序表，且插入删除困难。因此，折半查找方法适用于不经常变动而查找频繁的有序列表。...
*/
int main() {
	int a[1024];
	int len = sizeof(a) / sizeof(a[0]); // 1024
	for (int i = 0; i < len; i++) {
		a[i] = i;
	}
	printf("%p\n", a); //数组首地址

	int num = 333; //需要查找的数
	int shang = 0;
	int xia = len - 1;
	int zhong;

	while (shang < xia) {
		zhong = (shang + xia) / 2;//取中间值
		printf("shang=%d, xia =%d, zhong=%d\n", shang, xia, zhong);
		if (a[zhong] == num) {
			printf("finded\n");
			break;
		}
		else if (num>a[zhong]) {
			shang = zhong + 1;
		}
		else {
			xia = zhong - 1;
		}
	}

	system("pause");
	return 0;
}