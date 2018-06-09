#include<iostream>
using namespace std;

//CPP编译的时候，从上往下，遇到不匹配
//类的声明，拓展作用域，只能创建指针或引用
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
	FangfangPoint *fang; //只能创建指针或引用
	HaihuaPoint() :x(10), y(20), z(250) {
		
	}

	//FangfangPoint转化为本类型
	HaihuaPoint(const FangfangPoint &fang):x(fang.a), y(fang.b), z(0) {
		
	}

	void operator = (const FangfangPoint &fang) {
		x = fang.a;
		y = fang.b;
		z = 0;
	}

	//本类型转化为FangfangPoint类型
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

	haihua2 = fang2; //赋值重载

	FangfangPoint fang3 = haihua2;
	fang3 = haihua1;

	cin.get();
}