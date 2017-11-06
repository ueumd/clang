#include <stdio.h>

int * getMemory() {
    /**
    静态区 常量区的生命周期是跟mian函数一样的

    stack 空间是不可以返回的
    heap 空间可以返回的
    */

    int arr[3]={1,2,3};

    return &arr;
}

int main3() {

    int *p = getMemory();

    printf("%p",p);
}
