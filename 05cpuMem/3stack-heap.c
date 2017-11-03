#include <stdio.h>

int * getMemory() {
    /**
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
