#include <stdio.h>

// 字符串在常量区
int main () {
    char *p = "hello world";

    printf("%s\n", p);

    printf("p = %p, \"hello world\"=%p\n", p, "hello world"); //p = 004053B0, "hello world"=004053B0

    //char name[100] = "china"; //用数组的形式修改定义的字符串值
    char name[] = "china"; // 这样会自动分配内存空间
    name[0] = 'C';

    printf("%c\n", name[0]);    //C
    printf("%c\n", "china"[0]); //c 常量区不会改变
    printf("%s\n", name);       //China

    return 0;
}
