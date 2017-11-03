#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int a[10];
};

struct BIRTHDAY
{
   int year;
   int month;
   int day;
};

typedef struct student
{
    int num;
    char name[30];
    int age;
    struct BIRTHDAY birth; //结构体中套用结构体
}STUDENT;

int main21 () {

    // 结构体数组赋值
    struct Array arr = {1,2,3,4,5,6,7,8,9,0};
    struct Array arr2 = arr;

    printf("arr.a[2]=%d \t", arr.a[2]); //arr.a[2]=3      arr2.a[2]=3
    printf("arr2.a[2]=%d \n", arr2.a[2]);


    STUDENT stu[4] = {
        {1001,"zs",10, {1997,10,1}},
        {1002,"ls",11, {1998,10,1}},
        {1003,"xw",12, {1999,10,1}},
        {1004,"ww",13, {2000,10,1}},
    };

    for(int i=0; i<sizeof(stu)/sizeof(stu[0]);i++) {
        printf("num:%d\t name:%s\t age:%d\t year:%d\n", stu[i].num, stu[i].name, stu[i].age, stu[i].birth.year);
    }

    return 0;


}
