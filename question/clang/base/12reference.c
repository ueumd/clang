#include <stdio.h>

// 引用
int main12 () {
    char    a = 1 ;
    short   b = 2;
    int     c = 3;
    long    d = 4;
    float   e = 1.2;
    double  f = 2.3;

    printf("&a = %p\n", &a);
    printf("&b = %p\n", &b);
    printf("&c = %p\n", &c);
    printf("&d = %p\n", &d);
    printf("&e = %p\n", &e);
    printf("&f = %p\n", &f);

//    &a = 0028FEBF
//    &b = 0028FEBC
//    &c = 0028FEB8
//    &d = 0028FEB4
//    &e = 0028FEB0
//    &f = 0028FEA8

    printf("a = %d\n", *(&a));
    printf("b = %d\n", *(&b));
    printf("c = %d\n", *(&c));
    printf("d = %d\n", *(&d));
    printf("e = %f\n", *(&e));
    printf("f = %f\n", *(&f));
//    a = 1
//    b = 2
//    c = 3
//    d = 4
//    e = 1.200000
//    f = 2.300000

    printf("a = %d\n", *((char *)0x0028FEBF));      // (char *)0x0028FEBF == &a
    printf("b = %d\n", *((short *)0x0028FEBC));
    printf("c = %d\n", *((int *)0x0028FEB8));
    printf("d = %d\n", *((long *)0x0028FEB4));
    printf("e = %f\n", *((float *)0x0028FEB0));    // 从这里可以看出 &e 进行取地址，取出来的地址是有类型的
    printf("f = %f\n", *((double *)0x0028FEA8));

//    a = 1
//    b = 2
//    c = 3
//    d = 4
//    e = 1.200000
//    f = 2.300000

    return 0;
}
