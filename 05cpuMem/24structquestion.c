#include <stdio.h>
#include <stdlib.h>
typedef struct STUDENT
{
    char *name;
    int age;
}STU;

void structQuestion(){
    STU stu;
    stu.age = 101;
    // strcpy(stu.name, "I Love U"); //name指针没有指向合法的地址

    char buf[1024] = "I Love U";
    stu.name = (char*)malloc(strlen(buf)+1);    //分配空间
    strcpy(stu.name, buf);                      //拷贝赋值

    printf("%d\t %s\n",stu.age, stu.name); //101      I Love U
}

void structQuestion2(){
    STU *ps = (STU*)malloc(sizeof(STU));
    ps->age = 100;
    ps->name=(char*)malloc(100);
    strcpy(ps->name, "I Love You Only You");
    printf("name = %s age=%d\n",ps->name, ps->age);  // name = I Love You Only You age=100
    free(ps);
}

int main24 () {
    structQuestion();
    structQuestion2();
    return 0;
}
