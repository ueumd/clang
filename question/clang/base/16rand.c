#include <stdio.h>

int main16 () {
    // 随机
    srand(time(NULL));
    for(int i=0;i<10;i++) {
        printf("%d \t", rand()%100);
    }
    return 0;
}
