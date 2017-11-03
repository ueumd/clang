#include <stdio.h>
#include <stdlib.h>
/*
怎么区别自定义的struct，所以要加类名
*/
// 自定义类 有名结构体 Desk
struct Desk // 类名
{
    float length;
    float width;
    float high;
    char mer;
    float price;
};
// 自定义类 有名结构体 Person
struct Person
{
    float high;
    int weight;
    char sex;
    int age;
    float score[4];
};
// 无名结构体City
struct
{
    char *name;
    char *areaCode;
} city; //定义了变量city

/**
 1 有名结构体一次定义 多处使用，会带来新的命名
 2 无名结构体 定义类型的同时定义变量， 无名结构体不引入新的类型

 这两种方式 用的是偏少一些 多的还是别名结构体
 */

// 别名结构体
typedef struct Student
{
    char name[100];
    char sex;
    int age;
}STU;

int main20 () {

    // 自定义的类型
    struct Desk d; // 定义了变量 d
    struct Person p; //定义了变量 p

    d.length = 10; //成员访问
    city.name = "ShangHai";

    printf("city.name = %s\n", city.name); //city.name = ShangHai

    STU s1;
    s1.age = 10;
    printf("s1.age=%d\n", s1.age);

    // 凡是基本类型 既可定义时初始化 也可以先定义 再赋值
    // 凡是构造类型 要么在定义时初始化， 不可以，先定义 再以初始化的方式初始化

    STU s2 ={"tom", 'x', 18}; //初始化 注意 构造类型只能在定义时就要初始化
    printf("s2.name=%s\n", s2.name); // s2.name=tom

    STU s3;
    strcpy(s3.name, "hello");
    // s3.name = "Hello"; name是数组的首地址 数组赋值需要下标才可以
    printf("s3.name=%s\n", s3.name); //s3.name=hello


    //以上都是成员式 下面演示指向式

    STU *ps = &s3; //指针初始化
    strcpy(ps->name, "World");
    ps->age = 20;
    printf("ps.name=%s\n", ps->name);
    printf("ps.age=%d\n", ps->age);
    return 0;
}
