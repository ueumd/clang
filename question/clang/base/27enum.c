#include <stdio.h>

//#define MON 0
//#define TUE 1

// #define 同样可以实现，但是落后了

//整型常量 默认从0开始 后面依次加1
enum DAY
{
    MON, TUE,WED,THU,FRI,SAT,SUN
};

// C88中没有bool类型 c99中有
enum BOOLB
{
    false, true
};

int main27(void) {

    printf("day=%d",MON); // 0


    return 0;
}
