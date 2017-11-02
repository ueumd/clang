#include <stdio.h>
//T *p 指针+1 加的是sizeof(T)的大小
int main14 () {
    int a = 0x10000;
    printf("a = %x a+1=%x\n", a, a+1); // a = 10000 a+1=10001

    int *p = (int *)0x10000;
    printf("p = %x p+1= %x\n", p, p+1);// p = 10000 p+1= 10004

    char *p1 = (char *)0x10000;
    printf("p1 = %x p1+1= %x\n", p1, p1+1);// p = 10000 p+1= 10001

    return 0;
}
