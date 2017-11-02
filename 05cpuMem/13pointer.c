#include <stdio.h>
// pointer
int main13 () {
    char    a = 1;
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

//    &a = 0028FEBB
//    &b = 0028FEB8
//    &c = 0028FEB4
//    &d = 0028FEB0
//    &e = 0028FEAC
//    &f = 0028FEA0

    printf("a = %d\n", *((char *)   0x0028FEBB));      // (char *)0x0028FEBF == &a
    printf("b = %d\n", *((short *)  0x0028FEB8));
    printf("c = %d\n", *((int *)    0x0028FEB4));
    printf("d = %d\n", *((long *)   0x0028FEB0));
    printf("e = %f\n", *((float *)  0x0028FEAC));    // 从这里可以看出 &e 进行取地址，取出来的地址是有类型的
    printf("f = %f\n", *((double *) 0x0028FEA0));

    char    *pa;
    short   *pb;
    int     *pc;
    long    *pd;
    float   *pe;
    double  *pf;

    printf("sizeof(pa) = %d \n", sizeof(pa));
    printf("sizeof(pb) = %d \n", sizeof(pb));
    printf("sizeof(pc) = %d \n", sizeof(pc));
    printf("sizeof(pd) = %d \n", sizeof(pd));
    printf("sizeof(pe) = %d \n", sizeof(pe));
    printf("sizeof(pf) = %d \n", sizeof(pf));

//    指向/被指向/更改指向
//    我们通常进行口述形表达时，说谁指向了谁，就是一种描述指针的指向关系。指向
//    谁，即保存了谁的地址。

    pc = &c;    //指向
    printf("*pc = %d\n", *pc); // 1

    int y = 300;
    pc = &y;    //更改指向
    printf("*pc = %d, y = %d\n", *pc, y); // 300 300

    *pc = 500; //修改指针指向的地址上的值 即 y = 500
    printf("*pc = %d, y = %d\n", *pc, y); // 500 500

     //强转
     long long *z = (long long *)&y;
     printf("*z = %d, y = %d\n", *z, y); // 500 500
    return 0;

}
