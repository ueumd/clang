#include<iostream>
using namespace std;

//CPP�����ʱ�򣬴������£�������ƥ��
//�����������չ������ֻ�ܴ���ָ�������
class FangfangPoint;


class FangfangPoint {
public:
	int a;
	int b;
	//HaihuaPoint haihua;

	FangfangPoint(int x, int y) :a(x), b(y) {

	}
	/*FangfangPoint(const HaihuaPoint &haihu) :a(haihua.x), b(haihua.y) {

	}*/
};

class HaihuaPoint {
public:
	int x;
	int y;
	int z;
	FangfangPoint *fang; //ֻ�ܴ���ָ�������
	HaihuaPoint() :x(10), y(20), z(250) {
		
	}

	//FangfangPointת��Ϊ������
	HaihuaPoint(const FangfangPoint &fang):x(fang.a), y(fang.b), z(0) {
		
	}

	void operator = (const FangfangPoint &fang) {
		x = fang.a;
		y = fang.b;
		z = 0;
	}

	//������ת��ΪFangfangPoint����
	operator FangfangPoint() {
		FangfangPoint temp(x, y);
		return temp;
	}
};



void main() {

	FangfangPoint fang1(88, 66);
	FangfangPoint fang2(888, 666);

	HaihuaPoint haihua1(fang1);
	HaihuaPoint haihua2 = fang1;

	haihua2 = fang2; //��ֵ����

	FangfangPoint fang3 = haihua2;
	fang3 = haihua1;

	cin.get();
}