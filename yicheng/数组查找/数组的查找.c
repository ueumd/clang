#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main1() {
	time_t  ts; //ʱ����������
	unsigned int num = time(&ts);
	srand(num); //��ʼ����������� �������ʼ��������ÿ�δ����Ķ���һ����
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

���ֲ��ҷ���ȱ��
���ֲ��ҷ���O(log n)������Ϊʮ�ָ�Ч���㷨����������ȱ��ȴҲ����ô���Եġ����������޶�֮�ϣ�

�����������Ǻ��ѱ�֤���ǵ����鶼������ġ���Ȼ�����ڹ��������ʱ��������򣬿������䵽�˵ڶ���ƿ���ϣ������������顣�����ȡЧ����O(1)���������Ĳ����ɾ��ĳ��Ԫ�ص�Ч��ȴ��O(n)��������¹������������ɵ�Ч�����顣

�����Щȱ��������õķ���Ӧ����ʹ�ö���������ˣ������Ȼ����ƽ�����������ˣ���Ч�ģ�O(n logn)����������Ԫ�ؼ��ϣ�������ͬ���ֲ��ҷ�һ�����٣�O(log n)������ѰĿ������

���ֲ����ֳ��۰���ң��ŵ��ǱȽϴ����٣������ٶȿ죬ƽ�����ܺã���ȱ����Ҫ������Ϊ������Ҳ���ɾ�����ѡ���ˣ��۰���ҷ��������ڲ������䶯������Ƶ���������б�...
*/
int main() {
	int a[1024];
	int len = sizeof(a) / sizeof(a[0]); // 1024
	for (int i = 0; i < len; i++) {
		a[i] = i;
	}
	printf("%p\n", a); //�����׵�ַ

	int num = 333; //��Ҫ���ҵ���
	int shang = 0;
	int xia = len - 1;
	int zhong;

	while (shang < xia) {
		zhong = (shang + xia) / 2;//ȡ�м�ֵ
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