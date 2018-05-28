#include <stdio.h>

int main9() {
    char ch = 'a';
    int a = 1;
    int c= 1;
    int b = a++; //先使用后加加
    int x = ++c; //先加加再使用
    printf("b:%d\n", b); //1
    printf("a:%d\n", a); //2

    printf("c:%d\n", c); //1
    printf("x:%d\n", x); //2


    int y = 8, z =10;
    int w =  y+++z; // (y++) + z
    printf("w:%d\n", w); //18
    printf("y:%d\n", y); //9


    if(3==3==3) { // true == 3 false友情99·
        printf("XXXXXXX");
    } else {
        printf("ooooo");
    }
    return 0;
}
