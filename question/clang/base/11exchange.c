#include <stdio.h>
// 交换位置/
int main11() {
    int x =20;
    int y = 100;

    printf("x: %d,  y: %d\n", x, y);

    x = x^y;
    y = x^y;
    x = x^y;

    printf("x: %d,  y: %d\n", x, y);

    char city1 = 'sh';
    char city2 ='bj';

    printf("city1: %c  city2: %c", city1, city2);

    city1 = city1 ^ city2;
    city2 = city1 ^ city2;
    city1 = city1 ^ city2;

     printf("city1: %c  city2: %c", city1, city2);

    return  0;


}
