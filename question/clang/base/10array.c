#include <stdio.h>

#if 0
数组      一组相同类型的数据管理
结构体    一组不同类型的数据管理
#endif

int main10() {

    // 数组
    int arr[10] = {100};
#if 0

    printf("sizeof(arr) = %d  sizeof(int[10]=%d)", sizeof(arr), sizeof(int[10]));
    // sizeof(arr) = 40  sizeof(int[10]=40)

    for(int i= 0;i<=10; i++) {
        printf("arr[%d] = %d \n", i, arr[i]);
    }
#endif

    //初始化
    //int age = 1; 初始化赋值
    //age = 20;    赋值

    //int arr[10]; 初始化
    //arr[10] = {1,2,3,4,5,6} 错误的 arr[10]代表的是下标10侟储的元素  正解：arr[10] = 10

    //凡是构造类型，要么在初始化的时候初始化， 要么对集合中的每个元素单独实始化。定义以后，不可以再以初始化的方式实始化。

    //凡是基础数据类型，既可以在定义的时候初始化，也可以先定义后初始化。

    int myArr[5] ={100}; //初始化  myArr[0] = 100;
    for(int j=0 ;j<sizeof(myArr)/sizeof(int); j++)
    {
        printf("myArr[%d] = %d\n",j,myArr[j]);
    }

    myArr[2] = 300; // 赋值  ，赋值时不能用 myArr[2] =｛300｝

    // 结构体
    struct stu
    {
        int age;
        char name;
    } array;

    return 0;
}
