#include <stdio.h>

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
// 自定义类 有名结构体City
struct City
{
    char *name;
    char *areaCode;
} city; //初始化

int main () {

    // 自定义的类型
    struct Desk d; // 初始化
    struct Person p; //// 初始化

    d.length = 10; //成员访问
    city.name = "ShangHai";

    printf("city.name = %s", city.name); //city.name = ShangHai

    return 0;
}
